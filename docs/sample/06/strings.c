#include <stdio.h>
#include <string.h>
int main(void)
{
    char word[16] = "cat";
    char copy[16] = {0};
    size_t length = strlen(word);
    if (length < sizeof copy) {
        for (size_t i = 0; i <= length; ++i) {
            copy[i] = word[i];
        }
    }
    word[0] = 'C';
    printf("%s %s\n", word, copy);
    printf("length=%zu capacity=%zu\n", strlen(word), sizeof word);
    printf("equal=%d\n", strcmp(word, copy) == 0);
    int total = 7, count = 2;
    printf("mean=%.1f\n", (double)total / count);
    return 0;
}
