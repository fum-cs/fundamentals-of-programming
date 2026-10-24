# بخش چهارم: توابع و بازگشت — تمارین

:::{admonition} راهنمای استفاده
:class: tip
تمرین‌ها به ترتیب سرفصل‌های درسنامه و در هر سرفصل تقریباً از آسان به سخت چیده شده‌اند. سطح دشواری با ستاره مشخص است: ★☆☆ آسان، ★★☆ متوسط، ★★★ چالشی.

زیر هر تمرین یک کادر **بستهٔ** «راهنمایی‌ها و پاسخ» هست که شامل **دو راهنمایی** و **پاسخ** است. پیشنهاد می‌کنیم اول خودتان تلاش کنید، بعد فقط راهنمایی ۱، بعد راهنمایی ۲، و در آخر پاسخ را باز کنید. تمرین‌هایی که به ‎`adt.h`‎ نیاز دارند، همان پرونده‌ای را استفاده می‌کنند که در مباحث تکمیلی (مبحث ۶) آمده است.

فهرست سرفصل‌ها: الف) تابع و محاسبه‌پذیری؛ ب) رویه، حافظه و Stack؛ ج) بازگشت پایه؛ د) درخت بازگشت و فیبوناچی؛ هـ) توان دودویی؛ و) حساب پئانو و آکرمان؛ ز) بازگشت و حلقه؛ ح) Stack، Queue، DFS و BFS؛ ط) ماکروها؛ ی) تمرین جامع.
:::

## الف) تابع و محاسبه‌پذیری

### تمرین ۱ ★☆☆ — یک تابع، دو الگوریتم

مجموع $n$ عدد فرد اول، یعنی $S(n) = 1 + 3 + 5 + \cdots + (2n - 1)$ را هم با یک حلقه و هم با یک فرمول (بدون حلقه) حساب کنید. نشان دهید این دو **یک تابع** را حساب می‌کنند ولی **دو الگوریتم** متفاوت‌اند، و بگویید زمان هر کدام از چه مرتبه‌ای است.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** چند مقدار اول را بنویسید: $S(1), S(2), S(3), S(4)$. چه الگویی می‌بینید؟

**راهنمایی ۲:** هر دو تابع را بنویسید و برای چند $n$ خروجی‌شان را کنار هم چاپ کنید.

**پاسخ:** $S(n) = n^2$. (مثلاً $1+3+5 = 9 = 3^2$؛ هر بار عدد فرد بعدی یک «L شکل» به مربع قبلی اضافه می‌کند.) نسخهٔ حلقه $O(n)$ و نسخهٔ فرمول $O(1)$ است، اما از بیرون تفاوتی نمی‌بینیم؛ همان جعبهٔ سیاه است.

```c
#include <stdio.h>

unsigned odd_sum_loop(unsigned n)
{
    unsigned s = 0;
    for (unsigned i = 1; i <= n; i++)
        s += 2 * i - 1;                 /* i-th odd number */
    return s;
}

unsigned odd_sum_formula(unsigned n)
{
    return n * n;
}

int main(void)
{
    unsigned tests[] = {1, 5, 10, 100};
    for (int i = 0; i < 4; i++)
        printf("n = %3u | loop = %5u | formula = %5u\n", tests[i], odd_sum_loop(tests[i]), odd_sum_formula(tests[i]));
    return 0;
}
```

خروجی:

```text
n =   1 | loop =     1 | formula =     1
n =   5 | loop =    25 | formula =    25
n =  10 | loop =   100 | formula =   100
n = 100 | loop = 10000 | formula = 10000
```

:::

### تمرین ۲ ★☆☆ — تابع هست یا نیست؟

برای هر مورد مشخص کنید آیا یک **تابع کامل**، یک **تابع جزئی** یا **اصلاً تابع نیست**. اگر لازم است دامنه را اصلاح کنید.

1. $f : \mathbb{R} \to \mathbb{R}$ با $f(x) = 1 / x$
2. رابطهٔ «$x$ مقسوم‌علیه $y$ است» روی $\mathbb{N} \times \mathbb{N}$ (جفت‌های $(x, y)$)، به‌عنوان نگاشت از $x$ به $y$
3. $g : \mathbb{N} \to \mathbb{N}$ با $g(n) = n - 1$
4. تابع ‎`int f(int n) { while (n != 0) n = n - 2; return n; }`‎ روی اعداد صحیح ریاضی (بدون سرریز)

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** برای هر مورد دو سؤال بپرسید: «آیا برای هر ورودی مجاز خروجی دارد؟» و «آیا برای هر ورودی **فقط یک** خروجی دارد؟»

**راهنمایی ۲:** در مورد ۴ ببینید حلقه به ازای چه $n$ هایی به $0$ می‌رسد.

**پاسخ:**

1. **جزئی** (در $x = 0$ تعریف نشده). با دامنهٔ $\mathbb{R} \setminus \{0\}$ کامل می‌شود.
2. **تابع نیست**: ورودی $x = 2$ خروجی‌های $2, 4, 6, \dots$ دارد (چند مقدار).
3. **جزئی** (در $n = 0$ جواب طبیعی ندارد). با دامنهٔ $\mathbb{N}_{>0}$ یا با «تفریق طبیعی» (Monus) که $g(0) = 0$ می‌دهد، کامل می‌شود؛ ولی در این صورت **تابع دیگری** است.
4. **جزئی**: فقط برای $n$ زوج و نامنفی متوقف می‌شود (خروجی ۰). برای $n$ فرد یا منفی هرگز تمام نمی‌شود، یعنی $f(n)\uparrow$.
:::

### تمرین ۳ ★★☆ — کولاتس، کدام ورودی طولانی‌تر است؟

برای دنبالهٔ کولاتس (مبحث تکمیلی ۲)، در بین $n = 1, \dots, 30$ مشخص کنید کدام $n$ بیشترین تعداد گام تا رسیدن به ۱ را دارد. برنامه بنویسید که این را بیابد (تابعی بنویسید که تعداد گام‌ها را برگرداند).

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** ابتدا تابع ‎`collatz_steps(n)`‎ بنویسید که با یک حلقهٔ ‎`while`‎ گام‌ها را بشمارد.

**راهنمایی ۲:** در ‎`main`‎ حلقه‌ای روی $n$ بنویسید و بیشینهٔ تا اینجا و ورودی متناظر را نگه دارید. مقادیر میانی می‌توانند بزرگ شوند، پس نوع ‎`unsigned long long`‎ بگیرید.

**پاسخ:**

```c
#include <stdio.h>

unsigned collatz_steps(unsigned long long n)
{
    unsigned steps = 0;
    while (n != 1) {
        n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
        steps++;
    }
    return steps;
}

int main(void)
{
    unsigned best_n = 1, best_steps = 0;
    for (unsigned n = 1; n <= 30; n++) {
        unsigned s = collatz_steps(n);
        if (s > best_steps) { best_steps = s; best_n = n; }
    }
    printf("longest for n <= 30: n = %u with %u steps\n", best_n, best_steps);
    return 0;
}
```

خروجی:

```text
longest for n <= 30: n = 27 with 111 steps
```

:::

## ب) رویه، حافظه و Stack

### تمرین ۴ ★☆☆ — قبل و بعد از فراخوانی

خروجی برنامهٔ زیر را **پیش از اجرا** پیش‌بینی کنید و توضیح دهید چرا اعداد دو بار و با ترتیب متفاوت چاپ می‌شوند.

```c
#include <stdio.h>

void f(int n)
{
    if (n == 0) return;
    printf("%d ", n);
    f(n - 1);
    printf("%d ", n);
}

int main(void)
{
    f(3);
    printf("\n");
    return 0;
}
```

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** فراخوانی‌ها را با یک Stack رسم کنید: ‎`f(3)`‎ ← ‎`f(2)`‎ ← ‎`f(1)`‎ ← ‎`f(0)`‎. هر ‎`printf`‎ اول قبل از فراخوانی و دومی بعد از بازگشت است.

