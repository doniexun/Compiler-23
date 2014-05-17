#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Linked List data structer
typedef struct listNode* listPointer;
typedef struct listNode {
	char* name;
	char* type;
	listPointer link;
};

static listPointer symTable[26];
static listPointer tableHead[26];

#endif
