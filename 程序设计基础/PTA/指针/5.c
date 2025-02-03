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

void move(int *a) {
    int i, j;
    int temp;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {  // 只交换上三角部分
            temp = *(a + i * 3 + j);
            *(a + i * 3 + j) = *(a + j * 3 + i);
            *(a + j * 3 + i) = temp;
        }
    }
}

/**********************
如何通过指针操作二维数组
在二维数组中：
a[i][j] 的地址可以表示为：
&a[i][j] = a + i * 列数 + j

为什么 i 要 * 列数？
二维数组在内存中是按行优先存储的，可以看作是一个连续的 一维数组。
如a[3][3]在内存中的布局为
a[0][0], a[0][1], a[0][2], a[1][0], a[1][1], a[1][2], a[2][0], a[2][1], a[2][2]
计算第 i 行的起始位置，需要跳过前 i 行的所有元素，即偏移量是 i × 列数
***********************/

/**********************不使用指针的写法
void move(int a[3][3]) {
    int i, j, temp;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++)
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}
**********************/

int main(void) {
    int i, j, a[3][3];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    move(&a[0][0]);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d", a[i][j]);
            // 最后一个元素后面没有空格
            if (j != 2) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}