**راهنمایی ۲:** وقتی ‎`f(0)`‎ برمی‌گردد، کدام Frame اول ادامه می‌دهد؟

**پاسخ:** خروجی ‎`3 2 1 1 2 3`‎ است. چاپ اول در مسیر **رفت** (push) انجام می‌شود، پس ۳، ۲، ۱ چاپ می‌شوند. چاپ دوم در مسیر **برگشت** (pop) است و چون Stack به صورت LIFO کار می‌کند، آخرین Frame (یعنی ‎`n = 1`‎) اول ادامه می‌دهد: ۱، ۲، ۳.

```c
#include <stdio.h>

void f(int n)
{
    if (n == 0) return;
    printf("%d ", n);
    f(n - 1);
    printf("%d ", n);
}

int main(void)
{
    f(3);
    printf("\n");
    return 0;
}
```

خروجی:

```text
3 2 1 1 2 3 
```

:::

### تمرین ۵ ★★☆ — شمارش Frame ها

برای هر مورد بنویسید «بیشینهٔ تعداد Frame‌های هم‌زمان روی Stack» و «تعداد کل فراخوانی‌ها» چند است؛ سپس با برنامه وارسی کنید:

1. ‎`fact(6)`‎ (فاکتوریل بازگشتی درسنامه)
2. ‎`fib(5)`‎ (نسخهٔ ساده)
3. ‎`power_fast(x, 16)`‎ (توان دودویی درسنامه)

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** بیشینهٔ Frame‌های هم‌زمان برابر طول بلندترین مسیر در درخت بازگشت (بر حسب **تعداد گره‌ها**) و تعداد کل فراخوانی‌ها برابر تعداد گره‌هاست.

**راهنمایی ۲:** برای ‎`power_fast(x, 16)`‎ آرگومان‌های $n$ را بنویسید: ۱۶، ۸، ۴، ۲، ۱، ۰.

**پاسخ:** (۱) هر دو ۶. (۲) بیشینهٔ Frame ها ۵ و تعداد کل فراخوانی‌ها ۱۵. (۳) هر دو ۶. دقت کنید که در ‎`fib(5)`‎ تعداد فراخوانی‌ها (۱۵) با بیشینهٔ Frame ها (۵) بسیار فرق دارد.

```c
#include <stdio.h>

static unsigned long calls, depth, max_depth;

static void enter(void) { calls++; depth++; if (depth > max_depth) max_depth = depth; }
static void leave(void) { depth--; }

unsigned long long fact(unsigned n)
{
    enter();
    unsigned long long r = n <= 1 ? 1ULL : n * fact(n - 1);
    leave();
    return r;
}

unsigned long fib(int n)
{
    enter();
    unsigned long r = n < 2 ? (unsigned long)n : fib(n - 1) + fib(n - 2);
    leave();
    return r;
}

unsigned long long power_fast(unsigned long long x, unsigned n)
{
    enter();
    unsigned long long r;
    if (n == 0) r = 1;
    else if (n % 2 == 0) { unsigned long long h = power_fast(x, n / 2); r = h * h; }
    else r = x * power_fast(x, n - 1);
    leave();
    return r;
}

#define REPORT(label, expr) \
    do { calls = depth = max_depth = 0; (void)(expr); \
         printf("%-18s calls = %2lu  max frames = %lu\n", label, calls, max_depth); } while (0)

int main(void)
{
    REPORT("fact(6)", fact(6));
    REPORT("fib(5)", fib(5));
    REPORT("power_fast(x, 16)", power_fast(2, 16));
    return 0;
}
```

خروجی:

```text
fact(6)            calls =  6  max frames = 6
fib(5)             calls = 15  max frames = 5
power_fast(x, 16)  calls =  6  max frames = 6
```

:::

### تمرین ۶ ★★☆ — هم‌نامی متغیرها

خروجی برنامهٔ زیر چیست؟ هر چاپ مربوط به کدام ‎`x`‎ است؟

```c
#include <stdio.h>

int x = 10;

void f(int x)
{
    x = x + 1;
    printf("%d ", x);
}

void g(void)
{
    x = x + 1;
    printf("%d ", x);
}

int main(void)
{
    f(x);
    f(x);
    g();
    g();
    printf("%d\n", x);
    return 0;
}
```

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** در ‎`f`‎، ‎`x`‎ پارامتر است: یک **کپی** در Frame خودش که متغیر سراسری را «پنهان» می‌کند.

**راهنمایی ۲:** ‎`g`‎ پارامتر ندارد، پس ‎`x`‎ در آن همان متغیر سراسری است که در ناحیهٔ Static زندگی می‌کند و فقط یک نسخه دارد.

**پاسخ:** خروجی ‎`11 11 11 12 12`‎. هر دو فراخوانی ‎`f(x)`‎ روی کپی محلی کار می‌کنند و سراسری ۱۰ می‌ماند (بنابراین هر بار ۱۱). ‎`g`‎ متغیر سراسری را واقعاً تغییر می‌دهد: ۱۱ و بعد ۱۲. این همان تفاوت «تابع با حافظهٔ خصوصی» و «رویه با حافظهٔ مشترک» است.

```c
#include <stdio.h>

int x = 10;

void f(int x)
{
    x = x + 1;
    printf("%d ", x);
}

void g(void)
{
    x = x + 1;
    printf("%d ", x);
}

int main(void)
{
    f(x);
    f(x);
    g();
    g();
    printf("%d\n", x);
    return 0;
}
```

خروجی:

```text
11 11 11 12 12
```

:::

## ج) بازگشت پایه

### تمرین ۷ ★☆☆ — مجموع ارقام

تابع بازگشتی ‎`digit_sum(n)`‎ بنویسید که مجموع ارقام عدد $n$ را بدهد (مثلاً ‎`digit_sum(12345)`‎ برابر ۱۵). حالت پایه و کمیتی که کوچک می‌شود را مشخص کنید. سپس با آن ‎`digital_root(n)`‎ را بنویسید: تا وقتی عدد تک‌رقمی نشده، مجموع ارقامش را بگیرید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** رقم آخر ‎`n % 10`‎ است و بقیهٔ ارقام همان ‎`n / 10`‎.

**راهنمایی ۲:** حالت پایه: ‎`n == 0`‎. برای ‎`digital_root`‎ شرط تک‌رقمی ‎`n < 10`‎ است.

**پاسخ:** $\text{digit\_sum}(n) = (n \bmod 10) + \text{digit\_sum}(\lfloor n/10 \rfloor)$ با حالت پایهٔ $\text{digit\_sum}(0) = 0$؛ هر فراخوانی عدد را حدود ده برابر کوچک می‌کند، پس عمق بازگشت برابر تعداد ارقام است.

```c
#include <stdio.h>

unsigned digit_sum(unsigned n)
{
    return n == 0 ? 0 : n % 10 + digit_sum(n / 10);
}

unsigned digital_root(unsigned n)
{
    return n < 10 ? n : digital_root(digit_sum(n));
}

int main(void)
{
    printf("digit_sum(12345)    = %u\n", digit_sum(12345));
    printf("digital_root(12345) = %u\n", digital_root(12345));
    printf("digital_root(9875)  = %u\n", digital_root(9875));
    return 0;
}
```

خروجی:

```text
digit_sum(12345)    = 15
digital_root(12345) = 6
digital_root(9875)  = 2
```

:::

### تمرین ۸ ★☆☆ — چاپ دودویی

