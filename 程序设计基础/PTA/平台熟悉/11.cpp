/**********************************

摄氏温度C与华氏温度F的转换公式是：F=(9/5)C+32。编写程序，任意输入摄氏温度C，将其转换成华氏温度F，输出转换后的华氏温度。

输入格式:
输入在一行中给出1个绝对值不超过1000的整型摄氏温度值。

输出格式:
对每一组输入，在一行中输出华氏温度值，小数点后面保留2位。

输入样例:
在这里给出一组输入。例如：
32

输出样例:
在这里给出相应
f=89.60

**********************************/

#include <stdio.h>

int main() {
    int C;
    while (scanf("%d", &C) == 1) {
        double F = (9.0 / 5.0) * C + 32;
        printf("f=%.2f", F);
    }
return 0;
}
