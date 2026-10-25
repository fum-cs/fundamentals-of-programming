# بخش هفتم : داده‌های ترکیبی و فایل

## مقدمه

تا اینجا هر آرایه‌ای که ساختیم فقط یک نوع داده نگه می‌داشت. اما یک دانشجو چند جور اطلاعات دارد: شماره‌ی دانشجویی (عدد صحیح)، نام (رشته) و نمره (عدد اعشاری). اگر برای این‌ها سه آرایه‌ی جدا بسازیم، هر کاری روی «یک دانشجو» باید هم‌زمان روی سه آرایه انجام شود. مرتب‌سازی مثال خوبی است: اگر فقط آرایه‌ی نمره‌ها را مرتب کنیم، نام‌ها و شماره‌ها سر جای خود می‌مانند و اطلاعات دانشجوها با هم قاطی می‌شود. ما به چیزی نیاز داریم که چند فیلد با نوع‌های مختلف را در یک بسته نگه دارد. این کار را **ساختار (struct)** انجام می‌دهد.

مشکل دوم این است که هر چه در برنامه نگه می‌داریم با پایان برنامه از بین می‌رود. برای اینکه داده‌ها بین دو اجرا بمانند باید آن‌ها را روی دیسک بنویسیم، یعنی در **فایل**. در فصل ۱۶ ساختارها و سه ابزار کنار آن‌ها (`typedef`، `union` و `enum`) را یاد می‌گیریم و در فصل ۱۷ یاد می‌گیریم چطور آن‌ها را در فایل ذخیره و دوباره بخوانیم. سناریوی **سیستم مدیریت نمرات دانشجویان** همچنان ادامه دارد.

#### نقشه کلی بخش:

```text
Parallel arrays problem → struct → typedef → pointer to struct (->) → array of struct
                              │
                              └──► union / enum
                              │
        FILE * → fopen / fclose → fprintf / fscanf (text) → fwrite / fread (binary)
                              │
                       save and load an array of structs
```

---

## فصل ۱۶ : Struct و Union

### 16.1 تعریف ساختار و دسترسی به فیلدها

**ساختار (struct)** یک نوع داده‌ی تازه است که چند فیلد با نوع‌های مختلف را زیر یک نام نگه می‌دارد. اول نوع را تعریف می‌کنیم، بعد از روی آن متغیر می‌سازیم و با عملگر نقطه (‎`.`‎) به هر فیلد می‌رسیم. فیلدهای یک متغیر در حافظه پشت‌سرهم قرار می‌گیرند. توجه کنید که خودِ تعریف ‎`struct Student`‎ فقط یک قالب است و حافظه نمی‌گیرد؛ حافظه با ساختن متغیر گرفته می‌شود.

```c
#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    double score;
};

int main(void)
{
    struct Student s;

    s.id = 4001;
    strcpy(s.name, "Sara");
    s.score = 18.5;

    printf("%d %s %.1f\n", s.id, s.name, s.score);
    return 0;
}
```

```text
4001 Sara 18.5
```

#### مقداردهی اولیه و کپی

ساختار را می‌توان هنگام تعریف با آکولاد و به ترتیب فیلدها مقداردهی کرد. برخلاف آرایه، ساختار با علامت ‎`=`‎ به‌طور کامل کپی می‌شود، حتی اگر داخلش آرایه‌ای مثل `name` باشد:

```c
#include <stdio.h>

struct Student {
    int id;
    char name[20];
    double score;
};

int main(void)
{
    struct Student a = {4001, "Sara", 18.5};
    struct Student b = a;

    b.score = 20;
    printf("a: %s %.1f\n", a.name, a.score);
    printf("b: %s %.1f\n", b.name, b.score);
    return 0;
}
```

```text
a: Sara 18.5
b: Sara 20.0
```

بعد از کپی، `a` و `b` دو متغیر مستقل‌اند و تغییر یکی روی دیگری اثر ندارد. دو ساختار را نمی‌توان با ‎`==`‎ مقایسه کرد؛ باید فیلدها را یکی‌یکی مقایسه کنیم.

#### اندازه‌ی ساختار

اندازه‌ی یک ساختار لزوماً برابر مجموع اندازه‌ی فیلدهایش نیست. کامپایلر بین فیلدها فضای خالی (padding) می‌گذارد تا هر فیلد روی آدرسی قرار بگیرد که پردازنده بتواند سریع بخواندش. در نتیجه ترتیب فیلدها روی اندازه اثر دارد:

```c
#include <stdio.h>

struct X { char a; int b; char c; };
struct Y { int b; char a; char c; };

int main(void)
{
    printf("sum of fields : %zu\n", sizeof(char) + sizeof(int) + sizeof(char));
    printf("struct X      : %zu\n", sizeof(struct X));
    printf("struct Y      : %zu\n", sizeof(struct Y));
    return 0;
}
```