تابع بازگشتی ‎`print_binary(n)`‎ بنویسید که نمایش دودویی $n$ را چاپ کند (مثلاً ۱۳ ← ‎`1101`‎). سپس بگویید اگر ترتیب «چاپ رقم» و «فراخوانی بازگشتی» عوض شود چه می‌شود.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** رقم آخر دودویی ‎`n % 2`‎ است و بقیه همان نمایش دودویی ‎`n / 2`‎. ولی ارقام باید از **چپ به راست** چاپ شوند.

**راهنمایی ۲:** آخرین رقم باید **بعد** از چاپ بقیه چاپ شود؛ پس چاپ بعد از فراخوانی بازگشتی است. (مقایسه کنید با تمرین ۴.)

**پاسخ:** اگر رقم را **قبل** از فراخوانی چاپ کنیم، ارقام از **راست به چپ** (برعکس) چاپ می‌شوند.

```c
#include <stdio.h>

void print_binary(unsigned n)
{
    if (n > 1) print_binary(n / 2);       /* higher digits first */
    printf("%u", n % 2);
}

void print_binary_reversed(unsigned n)
{
    printf("%u", n % 2);                  /* lowest digit first */
    if (n > 1) print_binary_reversed(n / 2);
}

int main(void)
{
    unsigned tests[] = {0, 13, 255};
    for (int i = 0; i < 3; i++) {
        printf("%3u -> ", tests[i]);
        print_binary(tests[i]);
        printf("   (reversed: ");
        print_binary_reversed(tests[i]);
        printf(")\n");
    }
    return 0;
}
```

خروجی:

```text
  0 -> 0   (reversed: 0)
 13 -> 1101   (reversed: 1011)
255 -> 11111111   (reversed: 11111111)
```

:::

### تمرین ۹ ★★☆ — باگ‌یابی

هر یک از سه تابع زیر مشکلی دارد. مشکل را پیدا کنید، بگویید با چه ورودی‌هایی ظاهر می‌شود و نسخهٔ درست را بنویسید. (تابع ‎`f2`‎ باید مجموع همهٔ اعداد هم‌پاریته با $n$ از $n$ تا ۱ یا ۰ را بدهد: مثلاً ‎`f2(5)`‎ برابر $5 + 3 + 1$.)

```c
int f1(int n)                 /* intended: n! */
{
    return n * f1(n - 1);
}

int f2(int n)                 /* intended: n + (n-2) + (n-4) + ... */
{
    if (n == 0) return 0;
    return n + f2(n - 2);
}

unsigned long long f3(unsigned long long x, unsigned n)    /* intended: x^n, fast */
{
    if (n == 0) return 1;
    if (n % 2 == 0) return f3(x, n / 2) * f3(x, n / 2);
    return x * f3(x, n - 1);
}
```

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** برای هر تابع این سه پرسش را بپرسید: حالت پایه دارد؟ کمیت واقعاً کاهش می‌یابد؟ هر فراخوانی چند بار خودش را صدا می‌زند؟

**راهنمایی ۲:** در ‎`f2`‎ ورودی‌های فرد را دنبال کنید: $5 \to 3 \to 1 \to -1 \to \cdots$

**پاسخ:**

- ‎`f1`‎: **حالت پایه ندارد**؛ فراخوانی‌ها تا Stack Overflow ادامه می‌یابند. اصلاح: ‎`if (n <= 1) return 1;`‎.
- ‎`f2`‎: حالت پایه ‎`n == 0`‎ برای $n$ فرد **هرگز** برقرار نمی‌شود ($5, 3, 1, -1, \dots$). اصلاح: ‎`if (n <= 0) return 0;`‎.
- ‎`f3`‎: نتیجه درست است ولی **سریع نیست**: در حالت زوج دو فراخوانی با همان ورودی داریم، پس درخت دوشاخه می‌شود و زمان $O(n)$ است. اصلاح: نتیجهٔ ‎`f3(x, n / 2)`‎ را یک بار در متغیر بگذارید و مربع کنید.

```c
#include <stdio.h>

int f1_fixed(int n)
{
    if (n <= 1) return 1;
    return n * f1_fixed(n - 1);
}

int f2_fixed(int n)
{
    if (n <= 0) return 0;
    return n + f2_fixed(n - 2);
}

unsigned long long f3_fixed(unsigned long long x, unsigned n)
{
    if (n == 0) return 1;
    if (n % 2 == 0) {
        unsigned long long half = f3_fixed(x, n / 2);      /* ONE call */
        return half * half;
    }
    return x * f3_fixed(x, n - 1);
}

int main(void)
{
    printf("f1_fixed(5) = %d\n", f1_fixed(5));
    printf("f2_fixed(5) = %d, f2_fixed(6) = %d\n", f2_fixed(5), f2_fixed(6));
    printf("f3_fixed(3, 13) = %llu\n", f3_fixed(3, 13));
    return 0;
}
```

خروجی:

```text
f1_fixed(5) = 120
f2_fixed(5) = 9, f2_fixed(6) = 12
f3_fixed(3, 13) = 1594323
```

:::

### تمرین ۱۰ ★★☆ — بازگشت دوطرفه

دو تابع ‎`is_even(n)`‎ و ‎`is_odd(n)`‎ برای اعداد طبیعی بنویسید که **فقط** از یکدیگر و کم کردن یک واحد استفاده کنند (بدون ‎`%`‎). درخت بازگشت ‎`is_even(4)`‎ را بکشید. چه مشکلی در ترتیب تعریف توابع در C پیش می‌آید و چگونه حل می‌شود؟

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** $0$ زوج است. و $n > 0$ زوج است اگر و فقط اگر $n - 1$ فرد باشد.

**راهنمایی ۲:** کامپایلر C هر نام را باید پیش از استفاده دیده باشد. ‎`is_even`‎ از ‎`is_odd`‎ استفاده می‌کند و برعکس، پس یکی را باید **از پیش اعلام** کرد (نوشتن فقط امضا همراه ‎`;`‎).

**پاسخ:** درخت یک زنجیر است که بین دو تابع جابه‌جا می‌شود: ‎`is_even(4) ← is_odd(3) ← is_even(2) ← is_odd(1) ← is_even(0)`‎. به این الگو **بازگشت دوطرفه (Mutual Recursion)** می‌گوییم. برای ترتیب تعریف، **اعلام پیش‌نمونه (Forward Declaration)** لازم است.

```c
#include <stdio.h>

int is_odd(unsigned n);                 /* forward declaration */

int is_even(unsigned n)
{
    return n == 0 ? 1 : is_odd(n - 1);
}

int is_odd(unsigned n)
{
    return n == 0 ? 0 : is_even(n - 1);
}

int main(void)
{
    printf("is_even(10) = %d\n", is_even(10));
    printf("is_odd(7)   = %d\n", is_odd(7));
    printf("is_even(7)  = %d\n", is_even(7));
    return 0;
}
```

خروجی:

```text
is_even(10) = 1
is_odd(7)   = 1
is_even(7)  = 0
```

:::

## د) درخت بازگشت و فیبوناچی

### تمرین ۱۱ ★☆☆ — درخت ‎`fib(5)`‎

درخت بازگشت ‎`fib(5)`‎ را بکشید. تعداد کل گره‌ها، تعداد برگ‌ها، ارتفاع و تعداد دفعاتی که ‎`fib(2)`‎ و ‎`fib(3)`‎ حساب می‌شوند را بنویسید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** ریشه ‎`fib(5)`‎ است با دو فرزند ‎`fib(4)`‎ و ‎`fib(3)`‎؛ هر گره با آرگومان کمتر از ۲ برگ است.

**راهنمایی ۲:** می‌توانید برای شمارش دفعات، برنامه‌ای بنویسید که با شرط ‎`if (n == 2) ...`‎ یک شمارنده را زیاد کند.

