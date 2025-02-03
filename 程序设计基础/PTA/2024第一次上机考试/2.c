/**********************************

统计给定的n个数中，负数、零和正数的个数

输入格式:
输入数据有多组，每组占一行，每行的第一个数是整数n（n<100），表示需要统计的数值的个数，然后是n个实数；
如果n=0，则表示输入结束，该行不做处理。 

输出格式:
对于每组输入数据，输出一行a,b和c，分别表示给定的数据中负数、零和正数的个数。

输入样例:
在这里给出一组输入。例如：
6 0 1 2 3 -1 0
5 1 2 3 4 0.5
0

输出样例:
在这里给出相应的输出。例如：
1 2 3
0 0 5

***********************************/

#include <stdio.h>

int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        float a[n];
        int count1 = 0, count2 = 0, count3 = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%f", &a[i]);
            if (a[i] < 0)
            {
                count1++;
            }
            else if (a[i] == 0)
            {
                count2++;
            }
            else
            {
                count3++;
            }
        }

        printf("%d %d %d\n", count1, count2, count3);
    }
    return 0;
}