خروجی (روی سیستم‌های رایج):

```text
sum of fields : 6
struct X      : 12
struct Y      : 8
```

هر دو ساختار فیلدهای یکسانی دارند، ولی در `X` بعد از هر `char` سه بایت خالی می‌ماند. معمولاً فیلدهای بزرگ‌تر را اول می‌نویسند تا فضای هدررفته کمتر شود.

### 16.2 کوتاه‌نویسی با typedef

نوشتن ‎`struct Student`‎ در هر جا طولانی است. دستور `typedef` برای یک نوع اسم تازه می‌سازد، و با آن می‌توان ساختار را بدون کلمه‌ی `struct` به کار برد:

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
    Student s = {4001, "Sara", 18.5};

    printf("%d %s %.1f\n", s.id, s.name, s.score);
    return 0;
}
```

```text
4001 Sara 18.5
```

کاربرد `typedef` فقط به ساختار محدود نیست؛ مثلاً ‎`typedef unsigned int uint;`‎ برای ‎`unsigned int`‎ یک اسم کوتاه می‌سازد. از این‌جا به بعد از نوع `Student` استفاده می‌کنیم.

### 16.3 اشاره‌گر به ساختار و ارسال آن به تابع

وقتی ساختار را به تابع می‌دهیم، مثل هر پارامتر دیگری **کپی** می‌شود. این کپی همه‌ی فیلدها را شامل می‌شود، از جمله آرایه‌ی `name`، پس هم هزینه دارد و هم تابع نمی‌تواند ساختار اصلی را تغییر دهد. راه‌حل همان است که در بخش قبل دیدیم: آدرس را می‌فرستیم. برای رسیدن به فیلدِ ساختاری که یک اشاره‌گر نشانش می‌دهد از عملگر پیکان (‎`->`‎) استفاده می‌کنیم؛ ‎`p->score`‎ یعنی ‎`(*p).score`‎. پرانتز لازم است، چون عملگر نقطه از ستاره اولویت بیشتری دارد و ‎`*p.score`‎ معنی دیگری دارد.

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

void bonus_copy(Student s)
{
    s.score += 1;
}

void bonus_ptr(Student *p)
{
    p->score += 1;
}

int main(void)
{
    Student a = {4001, "Sara", 18.5};

    bonus_copy(a);
    printf("after bonus_copy: %.1f\n", a.score);

    bonus_ptr(&a);
    printf("after bonus_ptr : %.1f\n", a.score);
    return 0;
}
```

```text
after bonus_copy: 18.5
after bonus_ptr : 19.5
```

اگر تابع فقط ساختار را می‌خواند، بهتر است پارامتر را ‎`const Student *p`‎ بنویسید تا هم از کپی جلوگیری شود و هم مشخص باشد که تابع آن را تغییر نمی‌دهد.

### 16.4 آرایه‌ای از ساختار

ساختار هم مثل هر نوع دیگری می‌تواند عنصر آرایه باشد. هر خانه‌ی آرایه یک دانشجوی کامل است و با ‎`cls[i].score`‎ به نمره‌ی او می‌رسیم. آدرس یک عنصر را هم با ‎`&cls[i]`‎ می‌گیریم، پس می‌توان اشاره‌گری نگه داشت که به «بهترین دانشجو» اشاره کند:

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
    Student cls[4] = {
        {4001, "Sara", 18.5},
        {4002, "Ali", 15},
        {4003, "Mina", 20},
        {4004, "Reza", 12.5}
    };
    double sum = 0;
    Student *best = &cls[0];

    for (int i = 0; i < 4; i++) {
        sum += cls[i].score;
        if (cls[i].score > best->score)
            best = &cls[i];
    }

    printf("average = %.2f\n", sum / 4);
    printf("best    = %s (%.1f)\n", best->name, best->score);
    return 0;
}
```

```text
average = 16.50
best    = Mina (20.0)
```

حالا مشکل مرتب‌سازی مقدمه حل می‌شود: چون ساختار با ‎`=`‎ کامل کپی می‌شود، جابه‌جایی دو دانشجو در مرتب‌سازی حباب‌ی فقط سه انتساب است و هیچ اطلاعاتی قاطی نمی‌شود. تابع `qsort` بخش قبل هم برای ساختارها کار می‌کند (تمرین ۳).

### 16.5 ذخیره‌ی مشترک با union

نوع `union` شبیه `struct` نوشته می‌شود، ولی همه‌ی اعضایش **یک حافظه‌ی مشترک** دارند و اندازه‌اش برابر بزرگ‌ترین عضو است. در هر لحظه فقط عضوی که آخر از همه در آن نوشته‌ایم مقدار معتبر دارد. این برای وقتی مفید است که یک مقدار می‌تواند چند نوع مختلف داشته باشد ولی هیچ‌وقت هم‌زمان بیش از یکی از آن‌ها لازم نیست.

```c
#include <stdio.h>