**پاسخ:** ۱۵ گره، ۸ برگ (۵ برگ ‎`fib(1)`‎ و ۳ برگ ‎`fib(0)`‎)، ارتفاع ۴ یال (۵ سطح). ‎`fib(3)`‎ دو بار و ‎`fib(2)`‎ سه بار حساب می‌شود؛ همین تکرار منشأ زمان نمایی است.

```c
#include <stdio.h>

static unsigned long calls, count2, count3;

int fib(int n)
{
    calls++;
    if (n == 2) count2++;
    if (n == 3) count3++;
    return n < 2 ? n : fib(n - 1) + fib(n - 2);
}

int main(void)
{
    fib(5);
    printf("calls = %lu, fib(2) computed %lu times, fib(3) computed %lu times\n", calls, count2, count3);
    return 0;
}
```

خروجی:

```text
calls = 15, fib(2) computed 3 times, fib(3) computed 2 times
```

:::

### تمرین ۱۲ ★★☆ — تعداد فراخوانی‌های فیبوناچی

اگر $T(n)$ تعداد فراخوانی‌های ‎`fib(n)`‎ باشد، ادعا می‌کنیم $T(n) = 2F(n+1) - 1$. ابتدا با برنامه برای $n = 0, \dots, 15$ وارسی کنید، سپس با استقرا ثابتش کنید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** از ساختار درخت: $T(0) = T(1) = 1$ و $T(n) = 1 + T(n-1) + T(n-2)$.

**راهنمایی ۲:** در گام استقرا فرض کنید ادعا برای $n-1$ و $n-2$ درست است و آن را در رابطهٔ بازگشتی بگذارید.

**پاسخ:** پایه: $T(0) = 1 = 2F(1) - 1$ و $T(1) = 1 = 2F(2) - 1$. گام برای $n \ge 2$:

$$T(n) = 1 + \big(2F(n) - 1\big) + \big(2F(n-1) - 1\big) = 2\big(F(n) + F(n-1)\big) - 1 = 2F(n+1) - 1$$

```c
#include <stdio.h>

static unsigned long calls;

unsigned long fib(int n)
{
    calls++;
    return n < 2 ? (unsigned long)n : fib(n - 1) + fib(n - 2);
}

unsigned long fib_iter(int n)
{
    unsigned long a = 0, b = 1;
    for (int i = 0; i < n; i++) { unsigned long t = a + b; a = b; b = t; }
    return a;
}

int main(void)
{
    int mismatches = 0;
    for (int n = 0; n <= 15; n++) {
        calls = 0;
        fib(n);
        unsigned long predicted = 2 * fib_iter(n + 1) - 1;
        printf("n = %2d  calls = %5lu  2F(n+1)-1 = %5lu\n", n, calls, predicted);
        if (calls != predicted) mismatches++;
    }
    printf("mismatches: %d\n", mismatches);
    return 0;
}
```

خروجی:

```text
n =  0  calls =     1  2F(n+1)-1 =     1
n =  1  calls =     1  2F(n+1)-1 =     1
n =  2  calls =     3  2F(n+1)-1 =     3
n =  3  calls =     5  2F(n+1)-1 =     5
n =  4  calls =     9  2F(n+1)-1 =     9
n =  5  calls =    15  2F(n+1)-1 =    15
n =  6  calls =    25  2F(n+1)-1 =    25
n =  7  calls =    41  2F(n+1)-1 =    41
n =  8  calls =    67  2F(n+1)-1 =    67
n =  9  calls =   109  2F(n+1)-1 =   109
n = 10  calls =   177  2F(n+1)-1 =   177
n = 11  calls =   287  2F(n+1)-1 =   287
n = 12  calls =   465  2F(n+1)-1 =   465
n = 13  calls =   753  2F(n+1)-1 =   753
n = 14  calls =  1219  2F(n+1)-1 =  1219
n = 15  calls =  1973  2F(n+1)-1 =  1973
mismatches: 0
```

:::

### تمرین ۱۳ ★★☆ — بالا رفتن از پله‌ها

به چند طریق می‌توان از $n$ پله بالا رفت اگر هر بار ۱ یا ۲ پله بالا برویم؟ و اگر ۱ یا ۲ یا ۳ پله؟ دو تابع بازگشتی بنویسید، تعداد فراخوانی‌ها را برای $n = 25$ اندازه بگیرید، و برای حالت سه‌گامی یک نسخهٔ حلقه‌ای با زمان خطی بنویسید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** آخرین گام یا ۱ پله بوده یا ۲ پله (یا ۳). پس ‎`ways(n)`‎ از جمع ‎`ways`‎ روی پله‌های قبلی ساخته می‌شود. حالت‌های پایه: ‎`ways(0) = 1`‎ (یک راه: هیچ کاری نکن).

**راهنمایی ۲:** نسخهٔ حلقه‌ای: سه متغیر برای ‎`ways(i-3)`‎، ‎`ways(i-2)`‎ و ‎`ways(i-1)`‎ نگه دارید.

**پاسخ:** حالت دو‌گامی همان فیبوناچی است: $\text{ways}(n) = F(n+1)$. هر دو تابع بازگشتی ساده درخت نمایی دارند.

```c
#include <stdio.h>

static unsigned long calls;

unsigned long long ways12(int n)
{
    calls++;
    return n <= 1 ? 1ULL : ways12(n - 1) + ways12(n - 2);
}

unsigned long long ways123(int n)
{
    calls++;
    if (n < 0)  return 0;
    if (n == 0) return 1;
    return ways123(n - 1) + ways123(n - 2) + ways123(n - 3);
}

unsigned long long ways123_loop(int n)
{
    unsigned long long w0 = 1, w1 = 1, w2 = 2;      /* ways(0), ways(1), ways(2) */
    if (n <= 1) return 1;
    if (n == 2) return 2;
    for (int i = 3; i <= n; i++) {
        unsigned long long t = w0 + w1 + w2;
        w0 = w1; w1 = w2; w2 = t;
    }
    return w2;
}

int main(void)
{
    printf("ways12(10)  = %llu\n", ways12(10));
    printf("ways123(10) = %llu\n", ways123(10));

    calls = 0; unsigned long long a = ways12(25);   unsigned long c1 = calls;
    calls = 0; unsigned long long b = ways123(25);  unsigned long c2 = calls;
    printf("n = 25: ways12 = %llu (%lu calls), ways123 = %llu (%lu calls)\n", a, c1, b, c2);
    printf("loop version for n = 25: %llu\n", ways123_loop(25));
    return 0;
}
```

خروجی:

```text
ways12(10)  = 89
ways123(10) = 274
n = 25: ways12 = 121393 (242785 calls), ways123 = 2555757 (9135460 calls)
loop version for n = 25: 2555757
```

:::

### تمرین ۱۴ ★★★ — بدترین حالت الگوریتم اقلیدس

الگوریتم اقلیدس را بازگشتی بنویسید و تعداد فراخوانی‌هایش را بشمارید. نشان دهید برای ورودی‌های **متوالی فیبوناچی** $(F(k+1), F(k))$ تعداد فراخوانی‌ها بیشینه است، و رابطه‌ای بین تعداد فراخوانی‌ها و $k$ حدس بزنید. چرا نتیجه می‌گیریم زمان اقلیدس $O(\log b)$ است؟

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** برای $a = F(k+1)$ و $b = F(k)$ داریم $a \bmod b = F(k-1)$. پس فراخوانی بعدی $(F(k), F(k-1))$ است.

**راهنمایی ۲:** باقی‌مانده هر دو گام یک‌بار از **نصف** مقدار قبلی کمتر می‌شود؛ ولی فیبوناچی کندترین کاهش ممکن را دارد، چون هر باقی‌مانده فقط حدود $1/\varphi$ بار مقدار قبلی است.

