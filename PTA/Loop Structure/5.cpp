/**********************************

一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数 N（1<N<2^31）。

输出格式：
首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1*因子2*……*因子k 的格式输出最小的连续因子序列，其中因子按递增顺序输出，1 不算在内。

输入样例：
630

输出样例：
3
5*6*7

***********************************/

#include <stdio.h>
int main() {
    long long N;
    scanf("%lld", &N);  //输入
    int max_factor_length = 0, start = 0;  //start是当前最长连续因子的起始值

    // 枚举连续因子的起始值
    for (int i = 2; i <= N; ++i) {
        if (N % i == 0) {  //N能被i整除，那么i就是N的因子
            int length = 1;
            long long product = i;
            while (product <= N) {
                product *= (i + length);  //i在外层循环更新，所以下一个数是i+length。
                if (N % product == 0) {  //检查下一个数是不是N的因子
                    ++length;
                } else {
                    break;
                }
            }
            if (length > max_factor_length) {  //更新最长因子长度
                max_factor_length = length;
                start = i;  //更新最长因子的起始值
            }
        }
    }

    printf("%d\n", max_factor_length);  //输出最长因子长度
    for (int i = 0; i < max_factor_length; ++i) {
        if (i > 0) printf("*");  //每隔一个数输出*
        printf("%d", start + i);  //输出所有因子
    }
    printf("\n");

return 0;
}