//
// Created by marun on 2022/3/25.
//

#include <ctype.h>
#include "4-2.h"

/* 把字符串转成对应的双精度浮点型*/
double atof(char s[]) {
    double val, power;
    int i, sign;

    // 跳过空白符
    for (i = 0; i < isspace(s[i]); ++i);

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    for (val = 0.00; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}