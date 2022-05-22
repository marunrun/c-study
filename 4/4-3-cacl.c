#include "stdio.h"
#include <stdlib.h>/* for atof() */
#include <math.h>
#include "4-def.h"


/* reverse polish calculator */
int exec() {

    int type;
    double op1;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error : zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g", pop());
                break;
            case '?':
                // 打印栈顶的元素
                op2 = pop();
                printf("\t %.8n", op2);
                push(op2);
                break;
            case 'c':
                // 清空栈
                clear();
                break;
            case 'd':
                // 复制栈顶的数据
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':
                // swap 交换栈顶的两个数据
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            default:
                printf("error : unknown command %s\n", s);
                break;
        }

    }

    return 0;
}
