# الگوی ساخت یک بخش جدید

۱. پوشه‌ی `book/parts/pNN-topic/` را بسازید (و در صورت نیاز `src/` و `images/`).
۲. فایل `part-xxx.ipynb` را بسازید و سلول اول (Markdown) آن را مطابق زیر پر کنید.
۳. متن بخش را در `part-xxx.md` نیز نگه دارید و هماهنگ بمانید.
۴. بخش را به `myst.yml` ریشه اضافه کنید:

```yaml
    - title: بخش نهم | عنوان بخش
      children:
        - file: book/parts/p09-topic/part-nine.ipynb
```

## سلول اول نوت‌بوک (front matter)

```markdown
---
title: "بخش نهم: عنوان بخش"
authors:
  - name: دکتر محمود امین طوسی
    affiliations:
      - institution: دانشگاه فردوسی مشهد
        department: گروه علوم کامپیوتر
        country: ایران
    email: m.amintoosi@gmail.com
    github: mamintoosi          # فقط نام کاربری، نه URL
    url: https://mamintoosi.github.io/
    roles: [supervision]
  - name: نام و نام خانوادگی
    affiliations:
      - institution: دانشگاه فردوسی مشهد
        department: گروه علوم کامپیوتر
    github: your-username
    roles: [writing, editing]
---
```

نقش‌های مجاز (`roles`) از طبقه‌بندی CRediT هستند، از جمله: `conceptualization`،
`methodology`، `writing`، `editing`، `validation`، `visualization`، `supervision`.

## اسکلت متن بخش

```markdown
# بخش نهم : عنوان بخش

## مقدمه

(انگیزه + نقشه‌ی کلی بخش)

---

## فصل N : Title

### N.1 عنوان زیربخش

(توضیح + مثال)

#### تمرین درون فصل N.1

**نوع تمرین: Predict the Output**

(صورت تمرین)

### N.k تمرین

(تمرین‌های پایان فصل)

---

## جمع‌بندی بخش

### فصل N: عنوان
(خلاصه)

### اشتباه‌های رایج
(فهرست)

### بخش بعد
(معرفی بخش بعد)
```

برای جزئیات نگارش و قالب‌بندی به [style-guide.md](style-guide.md) نگاه کنید.
