#ifndef _OPERATOR_H_
#define _OPERATOR_H_

enum operator {
	ADD, SUB, MULTI, DIV,
	ASSIGN,
	NOT, AND, OR, GT, GE, LT, LE, EQ, NE
};

char *operatorStr(enum operator op);

#endif