**پاسخ:** تعداد فراخوانی‌ها برای $(F(k+1), F(k))$ برابر $k$ است (چون هر گام یک اندیس فیبوناچی را کم می‌کند و در $F(1)$ و $F(0)$ تمام می‌شود). از طرف دیگر $F(k) \approx \varphi^k$، پس تعداد گام‌ها حدود $\log_\varphi b$ است. این قضیهٔ **لامه** است: بدترین حالت اقلیدس، فیبوناچی است و بنابراین اقلیدس **لگاریتمی** است.

```c
#include <stdio.h>

static unsigned long calls;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    calls++;
    return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
    unsigned long long f_prev = 1, f_cur = 1;        /* F(1), F(2) */
    printf("  k       F(k+1)        F(k)   calls\n");
    for (int k = 1; k <= 40; k++) {
        /* here f_cur = F(k+1), f_prev = F(k) */
        if (k % 5 == 0) {
            calls = 0;
            gcd(f_cur, f_prev);
            printf("%3d %12llu %11llu %7lu\n", k, f_cur, f_prev, calls);
        }
        unsigned long long t = f_prev + f_cur;
        f_prev = f_cur;
        f_cur = t;
    }
    return 0;
}
```

خروجی:

```text
  k       F(k+1)        F(k)   calls
  5            8           5       5
 10           89          55      10
 15          987         610      15
 20        10946        6765      20
 25       121393       75025      25
 30      1346269      832040      30
 35     14930352     9227465      35
 40    165580141   102334155      40
```

:::

## هـ) توان دودویی

### تمرین ۱۵ ★☆☆ — شمارش ضرب‌ها

با تابع ‎`power_fast`‎ درسنامه، تعداد ضرب‌ها را برای $n = 1000$، $n = 1024$ و $n = 1023$ بشمارید. دلیل تفاوت را توضیح دهید و کران $2\log_2 n$ را وارسی کنید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** هر مرحلهٔ زوج یک **مربع‌سازی** است و هر مرحلهٔ فرد یک ضرب در $x$. نمایش دودویی $n$ را بنویسید.

**راهنمایی ۲:** تعداد مربع‌سازی‌ها برابر (تعداد ارقام دودویی $- 1$) است و تعداد ضرب در $x$ برابر تعداد رقم‌های ۱ در نمایش دودویی.

**پاسخ:** تعداد ضرب‌ها = (تعداد بیت‌ها $- 1$) + (تعداد بیت‌های ۱). برای $1024 = 10000000000_2$ فقط یک بیت ۱ داریم (کمترین)، و برای $1023 = 1111111111_2$ همهٔ بیت‌ها ۱ هستند (بیشترین). همیشه حداکثر حدود $2\log_2 n$ ضرب لازم است.

```c
#include <stdio.h>

static unsigned long mults;

unsigned long long power_fast(unsigned long long x, unsigned n)
{
    if (n == 0) return 1;
    if (n % 2 == 0) {
        unsigned long long half = power_fast(x, n / 2);
        mults++;
        return half * half;
    }
    mults++;
    return x * power_fast(x, n - 1);
}

int main(void)
{
    unsigned tests[] = {1000, 1024, 1023};
    for (int i = 0; i < 3; i++) {
        mults = 0;
        power_fast(1, tests[i]);                 /* the base 1 keeps values small */
        printf("n = %4u : %2lu multiplications\n", tests[i], mults);
    }
    return 0;
}
```

خروجی:

```text
n = 1000 : 15 multiplications
n = 1024 : 11 multiplications
n = 1023 : 19 multiplications
```

:::

### تمرین ۱۶ ★★☆ — توان با نمای منفی

تابع ‎`power_real(double x, int n)`‎ بنویسید که $x^n$ را برای هر نمای صحیح (مثبت، صفر یا منفی) با روش نصف‌کردن حساب کند. یک مشکل ظریف برای $n = \text{INT\_MIN}$ را توضیح دهید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** $x^{-n} = 1 / x^n$.

**راهنمایی ۲:** در مقدار $-n$ برای $n = -2^{31}$ چه می‌شود؟ بزرگ‌ترین ‎`int`‎ چقدر است؟

**پاسخ:** مقدار $-\text{INT\_MIN}$ در ‎`int`‎ نمی‌گنجد (سرریز)؛ برای ایمنی می‌توان نمای منفی را به ‎`long long`‎ تبدیل کرد.

```c
#include <stdio.h>

double power_real(double x, long long n)
{
    if (n < 0) return 1.0 / power_real(x, -n);
    if (n == 0) return 1.0;
    double half = power_real(x, n / 2);
    return n % 2 == 0 ? half * half : half * half * x;
}

int main(void)
{
    printf("2^10    = %.5f\n", power_real(2.0, 10));
    printf("2^-3    = %.5f\n", power_real(2.0, -3));
    printf("1.5^5   = %.5f\n", power_real(1.5, 5));
    printf("10^0    = %.5f\n", power_real(10.0, 0));
    return 0;
}
```

خروجی:

```text
2^10    = 1024.00000
2^-3    = 0.12500
1.5^5   = 7.59375
10^0    = 1.00000
```

:::

### تمرین ۱۷ ★★★ — رقم‌های آخر

بدون حلقهٔ طولانی، سه رقم آخر $7^{2026}$ و سه رقم آخر $3^{10^{15}}$ را پیدا کنید. توضیح دهید چرا در هر گام می‌توان باقی‌مانده گرفت و چرا ضرب‌ها سرریز نمی‌کنند.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** سه رقم آخر یعنی باقی‌مانده بر $1000$. از خاصیت $(a \cdot b) \bmod m = \big((a \bmod m)(b \bmod m)\big) \bmod m$ استفاده کنید.

**راهنمایی ۲:** تابع ‎`power_mod`‎ درسنامه را با $\text{MOD} = 1000$ بنویسید. هر ضرب حداکثر $999 \times 999$ است.

**پاسخ:** چون هر عامل کمتر از $1000$ است، حاصل‌ضرب‌ها کمتر از $10^6$ می‌مانند و سرریز نمی‌کنند؛ تعداد ضرب‌ها هم فقط حدود $2\log_2 n$ است (برای $n = 10^{15}$ حدود ۱۰۰ ضرب).

```c
#include <stdio.h>

unsigned long long power_mod(unsigned long long x, unsigned long long n, unsigned long long mod)
{
    if (n == 0) return 1 % mod;
    unsigned long long half = power_mod(x, n / 2, mod);
    unsigned long long r = half * half % mod;
    if (n % 2 == 1) r = r * (x % mod) % mod;
    return r;
}

int main(void)
{
    printf("7^2026 mod 1000     = %llu\n", power_mod(7, 2026, 1000));
    printf("3^(10^15) mod 1000  = %llu\n", power_mod(3, 1000000000000000ULL, 1000));
    return 0;
}
```

خروجی:

```text
7^2026 mod 1000     = 649
3^(10^15) mod 1000  = 1
```

:::

## و) حساب پئانو و آکرمان

### تمرین ۱۸ ★★☆ — مقایسه فقط با ‎`dec`‎

با فرض اینکه فقط می‌توانید از ‎`dec`‎، مقایسه با صفر (‎`== 0`‎) و بازگشت استفاده کنید، توابع ‎`leq(a, b)`‎ (آیا $a \le b$)، ‎`equal(a, b)`‎ و ‎`maximum(a, b)`‎ را بنویسید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** ‎`leq`‎: اگر $a = 0$ باشد حتماً درست است؛ اگر $a > 0$ ولی $b = 0$ باشد نادرست. در غیر این صورت هر دو را یکی کم کنید.

**راهنمایی ۲:** $a = b$ یعنی $a \le b$ و $b \le a$.

**پاسخ:**

