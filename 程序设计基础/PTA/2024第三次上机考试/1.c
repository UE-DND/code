/**********************************

��ָ��ķ�ʽ����ĳ���ַ����г��ֵ��ض��ַ�ɾȥ��Ȼ������µ��ַ�����

�����ʽ:
��������һ��������T����ʾ�������ݵ�������Ȼ����T��������ݡ�
ÿ�������������һ���ַ���s��һ���ǿո��ַ�t������s�ĳ��Ȳ�����100����ֻ����Ӣ����ĸ��

�����ʽ:
����ÿ����ԣ���ɾ��t���µõ����ִ�������������ɾ�գ������NULL��

��������:
2
eeidliecielpvu i
ecdssnepffnofdoenci e
�������:
eedlecelpvu
cdssnpffnofdonci

***********************************/

#include <stdio.h>
#include <string.h>

int main() {
    int  T;
    scanf("%d", &T);

    while (T--) {
        char s[1001], t;
        scanf("%s %c", s, &t);

        char* write = s, * read = s;
        while (*read) {
            if (*read != t) {
                *write = *read;
                write++;
            } read++;
        }
        *write = '\0';

        if (write == s) {
            printf("NULL\n");
        }
        else {
            printf("%s\n", s);
        }
    }
    return 0;
}