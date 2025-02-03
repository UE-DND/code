/**********************************

输出1000以内所有各位数字之和为n的正整数，例如：如果输入的n是6，那么，105的各位数字之和1+0+5=6, 123的各位数字之和1+2+3=6，两者都满足要求。每行输出6列，每个整数占8位宽度右对齐。

输入格式:
从键盘输入整数n的值。

输出格式:
每行输出6列，每个整数占8位宽度右对齐。如果最后一行不足6列，也需要换行。

输入样例:
在这里给出一组输入。例如：
6

输出样例:
在这里给出相应的输出。例如：

       6      15      24      33      42      51
      60     105     114     123     132     141
     150     204     213     222     231     240
     303     312     321     330     402     411
     420     501     510     600

***********************************/

#include<stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int count = 0;
    for(int i = 1; i <= 1000; i++)
    {
        int sum = 0;
        int temp = i;
        while(temp)
        {
            sum += temp % 10;  // 取最后一位累加
            temp /= 10;  // 去掉最后一位
        }
        if(sum == n)
        {
            printf("%8d", i);
            count++;
            if(count % 6 == 0)
            {
                printf("\n");  // 每行输出6列
            }
        }
    }
    if(count % 6!= 0)
    {
        printf("\n");  // 不足6列也要换行
    }
    return 0;
}