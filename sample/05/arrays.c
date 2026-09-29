#include <stdio.h>
enum { COUNT = 5 };
int sum_array(const int a[], int n);
int main(void)
{
    int scores[COUNT] = {72, 85, 60, 93, 80};
    int total = sum_array(scores, COUNT);
    printf("total=%d mean=%.1f\n", total, total / 5.0);
    int table[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int row = 0; row < 2; ++row) {
        int sum = 0;
        for (int col = 0; col < 3; ++col) {
            sum += table[row][col];
        }
        printf("row %d: %d\n", row, sum);
    }
    return 0;
}
int sum_array(const int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return sum;
}
