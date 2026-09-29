#include <stdio.h>
int main(void)
{
    int a = 7, b = 2;
    printf("quotient=%d remainder=%d real=%.1f\n", a / b, a % b, a / 2.0);
    int year = 2000;
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    printf("leap=%d\n", leap);
    unsigned int flags = 5u;
    flags |= 1u << 1;
    printf("set=%u\n", flags);
    flags &= ~(1u << 0);
    printf("clear=%u\n", flags);
    flags ^= 1u << 2;
    printf("toggle=%u\n", flags);
    return 0;
}
