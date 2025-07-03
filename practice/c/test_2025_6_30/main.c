#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp = fopen("../test.txt", "w");
    if (fp == NULL) {
        printf("打开文件失败！\n");
        return 1; 
    }
    
    for (int i = 0; i < 10000; ++i) {
        if (fputs("Hello World!\n", fp) == EOF) { 
            printf("写入文件失败！\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    printf("文件写入成功！\n");
    return 0;
}