union Value {
    int i;
    float f;
};

int main(void)
{
    union Value v;

    v.f = 1.0f;
    printf("as float: %.1f\n", v.f);
    printf("as int  : 0x%08x\n", (unsigned int)v.i);
    printf("sizeof(union Value) = %zu\n", sizeof(union Value));
    return 0;
}
```

```text
as float: 1.0
as int  : 0x3f800000
sizeof(union Value) = 4
```

یک نکته‌ی جالب: عدد ‎`1.0`‎ در قالب استاندارد IEEE 754 با الگوی بیتیِ ‎`0x3f800000`‎ ذخیره می‌شود. وقتی همان چهار بایت را به‌عنوان `int` می‌خوانیم، همین الگو را می‌بینیم. خواندن عضوی غیر از آخرین عضو نوشته‌شده یعنی بازتفسیر بایت‌ها، و نتیجه به نمایش داده‌ها در آن سیستم بستگی دارد.

### 16.6 ثابت‌های نام‌دار با enum

دستور `enum` مجموعه‌ای از ثابت‌های صحیح با اسم می‌سازد. اگر مقداری ننویسیم، اولی صفر است و هر کدام یکی بیشتر از قبلی. کد با اسم‌هایی مثل `EXCELLENT` خواناتر از کدی است که عددهای جادویی ‎`0`‎ و ‎`1`‎ و ‎`2`‎ دارد، و `enum` با `switch` خوب جور است:

```c
#include <stdio.h>

enum Level { FAIL, PASS, EXCELLENT };

enum Level classify(double score)
{
    if (score >= 18)
        return EXCELLENT;
    if (score >= 10)
        return PASS;
    return FAIL;
}

int main(void)
{
    double scores[] = {18.5, 15, 7};

    for (int i = 0; i < 3; i++) {
        switch (classify(scores[i])) {
        case EXCELLENT: printf("%.1f: excellent\n", scores[i]); break;
        case PASS:      printf("%.1f: pass\n", scores[i]);      break;
        case FAIL:      printf("%.1f: fail\n", scores[i]);      break;
        }
    }
    printf("EXCELLENT = %d\n", EXCELLENT);
    return 0;
}
```

```text
18.5: excellent
15.0: pass
7.0: fail
EXCELLENT = 2
```

ثابت‌های `enum` در C از نوع `int` هستند و کامپایلر جلوی انتساب یک عدد دلخواه به متغیر `enum` را نمی‌گیرد؛ مراقب خودتان باشید.

:::{admonition} اختیاری: برای مطالعه‌ی بیشتر
:class: tip
اگر به این مباحث علاقه دارید، این‌ها را هم ببینید:

- ترکیب `enum` و `union` برای نگه‌داشتن «نوعِ مقدارِ فعلی» کنار خودِ مقدار (tagged union)
- مقداردهی با نام فیلد، مثل ‎`Student s = {.id = 1, .score = 20};`‎
- فیلدهای بیتی داخل ساختار، مثل ‎`unsigned flag : 1;`‎
- ماکروی `offsetof` در ‎`<stddef.h>`‎ که فاصله‌ی یک فیلد از ابتدای ساختار را می‌دهد
:::

### 16.7 تمرین

**تمرین ۱.** خروجی برنامه‌ی زیر را بدون اجرا پیش‌بینی کنید.

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
    Student a = {1, "Ali", 10};
    Student b = a;

    b.score = 20;
    a.id = 2;
    printf("%d %.0f %d %.0f\n", a.id, a.score, b.id, b.score);
    return 0;
}
```

:::{admonition} پاسخ
:class: dropdown
خروجی ‎`2 10 1 20`‎ است. بعد از ‎`Student b = a;`‎ دو ساختار مستقل داریم. تغییر ‎`b.score`‎ روی `a` اثر ندارد و تغییر ‎`a.id`‎ هم روی `b` اثر ندارد.
:::

**تمرین ۲.** تابع ‎`Student *find_by_id(Student *list, int n, int id)`‎ را بنویسید که اشاره‌گر به دانشجوی دارای شماره‌ی `id` را برگرداند و اگر چنین دانشجویی نبود، `NULL` برگرداند.

