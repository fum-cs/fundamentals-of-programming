
#include <stdio.h>

int main(void)
{
    /* A = {0, 1, ..., 7}  و  f(x) = x^2 mod 8 */
    printf("graph of f = { ");
    for (int x = 0; x < 8; x++) {
        printf("(%d,%d) ", x, (x * x) % 8);
    }
    printf("}\n");

    /* برد: تعداد y هایی که حداقل یک x به آن‌ها می‌رسد */
    int image_size = 0;
    for (int y = 0; y < 8; y++) {
        int reached = 0;
        for (int x = 0; x < 8; x++) {
            if ((x * x) % 8 == y) reached = 1;
        }
        image_size += reached;
    }

    /* یک‌به‌یک؟ آیا دو x متفاوت با خروجی یکسان وجود دارد؟ */
    int injective = 1;
    for (int x1 = 0; x1 < 8; x1++)
        for (int x2 = x1 + 1; x2 < 8; x2++)
            if ((x1 * x1) % 8 == (x2 * x2) % 8) injective = 0;

    printf("image size  = %d (codomain size = 8)\n", image_size);
    printf("injective?    %s\n", injective ? "yes" : "no");
    printf("surjective?   %s\n", image_size == 8 ? "yes" : "no");
    return 0;
}
