//
// Created by marun on 2022/5/22.
//
#include <ctype.h>
#include <stdio.h>
#include "calc.h"

/**
 * 取出下一个操作符 或者数值
 * @param s
 * @return
 */
int getOp(char s[]) {

    int c, i;

    static int lastCh = 0;

    if (lastCh == 0) {
        c = getCh();
    } else {
        c = lastCh;
        lastCh = 0;
    }

    // 跳过空行和 tab
    while ((s[0] = c) == ' ' || c == '\t') {
        c = getCh();
    }

    s[1] = '\0';
    i = 0;
    // 如果第一个输入不是数值 并且也不是小数点或负数 直接return出去
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    // 如果是 - 号
    if (c == '-') {

        // 如果是 - 号下一个是数值或者小数点 那说明是一个负数
        if (isdigit(c = getCh()) || c == '.') {
            s[++i] = c;
        } else {
            // 如果不是数值也不是回车 那就说明是一个操作符 重新写回缓冲区
            if (c != EOF) {
                lastCh = c;
            }
            // 返回 减号 操作符
            return '-';
        }
    }


    // 拼接数值
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getCh())) {
        }
    }

    // 如果是小数点 继续拼接小数部分
    if (c == '.') {
        while (isdigit(s[++i] = c = getCh())) {
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        lastCh = c ;
    }


    return NUMBER;
}
