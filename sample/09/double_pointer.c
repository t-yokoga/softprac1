#include <stdio.h>
int find_max(int a[], int n, int **out)
{
    *out = NULL;
    if (n <= 0) { return 0; }
    int *best = &a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > *best) { best = &a[i]; }
    }
    *out = best;
    return 1;
}
int main(void)
{
    int a[] = {7, 12, 4};
    int *answer = NULL;
    if (find_max(a, 3, &answer)) {
        printf("max=%d\n", *answer);
        *answer = 99;
    }
    printf("a[1]=%d\n", a[1]);
    const char *names[] = {"red", "green", "blue"};
    const char *temp = names[0];
    names[0] = names[2];
    names[2] = temp;
    for (int i = 0; i < 3; ++i) { printf("%s\n", names[i]); }
    return 0;
}
