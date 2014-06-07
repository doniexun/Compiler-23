#ifndef _SYMTABLE_H_
#define _SYMTABLE_H_

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
	if(!((p) = malloc(s))) {\
		fprintf(stderr,"Insufficient memory");\
		exit(EXIT_FAILURE);\
}

typedef enum { CONST_TYPE, INT_TYPE, REAL_TYPE, LOGI_TYPE, CHAR_TYPE, PINT_TYPE,
               STR_TYPE, PREAL_TYPE, PLOGI_TYPE, PCHAR_TYPE, PROG_TYPE, FUNC_TYPE,
               SUBR_TYPE, ERR_TYPE } Types;

typedef enum { ARY_ATTR, PTR_ATTR, PARA_ATTR,  BOTH, ERR_ATTR } Attrs;

// Structure of Symbol Table
typedef struct symTable symTable;
struct symTable {
	char *name;
	Types type;
	Attrs attr;
	int index;
	union{
		int ival;
		float dval;
		int bval;
		char c;
	};
    symTable *next;
};

// Structure of scope
typedef struct scope scope;
struct scope{
	symTable *table[26];
	symTable *tableHead[26];
	scope *prevLink;
	int varNum;
};


scope *currentScope;
scope *prevScope;
scope *globalScope;
scope *scopeGroup[100];
int scopeNum;

scope *createScope();

void initTable(scope *s);

symTable *search(scope *s, char* token);

symTable *searchRecu(scope *s, char *token);

symTable *insert(scope *s, char* token);

void deleteSym(scope *s, symTable *sym);

void printSym(symTable *sym);

void dump();

#endif
