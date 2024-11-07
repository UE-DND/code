/**********************************

给定两个整型数组，本题要求找出不是两者共有的元素。

输入格式:
输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。 

输出格式:
在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。 

输入样例:
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1

输出样例:
3 5 -15 6 4 1

***********************************/

/*第一版逻辑是有问题的，不能合并两个数组再找不重复的，否则数组1内若有重复数字，且这个数字在数组2没有，就不会输出。
#include <stdio.h>
#include <stdint.h>

#define Max_Range 200001
#define Offset 100000  //设定偏移量，用于处理负数

int main() {
    int64_t N1, N2;

    scanf("%lld", &N1);
    int64_t arr1[N1];
    for (int64_t i = 0; i < N1; i++) {
        scanf("%lld", &arr1[i]);
    }
    scanf("%lld", &N2);
    int64_t arr2[N2];
    for (int64_t i = 0; i < N2; i++) {
        scanf("%lld", &arr2[i]);
    }

    //合并两个数组
    int64_t combine[N1 + N2];
    for (int64_t i = 0; i < N1; i++) {
        combine[i] = arr1[i];
    }
    for (int64_t i = 0; i < N2; i++) {
        combine[N1 + i] = arr2[i];
    }

    //标记
    int64_t count[Max_Range] = {0};
    for (int64_t i = 0; i < N1 + N2; i++) {
        count[combine[i] + Offset]++;
    }

    for (int64_t i = 0; i < N1 + N2; i++) {
        if (count[combine[i] + Offset] == 1) {  //只出现一次的数字
            printf("%lld ", combine[i]);
            count[combine[i] + Offset] = 0;  //计数器归为0，避免重复输出
        }
    }

    printf("\n");
    
    return 0;
}
*/



