/**********************************

编程序实现如下功能：
从键盘输入一个包含小数的小写金额（整数部分不超过7位），将其转换为汉字大写金额，最后输出结果。

提示：不需要对0进行特殊处理。

输入格式:
输入一个包含小数的小写金额（整数部分不超过7位，小数部分不超过2位）。

输出格式:
汉字大写金额,最后换行。

输入样例:
123.45

输出样例:
壹佰贰拾叁元肆角伍分

***********************************/

#include <stdio.h>
#include <string.h>

char *num_to_chinese(int num) {
    char *digit[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    return digit[num];
}

void zhengshu_part(int num, char *result) {
    char *danwei[] = {"", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿"};  // 第一个""实际上用不到，只是为了省去映射步骤
    int unit = 0;  // 位数
    int zero= 0;  // 标记是否需要输出"零"

    if (num == 0)
    {
        strcat(result, "零");  // strcat的功能是将两个数组合并
        return;
    }
    
    while (num > 0) {
        int digit = num % 10;
        if (digit != 0)
        {
            if (zero)
            {
                strcat(result, "零");
                zero = 0;
            }
            strcat(result, num_to_chinese(digit));  // 转换数字
            strcat(result, danwei[unit]);  // 添加单位
        } else {
            zero = 0;  // 遇到0，标记，待后面补充“零”
        }

        num /= 10;
        unit++;  // 每次单位向左移动
    }

    // 逆转字符串，最终结果的顺序是从高位到低位
    // （处理后结果需要从最后一位的单位向前进行拼接）
    for (int i = 0; i < strlen(result); i++) {
        char temp = result[i];
        result[i] = result[strlen(result) - 1 - i];
        result[strlen(result) - 1 - i] = temp;
    }

        strcat(result, "元");  // 将"元"添加到 result 的末尾
}

void xiaoshu_part(int num, char *result) {
    // 如果没有小数，直接退出
    if (num == 0) {
        return;
    }

    int jiao = num / 10, fen = num % 10;  // 提取角和分

    if (jiao != 0) {
        strcat(result, num_to_chinese(jiao));  // 转换数字
        strcat(result, "角");  //添加单位
    }
    if (fen != 0) {
        strcat(result, num_to_chinese(fen));
        strcat(result, "分");
    }
}

int main(void) {
    double input;
    scanf("%lf", &input);

    // 处理等会要进入函数的数字
    int zhengshu = (int)input;
    int xiaoshu = (int)((input - zhengshu) * 100);

    char result[100] = {0};

    zhengshu_part(zhengshu, result);
    xiaoshu_part(xiaoshu, result);

    // 去掉没有角和分的情况
    if (xiaoshu == 0) {
        result[strlen(result) - 1] = "\0";
    }

    printf("%s", result);
    return 0;
}
