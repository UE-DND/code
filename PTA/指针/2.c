/**********************************

用指针实现将一个3*3的整型矩阵转置。

要求定义并调用函数void move(int *pointer)，实现上述矩阵转置的功能。

输出格式：每行数据之间以空格分隔，最后一个数据后面没有空格

输入样例:
1 2 3
4 5 6
7 8 9

输出样例:
1 4 7
2 5 8
3 6 9

***********************************/

#include <stdio.h>

void move(int *pointer) {
    int i, j;
    int temp;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            temp = *(pointer + i * 3 + j);
            *(pointer + i * 3 + j) = *(pointer + j * 3 + i);
            *(pointer + j * 3 + i) = temp;
        }
    }
    return;
}

int main(void) {
    int i, j, a[3][3];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    move(a[0]);
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d", a[i][j]);
            if (j!= 2) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}