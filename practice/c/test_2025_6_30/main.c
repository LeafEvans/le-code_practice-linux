#include <stdio.h>
#include <stdlib.h>
#define N 10000

typedef struct {
    int number;     // 学号
    char name[30];  // 姓名
    char major[30]; // 专业
} StudentInfo;

int main(void) {
    FILE* fp = fopen("../students.info", "w"); // 以“写”方式打开文件

    if (fp == NULL) {
        printf("打开文件失败！");
        exit(0);
    }

    StudentInfo student[N];       // 用数组保存 N 个学生的信息
    for (int i = 0; i < N; ++i) { // 生存 N 个学生的信息
        student[i].name[0] = '?';
        student[i].number = i;
        student[i].major[0] = '?';
    }

    // 将 N 个学生的信息写入文件
    fwrite(student, sizeof(StudentInfo), N, fp);
    fclose(fp);

    return 0;
}
