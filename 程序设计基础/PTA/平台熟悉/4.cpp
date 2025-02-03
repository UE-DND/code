/**********************************

/**********************************

编写程序：从键盘任意输入三个整数，计算并输出它们的平均值，以及这三个整数的乘积。平均值的小数点后面保留2位输出。

输入格式:
输入：在一行中输入3个绝对值不超过1000的非0整数。

输出格式:
对每一组输入，在一行中输出3个整数的平均值，和3个整数的乘积，其间用一个空格分开。

输入样例:
例如：
4 5 7

输出样例:
在这里给出相应的输出。例如：
5.33 140

**********************************/

#include <stdio.h>

int main() {
    int n, d1, d2, d3, d4;
    scanf("%d",&n);
    d1 = n % 10;
    d2 =(n % 100) / 10;
    d3 =(n % 1000) / 100;
    d4 = n / 1000;
    printf("%d is changed to:%d%d%d%d",n, d1, d2, d3, d4);
return 0;
}