```c
#include <stdio.h>

typedef unsigned int uint;

uint dec(uint a) { return --a; }

int leq(uint a, uint b)
{
    return a == 0 ? 1 : (b == 0 ? 0 : leq(dec(a), dec(b)));
}

int equal(uint a, uint b)    { return leq(a, b) && leq(b, a); }
uint maximum(uint a, uint b) { return leq(a, b) ? b : a; }

int main(void)
{
    printf("leq(3, 5)     = %d\n", leq(3, 5));
    printf("leq(5, 3)     = %d\n", leq(5, 3));
    printf("equal(4, 4)   = %d\n", equal(4, 4));
    printf("maximum(7, 2) = %u\n", maximum(7, 2));
    return 0;
}
```

خروجی:

```text
leq(3, 5)     = 1
leq(5, 3)     = 0
equal(4, 4)   = 1
maximum(7, 2) = 7
```

:::

### تمرین ۱۹ ★★☆ — آکرمان با دست

$A(1, 2)$ را با ردیابی کامل (نوشتن همهٔ گام‌ها) حساب کنید و تعداد فراخوانی‌ها را بشمارید. سپس بدون محاسبهٔ کامل حدس بزنید $A(2, 2)$ چند فراخوانی دارد؛ با برنامه وارسی کنید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** از قاعدهٔ سوم شروع کنید: $A(1, 2) = A(0, A(1, 1))$. ابتدا باید $A(1, 1)$ را به‌دست آورید.

**راهنمایی ۲:** در جدول مبحث ۴ ببینید $A(2, 2)$ چه مقداری دارد؛ تعداد فراخوانی‌ها حدود چند برابر $A(1,2)$ است؟

**پاسخ:**

$$\begin{aligned}
A(1,0) &= A(0,1) = 2 \\
A(1,1) &= A(0, A(1,0)) = A(0,2) = 3 \\
A(1,2) &= A(0, A(1,1)) = A(0,3) = 4
\end{aligned}$$

فراخوانی‌ها: $A(1,2),\ A(1,1),\ A(1,0),\ A(0,1),\ A(0,2),\ A(0,3)$، یعنی ۶ تا. مقدار $A(2, 2) = 7$.

```c
#include <stdio.h>

static unsigned long calls;

unsigned long ack(unsigned long m, unsigned long n)
{
    calls++;
    if (m == 0) return n + 1;
    if (n == 0) return ack(m - 1, 1);
    return ack(m - 1, ack(m, n - 1));
}

int main(void)
{
    calls = 0; unsigned long a = ack(1, 2); printf("A(1,2) = %lu, calls = %lu\n", a, calls);
    calls = 0; unsigned long b = ack(2, 2); printf("A(2,2) = %lu, calls = %lu\n", b, calls);
    return 0;
}
```

خروجی:

```text
A(1,2) = 4, calls = 6
A(2,2) = 7, calls = 27
```

:::

### تمرین ۲۰ ★★★ — اثبات با استقرا

با استقرا ثابت کنید $A(1, n) = n + 2$ و $A(2, n) = 2n + 3$.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** اول $A(1, n)$ را ثابت کنید؛ سپس $A(2, n)$ را بر اساس آن.

**راهنمایی ۲:** برای گام استقرا از قاعدهٔ سوم استفاده کنید: $A(m+1, n+1) = A(m, A(m+1, n))$.

**پاسخ:**

- $A(1, \cdot)$: پایه: $A(1, 0) = A(0, 1) = 2 = 0 + 2$. گام: $A(1, n+1) = A(0, A(1, n)) = A(1, n) + 1 = (n + 2) + 1 = (n+1) + 2$.
- $A(2, \cdot)$: پایه: $A(2, 0) = A(1, 1) = 3 = 2 \cdot 0 + 3$. گام: $A(2, n+1) = A(1, A(2, n)) = A(2, n) + 2 = (2n + 3) + 2 = 2(n+1) + 3$.

(با همین روش $A(3, n) = 2^{n+3} - 3$ هم ثابت می‌شود.)
:::

## ز) بازگشت و حلقه

### تمرین ۲۱ ★★☆ — بازگشت دُم‌دار

کدام یک از توابع زیر بازگشت دُم‌دار دارند؟ برای ‎`count_digits`‎ یک نسخهٔ دُم‌دار (با انباره) بنویسید.

```c
unsigned gcd(unsigned a, unsigned b)         { return b == 0 ? a : gcd(b, a % b); }
unsigned fact(unsigned n)                    { return n <= 1 ? 1 : n * fact(n - 1); }
unsigned sum_acc(unsigned n, unsigned acc)   { return n == 0 ? acc : sum_acc(n - 1, acc + n); }
unsigned count_digits(unsigned n)            { return n < 10 ? 1 : 1 + count_digits(n / 10); }
```

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** در بازگشت دُم‌دار، پس از بازگشت فراخوانی **هیچ عملی** باقی نمی‌ماند: خودِ فراخوانی همان مقدار بازگشتی تابع است.

**راهنمایی ۲:** در ‎`count_digits`‎ عمل باقی‌مانده ‎`1 + ...`‎ است؛ آن را به پارامتر جدیدی منتقل کنید که شمارش جاری را نگه می‌دارد.

**پاسخ:** ‎`gcd`‎ و ‎`sum_acc`‎ دُم‌دارند. ‎`fact`‎ (ضرب بعد از بازگشت) و ‎`count_digits`‎ (جمع بعد از بازگشت) دُم‌دار نیستند.

```c
#include <stdio.h>

unsigned count_digits_tail(unsigned n, unsigned acc)
{
    return n < 10 ? acc + 1 : count_digits_tail(n / 10, acc + 1);
}

unsigned count_digits(unsigned n) { return count_digits_tail(n, 0); }

int main(void)
{
    printf("count_digits(7)       = %u\n", count_digits(7));
    printf("count_digits(12345)   = %u\n", count_digits(12345));
    printf("count_digits(1000000) = %u\n", count_digits(1000000));
    return 0;
}
```

خروجی:

```text
count_digits(7)       = 1
count_digits(12345)   = 5
count_digits(1000000) = 7
```

:::

### تمرین ۲۲ ★★★ — توان دودویی بدون بازگشت

نسخهٔ **حلقه‌ای** توان دودویی را با یک **پایای حلقه** (Loop Invariant) بنویسید. نشان دهید در طول حلقه مقدار $r \cdot x^n$ تغییر نمی‌کند. با نسخهٔ بازگشتی مقایسه کنید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** اگر $n$ زوج باشد $x^n = (x^2)^{n/2}$؛ اگر فرد باشد یک $x$ را بیرون بکشید: $x^n = x \cdot x^{n-1}$ و $n - 1$ زوج است.

**راهنمایی ۲:** یک متغیر $r$ (شروع از ۱) برای «ضرایب بیرون‌کشیده» نگه دارید. در هر دور: اگر $n$ فرد بود $r \leftarrow r \cdot x$؛ سپس $x \leftarrow x \cdot x$ و $n \leftarrow \lfloor n / 2 \rfloor$.

**پاسخ:** مقدار اولیه $r = 1$ پایا را برقرار می‌کند ($1 \cdot x^n$). اگر $n$ فرد باشد: $(r x)(x^2)^{(n-1)/2} = r x^n$ ✓. اگر زوج باشد: $r (x^2)^{n/2} = r x^n$ ✓. وقتی $n = 0$ شد، $r \cdot x^0 = r$ جواب است. (این همان تبدیل بازگشت دُم‌دار به حلقه است.)

