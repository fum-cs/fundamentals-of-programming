# مبانی کامپیوتر و برنامه‌سازی (زبان C)

**[English](README.en.md)** | فارسی

کتاب و مواد درس **مبانی کامپیوتر و برنامه‌سازی** (کارشناسی، سال اول)،
[گروه علوم کامپیوتر، دانشگاه فردوسی مشهد](https://fum-cs.github.io/).

- **کتاب آنلاین:** <https://fum-cs.github.io/fundamentals-of-programming/>
- **سرفصل رسمی درس:** [Computer-Fundamentals-and-Programming](https://fum-cs.github.io/docs/curriculum/base/Computer-Fundamentals-and-Programming)
- **مدرس:** دکتر محمود امین‌طوسی

زبان درس **C** است، اما تأکید اصلی بر **حل مسئله** و **تفکر الگوریتمی** است:
کامپیوتر به‌عنوان یک مدل محاسباتی، الگوریتم، و سپس یک زبان سطح بالا برای
بیان آن‌ها (توابع، آرایه‌ها، فایل‌ها، بازگشت، جستجو و مرتب‌سازی). متن کتاب
فارسی است؛ کدها، نام شناسه‌ها و اصطلاحات فنی به انگلیسی نوشته شده‌اند.

## فهرست مطالب

کتاب هشت بخش و ۱۷ فصل دارد (شماره‌ی فصل‌ها در کل کتاب پیوسته است):

| بخش | عنوان | پوشه | وضعیت |
|:--|:--|:--|:--|
| ۱ | مبانی و مقدمات (الگوریتم، کامپیوتر و داده، C و ابزارها) | `book/parts/p01-basics/` | ✅ |
| ۲ | داده‌ها و عملگرها | `book/parts/p02-data-operators/` | ✅ |
| ۳ | کنترل جریان | `book/parts/p03-control-flow/` | ✅ |
| ۴ | توابع و بازگشت (فصل ۸ تا ۱۰) | `book/parts/p04-functions/` | ✅ |
| ۵ | ساختارهای داده پایه: آرایه، جستجو و مرتب‌سازی، رشته (فصل ۱۱ تا ۱۳) | `book/parts/p05-basic-data-structures/` | ✅ |
| ۶ | اشاره‌گرها و حافظه‌ی پویا (فصل ۱۴ و ۱۵) | `book/parts/p06-pointers-memory/` | ✅ |
| ۷ | ساختار، اجتماع و فایل (فصل ۱۶ و ۱۷) | `book/parts/p07-structs-files/` | ✅ |
| ۸ | مباحث تکمیلی (پیش‌پردازنده، آرگومان‌های خط فرمان، …) | `book/parts/p08-misc/` | 🚧 در دست تدوین |

## ساختار مخزن

```
myst.yml                  # تنظیمات کتاب + فهرست مطالب (فایلی که واقعاً استفاده می‌شود)
book/
  index.md                # صفحه‌ی آغازین
  style.css               # استایل راست‌به‌چپ و فونت وزیرمتن
  sidebar-footer.md
  images/                 # تصاویر عمومی کتاب (لوگوی دانشگاه)
  parts/pNN-topic/
    part-xxx.ipynb        # بخش به‌صورت نوت‌بوک (در فهرست مطالب همین فایل می‌آید)
    part-xxx.md           # همان بخش به‌صورت متن Markdown
    src/                  # برنامه‌های نمونه‌ی C: pNN_cCC_SS_name.c
    images/               # تصاویر مخصوص همان بخش
.github/workflows/        # انتشار روی GitHub Pages (+ بررسی بیلد در Pull Request)
CONTRIBUTING.md           # راهنمای افزودن و ویرایش محتوا
production.md             # جزئیات بیلد، اجرای محلی و انتشار
```

## ساخت کتاب روی سیستم خودتان

کتاب با **Jupyter Book 2** (موتور MyST) ساخته می‌شود. از ریشه‌ی مخزن:

```bash
pip install jupyter-book                 # یا: npm install -g jupyter-book
env -u PORT jupyter book build --html    # خروجی در: _build/html/
```

خروجی را از طریق یک وب‌سرور باز کنید، نه با دوبار کلیک روی `index.html`
(جزئیات در [production.md](production.md)). هر push به شاخه‌ی `main` به‌طور
خودکار بیلد و روی GitHub Pages منتشر می‌شود.

## اجرای مثال‌های C

مثال‌های داخل `book/parts/*/src/` برنامه‌های ساده‌ی C11 هستند:

```bash
gcc -std=c11 -Wall -Wextra -o prog book/parts/p01-basics/src/p01_c01_02_max_of_five.c
./prog
```

## مشارکت

مخزن را مدرس و دستیاران آموزشی مدیریت می‌کنند و از دانشجویان هم برای گزارش
اشکال‌ها استقبال می‌شود. راهنما: [CONTRIBUTING.md](CONTRIBUTING.md).
غلط املایی، توضیح نادرست یا مثال خراب پیدا کردید؟
[یک Issue باز کنید](../../issues/new/choose).

## اسناد بیشتر

- [CONTRIBUTING.md](CONTRIBUTING.md) — راهنمای مشارکت
- [docs/style-guide.md](docs/style-guide.md) — راهنمای نگارش فارسی و قالب‌بندی کتاب
- [docs/part-template.md](docs/part-template.md) — الگوی ساخت یک بخش جدید
- [CONTRIBUTORS.md](CONTRIBUTORS.md) — فهرست مشارکت‌کنندگان
- [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md) — آیین رفتار
- [production.md](production.md) — بیلد و انتشار

## وضعیت

🚧 در دست تدوین برای ترم جاری — بخش‌ها همزمان با پیشرفت درس بازبینی می‌شوند.
