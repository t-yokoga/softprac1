#include <stdio.h>
unsigned long long factorial(unsigned int n)
{
    if (n == 0) { return 1; }
    return n * factorial(n - 1);
}
unsigned int gcd(unsigned int a, unsigned int b)
{
    if (b == 0) { return a; }
    return gcd(b, a % b);
}
int main(void)
{
    unsigned int n = 5;
    if (n > 20) {
        fprintf(stderr, "n must be 0..20\n");
        return 1;
    }
    printf("%u! = %llu\n", n, factorial(n));
    printf("gcd=%u\n", gcd(48, 18));
    return 0;
}
