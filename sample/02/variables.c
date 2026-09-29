#include <stdio.h>
#include <limits.h>
int main(void)
{
    int height = 10;
    int width = 5;
    int area = height * width;
    double price = 120.5;
    char grade = 'A';
    printf("height=%d width=%d area=%d\n", height, width, area);
    height = 12;
    printf("height=%d area=%d\n", height, area);
    printf("price=%.2f grade=%c\n", price, grade);
    printf("sizeof(int)=%zu sizeof(double)=%zu\n", sizeof(int), sizeof(double));
    printf("CHAR_BIT=%d INT_MIN=%d INT_MAX=%d\n", CHAR_BIT, INT_MIN, INT_MAX);
    printf("height address=%p\n", (void *)&height);
    return 0;
}
