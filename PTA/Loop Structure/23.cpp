/**********************************

有n匹马要驮n担货，大马驮5担，中马驮3担，两匹小马驮1担，
问有几种驮担方案? （各种马的数量可以为0）

输入格式:
首先输入一个整数T，表示测试数据的组数，
然后是T组测试数据。每组测试数据输入一个正整数n（8≤n≤10000）。

输出格式:
对于每组测试，输出n匹马驮n担货的方案总数。

输入样例:
1
20

输出样例:
1

***********************************/

#include <stdio.h>

int main() {
    int T, n;
    scanf("%d %d", &T, &n);

    for (int i = 0; i < T; i++) {
        int count = 0;

        for (int big_horse = 0; big_horse <= n / 5; big_horse++) {
            for (int middle_horse = 0; middle_horse <= (n - big_horse * 5) / 3; middle_horse++) {
                int remaining = n - big_horse * 5 - middle_horse * 3;
                if (remaining >= 0 && remaining % 2 == 0) {  //确保小马数量为非负整数

                    int small_horse = remaining / 2;
                    if (big_horse + middle_horse + small_horse == n) {
                        count++;
                    }
                }
            }
        }
        printf("%d\n", count);
    }
return 0;
}
