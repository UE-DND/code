/**********************************

请使用指针的方法编写程序，程序的功能是从键盘输入一个字符串(字符串长度小于100)，删除其中的字母a后输出。例如，输入字符串abcaca，输出bcc。

输入样例:
abcaca

输出样例:
bcc

***********************************/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);

    char *p = str;
    while (*p!= '\0')
    {
        if (*p == 'a')
        {
            *p = *(p + 1);  // 将a替换为下一个字符
        } else {
            p++;
        }
    }
    printf("%s", str);
    return 0;
}