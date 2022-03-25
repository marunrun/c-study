//
// Created by marun on 2022/3/25.
//

#include <ctype.h>
#include "4-2.h"

/* 把字符串转成对应的双精度浮点型*/
double atof(char s[]) {
    double val, power;
    int exp, i, sign;

    // 跳过空白符
    for (i = 0; i < isspace(s[i]); ++i);

    // 判断正负
    sign = (s[i] == '-') ? -1 : 1;

    // 跳过正负号
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    // 判断当前字符是否是数值
    for (val = 0.00; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    // 如果当前字符是 小数点 跳过
    if (s[i] == '.') {
        i++;
    }

    // 小数点后的数字
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // 计算数值
    val = sign * val / power;

    // 计算科学计数法
    if (s[i] == 'e' || s[i] == 'E') {
        // 判断正负
        sign = (s[++i] == '-') ? -1 : 1;
        // 跳过正负号
        if (s[i] == '-' || s[i] == '+') {
            i++;
        }
        for (exp = 0; isdigit(s[i]); ++i) {
            exp = 10 * exp + (s[i] - '0');
        }
        if (sign == 1) {
            while (exp-- > 0) {
                val *= 10;
            }
        } else {
            while (exp-- > 0) {
                val /= 10;
            }
        }

    }
    return val;
}