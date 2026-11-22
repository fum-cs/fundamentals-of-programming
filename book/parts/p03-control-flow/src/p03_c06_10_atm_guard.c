#include <stdio.h>

int main(void)
{
    int balance = 1000, limit = 500, amount;

    if (scanf("%d", &amount) != 1) {
        return 1;
    }

    if (amount <= 0) {
        printf("Denied: amount must be positive\n");
    } else if (amount % 10 != 0) {
        printf("Denied: amount must be a multiple of 10\n");
    } else if (amount > balance) {
        printf("Denied: insufficient balance\n");
    } else if (amount > limit) {
        printf("Denied: above the daily limit\n");
    } else {
        balance -= amount;
        printf("OK: withdrew %d, balance = %d\n", amount, balance);
    }

    return 0;
}
