/**********************************

键盘输入1个正的整数A，如果A是3的倍数但不是5的倍数，则输出A除以5的余数。如果A是5的倍数但是不是3的倍数，则输出A除以3的余数。如果A既不是5的倍数但也不是3的倍数，输出A除以15的余数，其他情况没有输出

输入格式:
1个正整数

输出格式:
如果是3的倍数但不是5的倍数，则输出A除以5的余数。
如果A是5的倍数但是不是3的倍数，则输出A除以3的余数。
如果A既不是5的倍数但也不是3的倍数，输出A除以15的余数。
如果A不是正整数，没有任何输出。

输入样例:
18 

输出样例:
3

***********************************/

#include <stdio.h>

int main() {
    int A;
    scanf("%d", &A);

    if (A <= 0) {
        return 0;
    }

    if (A % 3 == 0 && A % 5 != 0) {
        printf("%d", A % 5);
    } else if (A % 5 == 0 && A % 3 != 0) {
        printf("%d", A % 3);
    } else if (A % 3 != 0 && A % 5 != 0) {
        printf("%d", A % 15);
    }

return 0;
}
