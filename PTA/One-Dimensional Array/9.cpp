/**********************************

给定一批整数，分析每个整数的每一位数字，求出现次数最多的个位数字。
例如给定3个整数1234、2345、3456，其中出现最多次数的数字是3和4，均出现了3次。

输入格式：
输入在第1行中给出正整数N（≤1000），
在第二行中给出N个不超过整型范围的非负整数，数字间以空格分隔。 

输出格式：
在一行中按格式“M: n1 n2 ...”输出，
其中M是最大次数，n1、n2、……为出现次数最多的个位数字，按从小到大的顺序排列。
数字间以空格分隔，但末尾不得有多余空格。

输入样例：
3
1234 2345 3456

输出样例：
3: 3 4

***********************************/

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int count[20] = {0};
    for (int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);
        count[score]++;
    }
    int turned_scores[101];  
    //这道题直接引用了第二题的功能，先排序了再删，懒得重新写
    //turned_scores[n]存储排序后的分数

    int k = 0;  // 用于 turned_scores 的下标
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j < count[i]; j++) {
            turned_scores[k++] = i;  // 将分数升序存储到turned_scores中
        }
    }

    //以下部分涉及指针，还没学，看不懂就算了

    int j = 0;  //慢指针，指向已去重的数组
    for (int i = 1; i < k; i++) {
        if (turned_scores[i]!= turned_scores[j]) {
            j++;
            turned_scores[j] = turned_scores[i];  //将当前元素放到去重数组的下一个位置
        }
    }

    int first = 1;
    for (int i = 0; i <= j; i++) {  //这里就体现了只输出到j的位置
        if (first) {
            printf("%d", turned_scores[i]);
            first = 0;
        } else {
            printf(" %d", turned_scores[i]);
        }
    }
    printf("\n");
}