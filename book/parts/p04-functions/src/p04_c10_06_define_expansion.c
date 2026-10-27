
#define SQUARE_BAD(x)  x * x
#define SQUARE(x)      ((x) * (x))
#define DOUBLE_BAD(x)  x + x
#define DOUBLE(x)      ((x) + (x))

int r1 = SQUARE_BAD(3 + 1);
int r2 = SQUARE(3 + 1);
int r3 = 3 * DOUBLE_BAD(2);
int r4 = 3 * DOUBLE(2);
