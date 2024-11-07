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
#include <stdint.h>

#define MAX_SIZE 101  // 假设数组元素的值不超过100

void remove_duplicates(int arr[], int n, int result[], int* result_size) {
    int count[MAX_SIZE] = {0};  // 统计每个元素出现的次数
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 去重并按升序排列
    *result_size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] > 0) {
            result[*result_size] = i;
            (*result_size)++;
        }
    }
}

void find_unique_elements(int arr1[], int size1, int arr2[], int size2) {
    int unique[2 * MAX_SIZE];  // 用于存储不重复的元素
    int idx = 0;

    // 查找arr1中不在arr2中的元素
    for (int i = 0; i < size1; i++) {
        int found = 0;
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[idx++] = arr1[i];
        }
    }

    // 查找arr2中不在arr1中的元素
    for (int i = 0; i < size2; i++) {
        int found = 0;
        for (int j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique[idx++] = arr2[i];
        }
    }

    // 输出结果
    int first = 1;
    for (int i = 0; i < idx; i++) {
        if (first) {
            printf("%d", unique[i]);
            first = 0;
        } else {
            printf(" %d", unique[i]);
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;
    
    scanf("%d", &n1);
    int arr1[n1];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // 去重处理
    int result1[MAX_SIZE], result_size1;
    remove_duplicates(arr1, n1, result1, &result_size1);
    
    int result2[MAX_SIZE], result_size2;
    remove_duplicates(arr2, n2, result2, &result_size2);
    
    // 查找两个数组中不在另一个数组中的元素
    find_unique_elements(result1, result_size1, result2, result_size2);

    return 0;
}



#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int count[101] = {0};
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