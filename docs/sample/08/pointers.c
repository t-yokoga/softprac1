#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int sum_array(const int *a, int n)
{
    int total = 0;
    for (int i = 0; i < n; ++i) {
        total += *(a + i);
    }
    return total;
}
int main(void)
{
    int x = 3, y = 8;
    int *p = &x;
    *p = 5;
    swap(&x, &y);
    printf("x=%d y=%d\n", x, y);
    int values[] = {10, 20, 30};
    printf("sum=%d\n", sum_array(values, 3));
    const char *word = "cat";
    printf("%c %s\n", *word, word + 1);
    return 0;
}
