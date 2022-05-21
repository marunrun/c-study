//
// Created by marun on 2022/5/21.
//

#include "4-3-op.h"
#include "stdio.h"
#include "string.h"
#include "ctype.h"

char buf[BUFFSIZE]; /* 用于ungetch函数的缓冲区 */
int bufp = 0; /* buf中下一个空闲位置 */



double val[MAXVAL];  // 存放数据的栈
int sp = 0; // 下一个空闲栈的位置

/**
 * 取出下一个操作符 或者数值
 * @param s
 * @return
 */
int getop(char s[]) {
    int c, i;

    // 跳过空行和 tab
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
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
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            // 如果不是数值也不是回车 那就说明是一个操作符 重新写回缓冲区
            if (c != EOF) {
                ungetch(c);
            }
            // 返回 减号 操作符
            return '-';
        }
    }


    // 拼接数值
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
        }
    }

    // 如果是小数点 继续拼接小数部分
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
        }
    }
    s[i] = '\0';
    if( c != EOF) {
        ungetch(c);
    }


    return NUMBER;
}

/**
 * 取一个字符 可能是压回的字符
 * @return
 */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/**
 * 把字符压回到输入中
 * @param c
 */
void ungetch(int c) {

    // 如果当前缓冲区满了 提示
    if (bufp >= BUFFSIZE) {
        printf("ungetch : too many characters\n");
    } else {
        // 写入到缓冲区
        buf[bufp++] = c;
    }
}

// 入栈
void push(double f) {

    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error : stack full ,can't push %g\n", f);
    }
}

// 出栈
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

