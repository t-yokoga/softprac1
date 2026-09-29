#include <stdio.h>
int main(void)
{
    int score = 75;
    if (score < 0 || score > 100) {
        printf("invalid\n");
    } else if (score >= 60) {
        printf("pass\n");
    } else {
        printf("retry\n");
    }
    int sum = 0;
    for (int i = 1; i <= 10; ++i) {
        sum += i;
    }
    printf("sum=%d\n", sum);
    int power = 1;
    while (power < 100) {
        printf("%d ", power);
        power *= 2;
    }
    printf("\n");
    return 0;
}