:::{admonition} پاسخ
:class: dropdown
```c
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

Student *find_by_id(Student *list, int n, int id)
{
    for (int i = 0; i < n; i++)
        if (list[i].id == id)
            return &list[i];
    return NULL;
}

int main(void)
{
    Student cls[3] = {{4001, "Sara", 18.5}, {4002, "Ali", 15}, {4003, "Mina", 20}};
    Student *s = find_by_id(cls, 3, 4002);

    if (s != NULL)
        printf("%s\n", s->name);
    else
        printf("not found\n");

    if (find_by_id(cls, 3, 9999) == NULL)
        printf("not found\n");
    return 0;
}
```

خروجی: `Ali` و بعد ‎`not found`‎. اگر نتیجه `NULL` باشد، نباید از ‎`->`‎ استفاده کرد.
:::

**تمرین ۳.** آرایه‌ای از دانشجوها را با `qsort` بر اساس نمره‌ی نزولی مرتب کنید.

:::{admonition} پاسخ
:class: dropdown
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int by_score_desc(const void *x, const void *y)
{
    const Student *a = x;
    const Student *b = y;
    return (a->score < b->score) - (a->score > b->score);
}

int main(void)
{
    Student cls[4] = {
        {4001, "Sara", 18.5}, {4002, "Ali", 15},
        {4003, "Mina", 20}, {4004, "Reza", 12.5}
    };

    qsort(cls, 4, sizeof(Student), by_score_desc);

    for (int i = 0; i < 4; i++)
        printf("%s %.1f\n", cls[i].name, cls[i].score);
    return 0;
}
```

تابع مقایسه آدرس عنصرها را به‌صورت ‎`const void *`‎ می‌گیرد و باید اول به ‎`const Student *`‎ تبدیل شود. عبارت ‎`(a->score < b->score) - (a->score > b->score)`‎ ترتیب نزولی می‌دهد.
:::

**تمرین ۴.** اندازه‌ی ‎`union U`‎ و ‎`struct S`‎ با فیلدهای یکسان ‎`char c; int n; double d;`‎ را پیش‌بینی کنید.

:::{admonition} پاسخ
:class: dropdown
```c
#include <stdio.h>

union U { char c; int n; double d; };
struct S { char c; int n; double d; };

int main(void)
{
    printf("union : %zu\n", sizeof(union U));
    printf("struct: %zu\n", sizeof(struct S));
    return 0;
}
```

خروجی (روی سیستم‌های رایج): ‎`union : 8`‎ و ‎`struct: 16`‎. در union همه‌ی اعضا یک حافظه‌ی مشترک دارند و اندازه برابر بزرگ‌ترین عضو (`double`) است. در struct هر سه فیلد جای جدا دارند: ۱ بایت برای `c`، ۳ بایت padding، ۴ بایت برای `n` و ۸ بایت برای `d`.
:::

---

## فصل ۱۷ : Files

### 17.1 فایل و اشاره‌گر ‎`FILE *`‎

حافظه‌ی برنامه با پایان اجرا پاک می‌شود. **فایل** دنباله‌ای از بایت‌هاست که با یک نام روی دیسک می‌ماند و بعد از پایان برنامه هم وجود دارد. در C برای کار با هر فایل از یک اشاره‌گر از نوع ‎`FILE *`‎ (تعریف‌شده در ‎`<stdio.h>`‎) استفاده می‌کنیم که تابع `fopen` برمی‌گرداند. لازم نیست درون `FILE` چه چیزی هست؛ فقط آن را به توابع فایل می‌دهیم. چون این یک اشاره‌گر است، قواعد فصل ۱۴ درباره‌ی `NULL` اینجا هم برقرار است. کار با فایل همیشه سه مرحله دارد:

```text
fopen  →  read / write (fprintf, fscanf, fwrite, fread)  →  fclose
```

یک نکته‌ی جالب: صفحه‌کلید و صفحه‌نمایش هم در C مثل فایل رفتار می‌کنند. `stdin`، `stdout` و `stderr` از نوع ‎`FILE *`‎ هستند، و ‎`printf("...")`‎ دقیقاً معادل ‎`fprintf(stdout, "...")`‎ است. برای پیام‌های خطا معمولاً از ‎`fprintf(stderr, ...)`‎ استفاده می‌کنند تا با خروجی عادی قاطی نشود.

### 17.2 باز کردن، نوشتن، خواندن و بستن

تابع ‎`fopen(path, mode)`‎ فایل را باز می‌کند و ‎`FILE *`‎ برمی‌گرداند، یا اگر نشد (فایل نیست، اجازه‌ی دسترسی نیست و غیره) `NULL`. پس نتیجه را همیشه بررسی کنید. برای نوشتن از `fprintf` استفاده می‌کنیم که مثل `printf` است با این تفاوت که آرگومان اولش فایل است. در پایان هم `fclose` را صدا می‌زنیم.

```c
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("scores.txt", "w");
    if (f == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    fprintf(f, "%d\n", 18);
    fprintf(f, "%d\n", 15);
    fprintf(f, "%d\n", 20);

    fclose(f);
    return 0;
}
```

فایل ‎`scores.txt`‎ در **پوشه‌ی جاری** همان لحظه‌ی اجرا ساخته می‌شود، نه لزوماً کنار فایل برنامه. حالا همان فایل را با `fscanf` می‌خوانیم. این تابع مثل `scanf` است و تعداد مقدارهایی را که توانسته بخواند برمی‌گرداند؛ در انتهای فایل چیزی برای خواندن نمی‌ماند و `EOF` برمی‌گرداند. برای همین شرط حلقه را ‎`== 1`‎ می‌نویسیم:

```c
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("scores.txt", "r");
    if (f == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    int x, count = 0, sum = 0;
    while (fscanf(f, "%d", &x) == 1) {
        printf("read: %d\n", x);
        sum += x;
        count++;
    }
    fclose(f);

    if (count > 0)
        printf("count = %d, average = %.2f\n", count, (double)sum / count);
    return 0;
}
```

```text
read: 18
read: 15
read: 20
count = 3, average = 17.67
```

برای عدد اعشاری از `double` در `fscanf` باید ‎`%lf`‎ بنویسید، در حالی که `fprintf` و `printf` با ‎`%f`‎ کار می‌کنند. همچنین `fclose` را فراموش نکنید: نوشتن‌ها اول در بافر نگه داشته می‌شوند و اگر برنامه بدون بستن فایل با خطا تمام شود، ممکن است بخشی از داده‌ها هرگز نوشته نشود.

### 17.3 حالت‌های باز کردن فایل

آرگومان دوم `fopen` مشخص می‌کند فایل برای چه کاری باز شود:

| حالت | کار | اگر فایل وجود نداشته باشد | محتوای قبلی |
|:--|:--|:--|:--|
| حالت `r` | خواندن | خطا (`NULL`) | سر جایش می‌ماند |
| حالت `w` | نوشتن | ساخته می‌شود | **پاک می‌شود** |
| حالت `a` | افزودن به انتها | ساخته می‌شود | سر جایش می‌ماند |

حرف `b` را می‌توان به همه‌ی این‌ها اضافه کرد (`rb`، `wb`، `ab`) تا فایل به‌صورت باینری باز شود. برنامه‌ی زیر با هر دو حالت `a` و `w` روی یک فایل کار می‌کند:

```c
#include <stdio.h>

