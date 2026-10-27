#include <stdio.h>

#define CAP 4

static int error = 0;                 /* set to 1 on a misuse (overflow / underflow) */

/* ---------- Stack: array + top index ---------- */
static int st[CAP];
static int top = 0;                   /* number of stored elements */

void stack_push(int x)
{
    if (top == CAP) { error = 1; return; }      /* overflow  */
    st[top++] = x;
}

int stack_pop(void)
{
    if (top == 0) { error = 1; return -1; }     /* underflow */
    return st[--top];
}

/* ---------- Queue: circular array + head index + size ---------- */
static int qu[CAP];
static int head = 0, size = 0;

void queue_push(int x)
{
    if (size == CAP) { error = 1; return; }     /* overflow  */
    qu[(head + size) % CAP] = x;                /* wrap around the end */
    size++;
}

int queue_pop(void)
{
    if (size == 0) { error = 1; return -1; }    /* underflow */
    int x = qu[head];
    head = (head + 1) % CAP;
    size--;
    return x;
}

int main(void)
{
    /* the queue wraps around: positions are reused */
    for (int x = 1; x <= 4; x++) queue_push(x);
    int first = queue_pop();
    int second = queue_pop();
    printf("dequeue: %d %d\n", first, second);
    queue_push(5);
    queue_push(6);                               /* stored in the freed cells 0 and 1 */
    printf("array  : %d %d %d %d   (head = %d, size = %d)\n",
           qu[0], qu[1], qu[2], qu[3], head, size);
    printf("rest   : ");
    while (size > 0) printf("%d ", queue_pop());
    printf("\n\n");

    /* misuse is detected instead of silently corrupting memory */
    for (int x = 1; x <= 5; x++) stack_push(x);  /* the 5th push overflows */
    printf("after 5 pushes: error = %d, top = %d\n", error, top);

    error = 0;
    while (top > 0) stack_pop();
    stack_pop();                                  /* underflow */
    printf("after extra pop: error = %d\n", error);
    return 0;
}
