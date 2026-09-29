#include <stdio.h>
int sum_to(int n)
{
    printf("enter %d\n", n);
    if (n == 0) {
        printf("leave 0: 0\n");
        return 0;
    }
    int result = n + sum_to(n - 1);
    printf("leave %d: %d\n", n, result);
    return result;
}
int main(void)
{
    int n = 3;
    if (n < 0 || n > 100) {
        fputs("n must be 0..100\n", stderr);
        return 1;
    }
    int result = sum_to(n);
    printf("sum=%d\n", result);
    return 0;
}