int write_text(const char *mode, const char *text)
{
    FILE *f = fopen("names.txt", mode);
    if (f == NULL)
        return 0;
    fprintf(f, "%s", text);
    fclose(f);
    return 1;
}

void show(const char *title)
{
    char name[20];
    FILE *f = fopen("names.txt", "r");

    printf("%s:", title);
    while (f != NULL && fscanf(f, "%19s", name) == 1)
        printf(" %s", name);
    printf("\n");
    if (f != NULL)
        fclose(f);
}

int main(void)
{
    write_text("w", "Ali\nSara\nMina\n");
    show("created ");

    write_text("a", "Reza\n");
    show("after a ");

    write_text("w", "Neda\n");
    show("after w ");
    return 0;
}
```

```text
created : Ali Sara Mina
after a : Ali Sara Mina Reza
after w : Neda
```

:::{admonition} احتیاط با حالت w
:class: warning
حالت `w` همان لحظه‌ی `fopen` محتوای قبلی فایل را پاک می‌کند، حتی اگر بعدش چیزی ننویسید. برای اضافه کردن به یک فایل موجود (مثلاً یک فایل گزارش) از `a` استفاده کنید.
:::

### 17.4 فایل متنی و فایل باینری

داده‌ها را به دو شکل می‌توان در فایل نگه داشت. در **فایل متنی** هر مقدار به‌صورت نویسه نوشته می‌شود (مثلاً عدد ‎`18`‎ دو نویسه است)، پس با هر ویرایشگری خوانا است؛ با `fprintf` می‌نویسیم و با `fscanf` می‌خوانیم. در **فایل باینری** بایت‌ها دقیقاً همان‌طور که در حافظه هستند ذخیره می‌شوند؛ خوانا نیست ولی ساده و سریع است و اندازه‌ی هر رکورد ثابت است. برای آن از `fwrite` و `fread` استفاده می‌کنیم:

```text
fwrite(address, size_of_one_record, number_of_records, file)
fread (address, size_of_one_record, number_of_records, file)
```

هر دو تعداد رکوردهایی را که واقعاً منتقل شده برمی‌گردانند. آرگومان اول از نوع ‎`void *`‎ است (همان اشاره‌گر عمومی بخش قبل)، پس هر نوعی را می‌توان با آن نوشت. در مثال زیر سه دانشجو را در فایل باینری می‌نویسیم و دوباره می‌خوانیم:

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
    Student cls[3] = {
        {4001, "Sara", 18.5},
        {4002, "Ali", 15},
        {4003, "Mina", 20}
    };
    Student s;

    FILE *f = fopen("students.bin", "wb");
    if (f == NULL)
        return 1;
    fwrite(cls, sizeof(Student), 3, f);
    fclose(f);

    f = fopen("students.bin", "rb");
    if (f == NULL)
        return 1;
    while (fread(&s, sizeof(Student), 1, f) == 1)
        printf("%d %s %.1f\n", s.id, s.name, s.score);
    fclose(f);

    printf("sizeof(Student) = %zu\n", sizeof(Student));
    return 0;
}
```