```c
#include <stdio.h>

unsigned long long power_rec(unsigned long long x, unsigned n)
{
    if (n == 0) return 1;
    if (n % 2 == 0) { unsigned long long h = power_rec(x, n / 2); return h * h; }
    return x * power_rec(x, n - 1);
}

unsigned long long power_loop(unsigned long long x, unsigned n)
{
    unsigned long long r = 1;
    while (n > 0) {
        if (n % 2 == 1) r = r * x;       /* invariant: r * x^n is constant */
        x = x * x;
        n = n / 2;
    }
    return r;
}

int main(void)
{
    int mismatches = 0;
    for (unsigned n = 0; n <= 39; n++)
        if (power_rec(3, n) != power_loop(3, n)) mismatches++;
    printf("3^n for n = 0..39: mismatches = %d\n", mismatches);
    printf("3^39 = %llu\n", power_loop(3, 39));
    return 0;
}
```

خروجی:

```text
3^n for n = 0..39: mismatches = 0
3^39 = 4052555153018976267
```

:::

## ح) Stack، Queue، DFS و BFS

### تمرین ۲۳ ★★☆ — دودویی با Stack صریح

مسئلهٔ تمرین ۸ را بدون بازگشت و با Stack صریح (‎`adt.h`‎) حل کنید. ارتباط Stack برنامهٔ شما با Call Stack تمرین ۸ چیست؟

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** ارقام را به ترتیب **از راست به چپ** تولید می‌کنید ولی باید از **چپ به راست** چاپ کنید. کدام ساختار ترتیب را برعکس می‌کند؟

**راهنمایی ۲:** رقم‌های ‎`n % 2`‎ را تا وقتی $n > 0$ است ‎`push`‎ کنید و بعد تا خالی شدن ‎`pop`‎ و چاپ کنید. حالت $n = 0$ را جدا در نظر بگیرید.

**پاسخ:** هر ‎`push`‎ متناظر یک فراخوانی (Frame منتظر چاپ رقم) و هر ‎`pop`‎ متناظر یک بازگشت است؛ همان کاری که Call Stack خودکار می‌کرد.

```c
#include <stdio.h>
#include "adt.h"

void print_binary_stack(unsigned n)
{
    if (n == 0) { printf("0"); return; }
    while (n > 0) {
        s_push((int)(n % 2));
        n = n / 2;
    }
    while (!s_empty())
        printf("%d", s_pop());
}

int main(void)
{
    unsigned tests[] = {0, 13, 255};
    for (int i = 0; i < 3; i++) {
        printf("%3u -> ", tests[i]);
        print_binary_stack(tests[i]);
        printf("\n");
    }
    return 0;
}
```

خروجی:

```text
  0 -> 0
 13 -> 1101
255 -> 11111111
```

:::

### تمرین ۲۴ ★★☆ — عددهای دودویی با Queue

با یک Queue، $n$ عدد اول دنبالهٔ «عددهای دودویی» را به ترتیب چاپ کنید: ۱، ۱۰، ۱۱، ۱۰۰، ۱۰۱، ... (عدد دودویی را به‌صورت یک عدد دهدهی با ارقام ۰ و ۱ ذخیره کنید).

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** اگر $x$ یک عدد دودویی باشد، $10x$ و $10x + 1$ (یعنی صفر یا یک به انتهایش اضافه شود) بلافاصله بعد از آن می‌آیند.

**راهنمایی ۲:** با ‎`1`‎ شروع کنید؛ هر بار یک عدد را از ابتدای صف بردارید، چاپ کنید و دو فرزندش را به انتهای صف بدهید. این یک BFS روی «درخت دودویی نامتناهی» است.

**پاسخ:** ترتیب FIFO تضمین می‌کند اعداد کوتاه‌تر پیش از بلندتر چاپ شوند، یعنی به ترتیب سطح (BFS).

```c
#include <stdio.h>
#include "adt.h"

int main(void)
{
    int n = 10;
    q_push(1);
    for (int i = 0; i < n; i++) {
        int x = q_pop();
        printf("%d ", x);
        q_push(x * 10);
        q_push(x * 10 + 1);
    }
    printf("\n");
    return 0;
}
```

خروجی:

```text
1 10 11 100 101 110 111 1000 1001 1010 
```

:::

### تمرین ۲۵ ★★★ — برج هانوی (چالش پایانی)

سه میله $A$، $B$ و $C$ و $n$ دیسک با اندازه‌های مختلف روی $A$ هستند (کوچک‌تر بالاتر). می‌خواهیم همه را به $C$ ببریم؛ هر بار یک دیسک، و هیچ‌وقت دیسک بزرگ‌تر روی کوچک‌تر نباشد.

1. تابع بازگشتی ‎`hanoi(n, from, to, via)`‎ بنویسید که حرکت‌ها را چاپ کند و برای $n = 3$ اجرا کنید.
2. نشان دهید تعداد حرکت‌ها $2^n - 1$ است. چرا هیچ الگوریتمی نمی‌تواند از این کمتر حرکت انجام دهد؟
3. درخت بازگشت چه شکلی است؟ ارتفاع آن و عمق Stack چقدر است؟
4. آیا می‌شود این مسئله را با BFS (حلقه + Queue) به‌جای DFS حل کرد و ترتیب درست حرکت‌ها را داشت؟

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** برای جابه‌جا کردن $n$ دیسک از $A$ به $C$: ابتدا $n-1$ دیسک بالایی را از $A$ به $B$ ببرید (با $C$ به‌عنوان میانجی)، سپس بزرگ‌ترین دیسک را از $A$ به $C$، و بعد آن $n-1$ دیسک را از $B$ به $C$.

**راهنمایی ۲:** رابطهٔ تعداد حرکت: $T(n) = 2T(n-1) + 1$ و $T(0) = 0$. چند مقدار اول را بنویسید و حدس بزنید.

**پاسخ:**

۱) برنامهٔ زیر. ۲) از رابطه: $T(n) = 2T(n-1) + 1 \Rightarrow T(n) = 2^n - 1$ (استقرا). کران پایین: بزرگ‌ترین دیسک باید دست‌کم یک بار حرکت کند و در لحظهٔ حرکتش همهٔ $n-1$ دیسک دیگر روی یک میلهٔ دیگر هستند؛ پس قبل از آن دست‌کم $T(n-1)$ حرکت و بعد از آن هم دست‌کم $T(n-1)$ حرکت لازم است، یعنی $T(n) \ge 2T(n-1) + 1$. چون **اندازهٔ خروجی** خودش نمایی است، هیچ الگوریتمی نمی‌تواند سریع‌تر شود (برخلاف فیبوناچی، اینجا «دو فراخوانی» قابل حذف نیست). ۳) درخت دودویی کامل با ارتفاع $n$؛ ولی عمق Stack فقط $n$ است. ۴) خیر؛ هر حرکت به **نتیجهٔ حرکت‌های قبلی** در همان ترتیب وابسته است و BFS ترتیب را به‌هم می‌ریزد (شرط‌های مبحث ۷ برقرار نیست).

```c
#include <stdio.h>

static unsigned long moves;

void hanoi(int n, char from, char to, char via, int verbose)
{
    if (n == 0) return;
    hanoi(n - 1, from, via, to, verbose);                 /* n-1 disks out of the way */
    moves++;
    if (verbose) printf("move disk %d: %c -> %c\n", n, from, to);
    hanoi(n - 1, via, to, from, verbose);                 /* n-1 disks on top of it */
}

int main(void)
{
    moves = 0;
    hanoi(3, 'A', 'C', 'B', 1);
    printf("n = 3: %lu moves\n", moves);

    for (int n = 10; n <= 20; n += 10) {
        moves = 0;
        hanoi(n, 'A', 'C', 'B', 0);
        printf("n = %d: %lu moves (2^n - 1 = %lu)\n", n, moves, (1UL << n) - 1);
    }
    return 0;
}
```

خروجی:

