# انتشار (Production)

راهنمای ساخت و انتشار کتاب درس. دانشجویان می‌توانند از سایت منتشرشده استفاده
کنند و به این راهنما نیازی ندارند.

## ساخت کتاب آنلاین

کتاب با **Jupyter Book 2** (موتور MyST) ساخته می‌شود. تمام تنظیمات در یک فایل
`myst.yml` در ریشه‌ی مخزن است: متادیتا، وابستگی‌های سازمانی، گزینه‌های سایت
(لوگو، استایل) و فهرست مطالب صریح. صفحه‌ی آغازین `book/index.md` است و بخش‌ها
در `book/parts/` قرار دارند.

روش نصب مانند CI (با Node.js ۲۴ و npm):

```bash
npm install -g jupyter-book@2
```

یا با Python در یک محیط مجازی:

```bash
python3 -m venv .venv
source .venv/bin/activate
python -m pip install 'jupyter-book>=2,<3'
```

با هر دو روش، از ریشه‌ی مخزن اجرا کنید:

```bash
env -u PORT -u BASE_URL jupyter-book build --html  # خروجی: _build/html/
```

فرمان مشترک هر دو روش `jupyter-book` است؛ نصب npm فرمان جداگانه‌ی `jupyter` را
فراهم نمی‌کند. برای بیلد محلی، `PORT` و `BASE_URL` را حذف می‌کنیم تا تنظیمات
شل روی نشانی سرور و مسیر فایل‌های سایت اثر نگذارند. در اولین بیلد، MyST قالب
سایت را دانلود می‌کند و به اینترنت نیاز دارد.

بیلد عادی نوت‌بوک‌ها را **اجرا نمی‌کند**؛ از خروجی‌های ذخیره‌شده استفاده می‌کند
و به کرنل Jupyter یا کامپایلر C نیاز ندارد. برای اجرای نوت‌بوک‌ها، پس از آماده‌کردن
کرنل‌ها و ابزارهای لازم، گزینهٔ `--execute` را به دستور بیلد اضافه کنید.

## انتشار خودکار روی GitHub Pages

هر push به `main` توسط `.github/workflows/deploy.yml` بیلد و منتشر می‌شود
(`jupyter-book` را با npm نصب می‌کند، `jupyter-book build --html` را با
`BASE_URL=/<نام-مخزن>` اجرا می‌کند و روی Pages منتشر می‌کند). پیشرفت را در
زبانه‌ی **Actions** ببینید. در *Settings → Pages* گزینه‌ی **Source** باید
همیشه **GitHub Actions** باشد.

برای بررسی پیش از Pull Request، بیلد و آزمون محلی را طبق
[راهنمای مشارکت](CONTRIBUTING.md#بیلد-و-بررسی-پیش-از-pull-request) اجرا کنید.

## اجرای محلی کتاب

با بازسازی خودکار هنگام ویرایش:

```bash
env -u PORT -u BASE_URL jupyter-book start   # http://localhost:3000
```

یا سرو کردن سایت استاتیکِ ساخته‌شده:

```bash
python3 -m http.server 8811 --bind 127.0.0.1 --directory _build/html
```

از ریشه‌ی مخزن این دستور را اجرا کنید و [صفحهٔ کتاب](http://127.0.0.1:8811/)
را باز کنید. باز کردن مستقیم `index.html` از روی دیسک جای وب‌سرور را نمی‌گیرد.

## متوقف کردن سرورهای محلی

سرور را با `Ctrl-C` در همان ترمینال متوقف کنید. سرورهای پس‌زمینه:

```bash
ss -tlnp | grep -E ':(3000|3001|8811)'   # پیدا کردن پورت‌ها و PIDها
kill <PID>                               # توقف نرم؛ اگر نشد: kill -9
fuser -k 3000/tcp                        # یا آزاد کردن مستقیم یک پورت
pkill -f "book-theme/server.js"          # سرور باقی‌مانده‌ی `jupyter-book start`
```

## روش دستی انتشار روی GitHub Pages

```bash
BASE_URL=/fundamentals-of-programming/ env -u PORT jupyter-book build --html
pip install ghp-import
ghp-import -n -p -f ./_build/html
```

## خروجی PDF (اختیاری)

یک export با `format: pdf` به `myst.yml` اضافه کنید و
`env -u PORT jupyter-book build --pdf` را اجرا کنید (خروجی PDF در نسخه‌ی ۲ از
طریق Typst انجام می‌شود).

## مثال‌های C و فایل‌های تولیدشده

بعضی نوت‌بوک‌ها هنگام اجرا فایل‌های `src/*.c` را می‌سازند و در `bin/` کامپایل
می‌کنند. پوشه‌ی `src/` در گیت نگه داشته می‌شود؛ پوشه‌ی `bin/` (فایل‌های اجرایی
کامپایل‌شده) خروجی بیلد است و نادیده گرفته می‌شود.
