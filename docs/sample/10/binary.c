#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    const unsigned char data[] = {0x41, 0x00, 0x42, 0x0A};
    FILE *fp = fopen("bytes.bin", "wb");
    if (fp == NULL) { perror("fopen"); return 1; }
    size_t written = fwrite(data, 1, sizeof data, fp);
    int closed = fclose(fp);
    if (written != sizeof data || closed == EOF) {
        fprintf(stderr, "write error\n");
        return 1;
    }
    fp = fopen("bytes.bin", "rb");
    if (fp == NULL) { perror("fopen"); return 1; }
    unsigned char buffer[16];
    size_t n = fread(buffer, 1, sizeof buffer, fp);
    int failed = ferror(fp);
    closed = fclose(fp);
    if (failed || closed == EOF) {
        fprintf(stderr, "read error\n");
        return 1;
    }
    for (size_t i = 0; i < n; ++i) {
        printf("%02X%s", (unsigned int)buffer[i], i + 1 == n ? "\n" : " ");
    }
    return 0;
}
