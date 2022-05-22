//
// Created by marun on 2022/5/22.
//

#include "stdio.h"
#include "calc.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp =0;


/**
 * 取一个字符 可能是压回的字符
 * @return
 */
int getCh(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/**
 * 把字符压回到输入中
 * @param c
 */
void unGetCh(int c) {

    // 如果当前缓冲区满了 提示
    if (bufp >= BUFSIZE) {
        printf("ungetch : too many characters\n");
    } else {
        // 写入到缓冲区
        buf[bufp++] = c;
    }
}