```text
4001 Sara 18.5
4002 Ali 15.0
4003 Mina 20.0
sizeof(Student) = 32
```

اندازه‌ی این فایل سه برابر ‎`sizeof(Student)`‎ است، یعنی ۹۶ بایت. فایل باینری دو محدودیت مهم دارد. اول اینکه به شکل ساختار در حافظه بستگی دارد (padding، اندازه‌ی نوع‌ها و ترتیب بایت‌ها)، پس فایلی که یک برنامه روی یک سیستم نوشته ممکن است روی سیستم یا کامپایلر دیگر درست خوانده نشود. دوم اینکه هرگز ساختاری را که اشاره‌گر دارد با `fwrite` ذخیره نکنید: آدرس ذخیره‌شده در اجرای بعدی بی‌معنی است، چون آدرس‌ها هر بار فرق می‌کنند.

یک نکته‌ی جالب: در ویندوز، فایل متنی هنگام نوشتن هر ‎`\n`‎ را به ‎`\r\n`‎ تبدیل می‌کند و موقع خواندن برعکس. در فایل باینری هیچ تبدیلی انجام نمی‌شود. همین دلیل اصلی وجود حرف `b` در حالت‌هاست.

### 17.5 ذخیره و بازیابی ساختارها

حالا همه‌چیز را کنار هم می‌گذاریم: دو تابع می‌نویسیم که آرایه‌ای از `Student` را در فایل متنی ذخیره و از آن بخوانند. هر دانشجو یک خط است. این‌جا چند چیز از بخش‌های قبل دوباره دیده می‌شود: آرایه به تابع به‌صورت اشاره‌گر می‌رسد (Array Decay)، پس تعداد را جدا می‌فرستیم و پارامتر را `const` می‌گیریم؛ و در `fscanf` از ‎`%19s`‎ استفاده می‌کنیم تا اگر نام بلندتر از فیلد ‎`name[20]`‎ بود، حافظه‌ی اطراف خراب نشود.

```c
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int save_students(const char *path, const Student *list, int n)
{
    FILE *f = fopen(path, "w");
    if (f == NULL)
        return 0;
    for (int i = 0; i < n; i++)
        fprintf(f, "%d %s %.1f\n", list[i].id, list[i].name, list[i].score);
    fclose(f);
    return 1;
}

int load_students(const char *path, Student *list, int max)
{
    FILE *f = fopen(path, "r");
    if (f == NULL)
        return 0;

    int n = 0;
    while (n < max && fscanf(f, "%d %19s %lf",
                             &list[n].id, list[n].name, &list[n].score) == 3)
        n++;
    fclose(f);
    return n;
}

int main(void)
{
    Student cls[3] = {
        {4001, "Sara", 18.5},
        {4002, "Ali", 15},
        {4003, "Mina", 20}
    };
    Student loaded[10];

    if (!save_students("students.txt", cls, 3)) {
        printf("cannot save\n");
        return 1;
    }

    int n = load_students("students.txt", loaded, 10);
    printf("loaded %d students\n", n);
    for (int i = 0; i < n; i++)
        printf("%d %s %.1f\n", loaded[i].id, loaded[i].name, loaded[i].score);
    return 0;
}
```

```text
loaded 3 students
4001 Sara 18.5
4002 Ali 15.0
4003 Mina 20.0
```

محتوای فایل ‎`students.txt`‎ که این برنامه می‌سازد چنین است:

```text
4001 Sara 18.5
4002 Ali 15.0
4003 Mina 20.0
```

تابع `load_students` تعداد رکوردهای خوانده‌شده را برمی‌گرداند و حلقه‌اش وقتی تمام می‌شود که `fscanf` سه مقدار نخواند، چه به‌خاطر پایان فایل و چه به‌خاطر خط خراب. چون ‎`%s`‎ تا اولین فاصله می‌خواند، این روش برای نام‌هایی مثل «Sara Ahmadi» که فاصله دارند کار نمی‌کند.

