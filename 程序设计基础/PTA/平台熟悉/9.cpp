/**********************************

任意输入两个浮点数，交换它们的值，输出交换以后的结果。
输入格式:
输入在一行中给出2个绝对值不超过1000的浮点数，其间用空格分开。

输出格式:
对每一组输入，在一行中输出交换后的两个数，小数点后面保留2位小数。

输入样例:
在这里给出一组输入。例如：
2.4 5.6

输出样例:
在这里给出相应的输出。例如：
After exchange:x1=5.60,x2=2.40

**********************************/

#include <stdio.h>
int main() {
    float num1, num2, temp;
    scanf("%f %f", &num1, &num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("After exchange:x1=%.2f,x2=%.2f", num1, num2);
return 0;
}