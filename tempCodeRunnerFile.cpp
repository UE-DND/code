#include <stdio.h>
int num;
int main() {   
    scanf("%d",&num)
    if (num == 1)
    {
        printf("星期一 8节课");
    }
    else if (num == 2)
    {
        printf("星期二 10节课");
    }
    else if (num == 3)
    {
        printf("星期三 6节课");
    }
    else if (num == 4)
    {
        printf("星期四 8节课");
    }
    else if (num == 5)
    {
        printf("星期五 6节课");
    }
    else {
        printf("今天没有课，可以好好休息一下啦！")
    }
return 0;
}