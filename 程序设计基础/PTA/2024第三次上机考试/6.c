/**********************************

�ú�����ָ�뽫������ĸ�ַ����ĵ�һ����ĸ��ɴ�д��ĸ��������ĸ���Сд��ĸ��
��main�����н����ַ��������룬�ı����ַ��������Ҳ��main������ʵ�֡�

��������:
���������һ�����롣���磺

CHENGDU UNIVERSITY OF INFORMATION TECHNOLOGY 1951-2023

�������:
�����������Ӧ����������磺

Chengdu university of information technology 1951-2023

***********************************/

#include <stdio.h>

void change(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
        i++;
    }
}

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    change(s);
    s[0] = s[0] - 32;
    printf("%s", s);
    return 0;
}