:::{admonition} اختیاری: برای مطالعه‌ی بیشتر
:class: tip
اگر به کار با فایل علاقه دارید، این‌ها را هم ببینید:

- خواندن و نوشتن خط‌های دارای فاصله با `fgets` و `fputs`
- پرش مستقیم به یک رکورد دلخواه در فایل باینری با `fseek` و `ftell`
- چاپ دلیل دقیق شکست `fopen` با `perror`
- حذف و تغییر نام فایل با `remove` و `rename`
:::

### 17.6 تمرین

**تمرین ۱.** برنامه‌ای بنویسید که از فایل ‎`numbers.txt`‎ (با چند عدد صحیح، هر کدام در یک خط) بزرگ‌ترین عدد را پیدا و چاپ کند. اگر فایل باز نشد یا خالی بود، پیام مناسب بدهد.

:::{admonition} پاسخ
:class: dropdown
```c
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("numbers.txt", "r");
    if (f == NULL) {
        printf("cannot open numbers.txt\n");
        return 1;
    }

    int x, max;
    if (fscanf(f, "%d", &x) != 1) {
        printf("file is empty\n");
        fclose(f);
        return 1;
    }
    max = x;
    while (fscanf(f, "%d", &x) == 1)
        if (x > max)
            max = x;
    fclose(f);

    printf("max = %d\n", max);
    return 0;
}
```

برای فایلی با اعداد ‎`4 17 9 12`‎ خروجی ‎`max = 17`‎ است.
:::

**تمرین ۲.** در هر قطعه‌کد یک خطا وجود دارد. نوع خطا و اصلاحش را بگویید.

```c
/* snippet 1 */
FILE *f = fopen("data.txt", "r");
fscanf(f, "%d", &x);

/* snippet 2: adding a line to a log file */
FILE *f = fopen("log.txt", "w");
fprintf(f, "new entry\n");
fclose(f);

/* snippet 3 */
FILE *f = fopen("out.txt", "w");
fprintf(f, "%d\n", total);
return 0;

/* snippet 4 */
while (!feof(f)) {
    fscanf(f, "%d", &x);
    sum += x;
}
```

:::{admonition} پاسخ
:class: dropdown
- قطعه‌ی ۱، نبودن بررسی `NULL`: اگر ‎`data.txt`‎ وجود نداشته باشد، `f` برابر `NULL` است و `fscanf` برنامه را می‌اندازد. بعد از `fopen` باید ‎`if (f == NULL)`‎ را بررسی کرد.
- قطعه‌ی ۲، حالت اشتباه: `w` محتوای قبلی گزارش را پاک می‌کند. برای اضافه کردن باید `a` استفاده شود.
- قطعه‌ی ۳، نبودن `fclose`: در پایان عادی برنامه معمولاً فایل بسته می‌شود، ولی نباید به آن تکیه کرد. اگر برنامه کرش کند، داده‌ی داخل بافر گم می‌شود، و در برنامه‌ی طولانی تعداد فایل‌های باز زیاد می‌شود.
- قطعه‌ی ۴، حلقه‌ی `feof`: `feof` فقط بعد از اینکه یک خواندن شکست بخورد درست می‌شود. برای فایل با اعداد ‎`1 2 3`‎، آخرین `fscanf` شکست می‌خورد ولی `x` هنوز ۳ است و دوباره جمع می‌شود؛ حاصل ۹ می‌شود، نه ۶. راه درست ‎`while (fscanf(f, "%d", &x) == 1)`‎ است.
:::

**تمرین ۳.** برنامه‌ای بنویسید که دو دانشجو را در یک فایل باینری بنویسد، سپس با حالت `ab` یک دانشجوی سوم را به انتهای همان فایل اضافه کند و در پایان همه‌ی رکوردها و تعداد آن‌ها را چاپ کند.

:::{admonition} پاسخ
:class: dropdown
```c
#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
    Student cls[2] = {{4001, "Sara", 18.5}, {4002, "Ali", 15}};
    Student extra = {4005, "Neda", 17};
    Student s;

    FILE *f = fopen("cls.bin", "wb");
    fwrite(cls, sizeof(Student), 2, f);
    fclose(f);

    f = fopen("cls.bin", "ab");
    if (f == NULL)
        return 1;
    fwrite(&extra, sizeof(Student), 1, f);
    fclose(f);

    f = fopen("cls.bin", "rb");
    int n = 0;
    while (fread(&s, sizeof(Student), 1, f) == 1) {
        printf("%d %s %.1f\n", s.id, s.name, s.score);
        n++;
    }
    fclose(f);
    printf("records: %d\n", n);
    return 0;
}
```

