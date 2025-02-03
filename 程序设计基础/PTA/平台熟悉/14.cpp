/**********************************

输入三个数字字符（字符‘1’~字符‘9’），输出由它们组成的一个整数。例如：输入‘2’、‘5’、‘7’，输出整数257。
输入格式:
输入在一行中给出3个字符，中间用1个空格分开。

输出格式:
在一行中输出转换后的1个整数。

输入样例:
2 5 7

输出样例:
257

**********************************/

#include <stdio.h>

int main() {
    char a, b, c;
    while (scanf(" %c %c %c", &a, &b, &c) == 3) {
        int number = (a - '0') * 100 + (b - '0') * 10 + (c - '0');
        printf("%d", number);
    }
return 0;
}
