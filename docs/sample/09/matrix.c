#include <stdio.h>
enum { COLS = 3 };
int matrix_sum(int a[][COLS], int rows)
{
    int sum = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < COLS; ++c) {
            sum += a[r][c];
        }
    }
    return sum;
}
int main(void)
{
    int a[2][COLS] = {{1, 2, 3}, {4, 5, 6}};
    int (*row)[COLS] = a;
    printf("%d %d\n", row[0][2], row[1][2]);
    printf("sum=%d\n", matrix_sum(a, 2));
    return 0;
}
