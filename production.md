# انتشار (Production)

راهنمای ساخت و انتشار کتاب درس. دانشجویان می‌توانند از سایت منتشرشده استفاده
کنند و به این راهنما نیازی ندارند.

## ساخت کتاب آنلاین

کتاب با **Jupyter Book 2** (موتور MyST) ساخته می‌شود. تمام تنظیمات در یک فایل
`myst.yml` در ریشه‌ی مخزن است: متادیتا، وابستگی‌های سازمانی، گزینه‌های سایت
(لوگو، استایل) و فهرست مطالب صریح. صفحه‌ی آغازین `book/index.md` است و بخش‌ها
در `book/parts/` قرار دارند.

نصب:

```bash
pip install jupyter-book            # نسخه‌ی ۲ — پوششی روی موتور MyST
# یا: npm install -g jupyter-book   (همان چیزی که CI استفاده می‌کند)
```

بیلد از ریشه‌ی مخزن:

```bash
jupyter book build --html           # خروجی: _build/html/
```

نکته: اگر شل شما متغیر `PORT` را export می‌کند (مثلاً `PORT=0`)، آن را برای بیلد
حذف کنید؛ MyST این متغیر را می‌خواند و خروجی استاتیک سعی می‌کند صفحه‌ها را از
`http://localhost:0` بگیرد و شکست می‌خورد:

```bash
env -u PORT jupyter book build --html
```

نوت‌بوک‌ها هنگام بیلد **اجرا نمی‌شوند** و از خروجی‌های ذخیره‌شده استفاده
می‌شود. برای اجرای آن‌ها: `jupyter book build --html --execute`.

## انتشار خودکار روی GitHub Pages

هر push به `main` توسط `.github/workflows/deploy.yml` بیلد و منتشر می‌شود
(`jupyter-book` را با npm نصب می‌کند، `jupyter-book build --html` را با
`BASE_URL=/<نام-مخزن>` اجرا می‌کند و روی Pages منتشر می‌کند). پیشرفت را در
زبانه‌ی **Actions** ببینید. در *Settings → Pages* گزینه‌ی **Source** باید
همیشه **GitHub Actions** باشد.

Pull Requestها با `.github/workflows/build-check.yml` بررسی می‌شوند؛ همان بیلد
را بدون انتشار اجرا می‌کند.

## اجرای محلی کتاب

با بازسازی خودکار هنگام ویرایش:

```bash
env -u PORT jupyter book start     # http://localhost:3000
```

یا سرو کردن سایت استاتیکِ ساخته‌شده:

```bash
cd _build/html
python3 -m http.server 8811 --bind 127.0.0.1
```

سایت مبتنی بر JavaScript است: همیشه آن را از طریق وب‌سرور باز کنید، نه با
دوبار کلیک روی `index.html`.

## متوقف کردن سرورهای محلی

سرور را با `Ctrl-C` در همان ترمینال متوقف کنید. سرورهای پس‌زمینه:

```bash
ss -tlnp | grep -E ':(3000|3001|8811)'   # پیدا کردن پورت‌ها و PIDها
kill <PID>                               # توقف نرم؛ اگر نشد: kill -9
fuser -k 3000/tcp                        # یا آزاد کردن مستقیم یک پورت
pkill -f "book-theme/server.js"          # سرور باقی‌مانده‌ی `jupyter book start`
```

## روش دستی انتشار روی GitHub Pages

```bash
BASE_URL=/fundamentals-of-programming/ env -u PORT jupyter book build --html
pip install ghp-import
ghp-import -n -p -f ./_build/html
```

## خروجی PDF (اختیاری)

یک export با `format: pdf` به `myst.yml` اضافه کنید و
`env -u PORT jupyter book build --pdf` را اجرا کنید (خروجی PDF در نسخه‌ی ۲ از
طریق Typst انجام می‌شود).

## مثال‌های C و فایل‌های تولیدشده

بعضی نوت‌بوک‌ها هنگام اجرا فایل‌های `src/*.c` را می‌سازند و در `bin/` کامپایل
می‌کنند. پوشه‌ی `src/` در گیت نگه داشته می‌شود؛ پوشه‌ی `bin/` (فایل‌های اجرایی
کامپایل‌شده) خروجی بیلد است و نادیده گرفته می‌شود.
