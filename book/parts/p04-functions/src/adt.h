
/* adt.h - «جعبهٔ سیاه»: رابط Stack و Queue برای اعداد صحیح.
   فعلاً فقط «رابط» (نام و رفتار توابع) مهم است. درون آن آرایه به کار رفته که در بخش پنجم می‌آموزید. */
#ifndef ADT_H
#define ADT_H
#define ADT_CAP (1 << 22)

/* ---------- Stack (LIFO) ---------- */
static int s_data[ADT_CAP];
static int s_top = 0, s_max = 0;                 /* s_max: بیشینهٔ اندازه (برای اندازه‌گیری) */
static inline void s_push(int x) { s_data[s_top++] = x; if (s_top > s_max) s_max = s_top; }
static inline int  s_pop(void)   { return s_data[--s_top]; }
static inline int  s_empty(void) { return s_top == 0; }

/* ---------- Queue (FIFO)، حلقوی ---------- */
static int q_data[ADT_CAP];
static int q_head = 0, q_size = 0, q_max = 0;    /* q_max: بیشینهٔ اندازه (برای اندازه‌گیری) */
static inline void q_push(int x) { q_data[(q_head + q_size++) % ADT_CAP] = x; if (q_size > q_max) q_max = q_size; }
static inline int  q_pop(void)   { int x = q_data[q_head]; q_head = (q_head + 1) % ADT_CAP; q_size--; return x; }
static inline int  q_empty(void) { return q_size == 0; }
#endif