حالت `ab` رکورد تازه را بعد از رکوردهای قبلی می‌نویسد و چیزی را پاک نمی‌کند.
:::

---

## جمع‌بندی بخش

این بخش دو مسئله را حل کرد: چطور چند داده‌ی ناهمگن را کنار هم نگه داریم (ساختار)، و چطور داده‌ها را از عمر یک اجرای برنامه فراتر ببریم (فایل). در پایان هر دو را به هم رساندیم: ذخیره و بازیابی آرایه‌ای از ساختارها.

### فصل ۱۶: ساختارها

- ساختار: چند فیلد با نوع‌های مختلف زیر یک نام. با ‎`.`‎ به فیلد می‌رسیم، با ‎`=`‎ کامل کپی می‌شود و اندازه‌اش ممکن است به‌خاطر padding از مجموع فیلدها بیشتر باشد.
- اسم تازه برای نوع: `typedef` برای یک نوع اسم تازه می‌سازد و نوشتن `struct` را حذف می‌کند.
- اشاره‌گر به ساختار: با ‎`p->score`‎ به فیلد می‌رسیم. ارسال آدرس از کپی شدن جلوگیری می‌کند و به تابع اجازه‌ی تغییر می‌دهد.
- آرایه‌ی ساختار: هر خانه یک ساختار کامل است، پس جابه‌جایی و مرتب‌سازی اطلاعات دانشجوها را قاطی نمی‌کند.
- مباحث تکمیلی: `union` حافظه را بین اعضایش مشترک می‌کند و `enum` ثابت‌های عددی نام‌دار می‌سازد.

### فصل ۱۷: فایل‌ها

- مراحل کار: `fopen`، خواندن یا نوشتن، `fclose`. نتیجه‌ی `fopen` را همیشه با `NULL` بسنجید.
- فایل متنی: `fprintf` و `fscanf`. شرط حلقه‌ی خواندن باید مقدار برگشتی `fscanf` را بسنجد، نه `feof`.
- حالت‌ها: `r` می‌خواند، `w` همه‌چیز را پاک می‌کند و از اول می‌نویسد، `a` به انتها اضافه می‌کند و `b` فایل را باینری می‌کند.
- فایل باینری: `fwrite` و `fread` رکوردها را با `sizeof` می‌نویسند و می‌خوانند. سریع‌اند ولی به سیستم وابسته‌اند و برای ساختار حاوی اشاره‌گر مناسب نیستند.
- ذخیره‌ی ساختارها: تابع‌های ذخیره و بازیابی با پارامتر اشاره‌گر، و ‎`%19s`‎ برای جلوگیری از سرریز.

### اشتباه‌های رایج

| اشتباه | چه می‌شود؟ | راه درست |
|:--|:--|:--|
| مقایسه‌ی دو ساختار با ‎`==`‎ | خطای کامپایل | مقایسه‌ی فیلد به فیلد |
| نوشتن ‎`*p.score`‎ به‌جای ‎`p->score`‎ | خطای کامپایل یا معنی اشتباه | نوشتن ‎`p->score`‎ یا ‎`(*p).score`‎ |
| فرستادن ساختار بزرگ به تابع به‌صورت کپی | کپی کامل در هر فراخوانی | فرستادن اشاره‌گر و `const` برای ورودی فقط‌خواندنی |
| نادیده‌گرفتن `NULL` بعد از `fopen` | کرش وقتی فایل وجود ندارد | بررسی نتیجه پیش از استفاده |
| باز کردن فایل با `w` برای اضافه کردن | محتوای قبلی پاک می‌شود | استفاده از `a` |
| فراموش‌کردن `fclose` | ممکن است داده‌ها نوشته نشوند | بستن فایل بعد از پایان کار |
| نوشتن ‎`while (!feof(f))`‎ | آخرین مقدار دو بار پردازش می‌شود | بررسی مقدار برگشتی `fscanf` یا `fread` |
| ذخیره‌ی ساختار حاوی اشاره‌گر با `fwrite` | آدرس ذخیره‌شده در اجرای بعدی بی‌معنی است | ذخیره‌ی خودِ داده‌ها، نه آدرس‌ها |

### بخش بعد

در بخش بعد دو موضوع تکمیلی را می‌بینیم: پیش‌پردازنده (‎`#define`‎، ماکرو و ‎`#ifdef`‎) و آرگومان‌های خط فرمان با ‎`int main(int argc, char *argv[])`‎. پارامتر `argv` همان آرایه‌ای از اشاره‌گرهاست که در بخش ششم دیدیم. با آن می‌توانیم نام فایل را موقع اجرا از کاربر بگیریم و دیگر لازم نباشد آن را داخل برنامه بنویسیم.
