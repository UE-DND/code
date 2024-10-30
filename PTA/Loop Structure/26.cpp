/**********************************

判断一个int型整数是否是2的n次方，如果是则输出n值，否则输出NO!。

输入格式:
输入若干个整数，以空格或换行间隔。

输出格式:
对每一个整数，在一行中输出n值或“NO！”。

输入样例1:
2 8 15

输出样例1:
在这里给出相应的输出。例如：

1
3
No!

输入样例2
-8
0

输出样例2:
在这里给出相应的输出。例如：

3
No!

***********************************/

#include <stdio.h>

int isSquare(int num) {
    int n = 0;
    if (num <= 0) return -1;
    if (num == 1) return 0;
    while (num > 1) {
        if (num % 2 != 0) return -1;
        num /= 2;
        n++;
    }
    return n;
}

int main() {
    int num;
    int end = 1;
    while (scanf("%d", &num) != EOF) {
        if (num < 0)
        {
            num = -num;
        }
        int result = isSquare(num);
        if (result >= 0) {
            if (!end) printf("\n");
            printf("%d", result);
            end = 0;
        } else {
            if (!end) printf("\n");
            printf("No!");
            end = 0;
        }
    }
    return 0;
}