//
// Created by marun on 2022/5/21.
//

#ifndef C_APPLICATION_DESIGN_4_3_OP_H
#define C_APPLICATION_DESIGN_4_3_OP_H

#endif //C_APPLICATION_DESIGN_4_3_OP_H

#define NUMBER '0'
#define BUFFSIZE 100


#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */


/**
 * 栈的大小
 */
#define MAXVAL 100



int getop(char []);
int getch(void);
void ungetch(int);

void push(double );
double pop(void);

void clear();

