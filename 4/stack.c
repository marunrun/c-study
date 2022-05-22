//
// Created by marun on 2022/5/22.
//


#include "stdio.h"
#include "calc.h"

#define MAXVAL 100


// 静态声明
static int sp = 0;
static double val[MAXVAL];

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

void clear() {
    sp = 0;
}
