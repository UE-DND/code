/**********************************

输入10个正整数到a数组中，对a[10]数组中的素数升序排序。

输入格式:
在一行中输入10个用空格间隔的正整数，数据之间只能各用1个空格间隔。

输出格式:
在一行中输出升序的素数序列，每个数输出占4列列宽。

输入样例:
9 5 1 6 4 8 7 2 9 11

输出样例:
   2   5   7  11

***********************************/

//由于输入数据长度未知，即素数的长度未知，所以不能使用计数排序
#include <stdio.h>
#include <math.h>

isPrime(int n) {
   if (n == 1) {
      return 0;
   }
   for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) {
         return 0;
      }
   }
   return 1;
}

int main(void) {
   int a[10], prime[10], count = 0;

   for (int i = 0; i < 10; i++)
   {
      scanf("%d", &a[i]);
      if (isPrime(a[i])) {
         prime[count] = a[i];
         count++;
      }
   }
   
   //这里使用冒泡排序
   for (int i = 0; i < count; i++) {
      for (int j = i + 1; j < count; j++) {
         if (prime[i] > prime[j]) {
            int temp = prime[i];
            prime[i] = prime[j];
            prime[j] = temp;
         }
      }
   }

   for (int i = 0; i < count; i++) {
      printf("%4d", prime[i]);
   }

return 0;
}