```text
move disk 1: A -> C
move disk 2: A -> B
move disk 1: C -> B
move disk 3: A -> C
move disk 1: B -> A
move disk 2: B -> C
move disk 1: A -> C
n = 3: 7 moves
n = 10: 1023 moves (2^n - 1 = 1023)
n = 20: 1048575 moves (2^n - 1 = 1048575)
```

:::

## ط) ماکروها

### تمرین ۲۶ ★☆☆ — بسط ماکرو

با فرض ماکروهای زیر، مقدار هر عبارت را **ابتدا بسط دهید و بعد حساب کنید**. سپس هر ماکرو را اصلاح کنید.

```c
#define SQ(x)     x * x
#define AVG(a, b) a + b / 2
```

1. ‎`SQ(2 + 3)`‎
2. ‎`10 / SQ(2)`‎
3. ‎`AVG(4, 2) * 3`‎

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** ماکرو فقط متن را جایگزین می‌کند و **پرانتز اضافه نمی‌کند**. مثلاً ‎`SQ(2 + 3)`‎ می‌شود ‎`2 + 3 * 2 + 3`‎.

**راهنمایی ۲:** حق تقدم عملگرها را اعمال کنید: ضرب و تقسیم پیش از جمع، و ضرب و تقسیم از چپ به راست.

**پاسخ:** (۱) ‎`2 + 3 * 2 + 3`‎ = ۱۱ (نه ۲۵). (۲) ‎`10 / 2 * 2`‎ = ۱۰ (نه $10/4$ که در ‎`int`‎ برابر ۲ است). (۳) ‎`4 + 2 / 2 * 3`‎ = ۷ (نه ۹). اصلاح: ‎`#define SQ(x) ((x) * (x))`‎ و ‎`#define AVG(a, b) (((a) + (b)) / 2)`‎.

```c
#include <stdio.h>

#define SQ(x)      x * x
#define AVG(a, b)  a + b / 2

#define SQ_OK(x)      ((x) * (x))
#define AVG_OK(a, b)  (((a) + (b)) / 2)

int main(void)
{
    printf("SQ(2 + 3)        = %d   fixed: %d\n", SQ(2 + 3), SQ_OK(2 + 3));
    printf("10 / SQ(2)       = %d   fixed: %d\n", 10 / SQ(2), 10 / SQ_OK(2));
    printf("AVG(4, 2) * 3    = %d   fixed: %d\n", AVG(4, 2) * 3, AVG_OK(4, 2) * 3);
    return 0;
}
```

خروجی:

```text
SQ(2 + 3)        = 11   fixed: 25
10 / SQ(2)       = 10   fixed: 2
AVG(4, 2) * 3    = 7   fixed: 9
```

:::

### تمرین ۲۷ ★★☆ — ماکروی امن یا تابع؟

ماکروی ‎`ABS(x)`‎ را بنویسید. نشان دهید با آرگومانی که اثر جانبی دارد (مثلاً تابعی که هر بار شمارنده را کم می‌کند و آن را برمی‌گرداند) نتیجهٔ غلط می‌دهد. چه راهی برای اصلاح می‌بینید؟

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** ماکروی ‎`ABS`‎ چند بار پارامتر ‎`x`‎ را در بدنه‌اش می‌نویسد؟ هر بار یعنی یک ارزیابی جدا.

**راهنمایی ۲:** تابع آرگومانش را یک بار ارزیابی می‌کند (فراخوانی با مقدار).

**پاسخ:** پرانتزگذاری کامل برای حق تقدم کافی است اما **ارزیابی چندباره** را حل نمی‌کند. راه اصلاح: تابع واقعی (‎`static inline`‎) یا هرگز آرگومان با اثر جانبی به ماکرو ندادن.

```c
#include <stdio.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

static int counter = 0;

int next_negative(void)
{
    counter--;
    return counter;
}

int abs_fn(int x) { return x < 0 ? -x : x; }

int main(void)
{
    counter = 0;
    int a = ABS(next_negative());
    printf("macro   : result = %d, counter = %d (called twice)\n", a, counter);

    counter = 0;
    int b = abs_fn(next_negative());
    printf("function: result = %d, counter = %d (called once)\n", b, counter);
    return 0;
}
```

خروجی:

```text
macro   : result = 2, counter = -2 (called twice)
function: result = 1, counter = -1 (called once)
```

:::

## ی) تمرین جامع

### تمرین ۲۸ ★★★ — اعداد کاتالان

اعداد کاتالان $C_n$ تعداد رشته‌های متوازن با $n$ جفت پرانتز را می‌شمارند (مبحث تکمیلی ۶) و رابطهٔ بازگشتی زیر را دارند:

$$C_0 = 1, \qquad C_n = \sum_{i=0}^{n-1} C_i \, C_{n-1-i}$$

1. تابع بازگشتی ‎`catalan(n)`‎ بنویسید که این رابطه را مستقیماً پیاده کند (یک حلقهٔ ‎`for`‎ داخل تابع).
2. تعداد فراخوانی‌ها را برای $n = 0, \dots, 12$ بشمارید و رابطه‌اش را با $n$ حدس بزنید و ثابت کنید.
3. نتیجه را با فرمول $C_n = \dfrac{1}{n+1}\dbinom{2n}{n}$ مقایسه کنید.

:::{admonition} راهنمایی‌ها و پاسخ
:class: dropdown

**راهنمایی ۱:** اگر $F(n)$ تعداد فراخوانی‌های ‎`catalan(n)`‎ باشد، رابطه‌اش را از ساختار حلقه بنویسید: $F(n) = 1 + \sum_{i=0}^{n-1} \big(F(i) + F(n-1-i)\big)$.

**راهنمایی ۲:** چند مقدار اول را حساب کنید: $F(0), F(1), F(2), F(3)$. توان یک عدد ثابت را می‌بینید؟

**پاسخ:** $F(n) = 3^n$. اثبات با استقرا: $F(0) = 1$. و

$$F(n) = 1 + 2\sum_{i=0}^{n-1} F(i) = 1 + 2\sum_{i=0}^{n-1} 3^i = 1 + (3^n - 1) = 3^n$$

یعنی باز هم زمان **نمایی** است، با اینکه $C_n$ فقط حدود $4^n$ رشد می‌کند. راه‌حل بعدی، ذخیره‌کردن جواب زیرمسئله‌ها (Memoization) است که با آرایه‌ها در بخش بعد ممکن می‌شود.

```c
#include <stdio.h>

static unsigned long calls;

unsigned long long catalan(int n)
{
    calls++;
    if (n == 0) return 1;
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += catalan(i) * catalan(n - 1 - i);
    return sum;
}

unsigned long long binom_loop(int n, int k)
{
    unsigned long long r = 1;
    for (int i = 0; i < k; i++)
        r = r * (n - i) / (i + 1);
    return r;
}

unsigned long long pow3(int n) { return n == 0 ? 1 : 3 * pow3(n - 1); }

int main(void)
{
    printf("  n   catalan(n)    calls   3^n    formula\n");
    for (int n = 0; n <= 12; n++) {
        calls = 0;
        unsigned long long c = catalan(n);
        printf("%3d %12llu %8lu %8llu %10llu\n", n, c, calls, pow3(n), binom_loop(2 * n, n) / (n + 1));
    }
    return 0;
}
```

خروجی:

```text
  n   catalan(n)    calls   3^n    formula
  0            1        1        1          1
  1            1        3        3          1
  2            2        9        9          2
  3            5       27       27          5
  4           14       81       81         14
  5           42      243      243         42
  6          132      729      729        132
  7          429     2187     2187        429
  8         1430     6561     6561       1430
  9         4862    19683    19683       4862
 10        16796    59049    59049      16796
 11        58786   177147   177147      58786
 12       208012   531441   531441     208012
```

:::
