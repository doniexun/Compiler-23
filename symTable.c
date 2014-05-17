#include "symTable.h"

scope *createScope()
{
	scope *s;
	MALLOC(s, sizeof(*s));
	initTable(s);
	return s;
}

void initTable(scope *s)
{
	/* Initialize the Symbol Table's pointer. */
	int i;
	for (i = 0; i < 26; i++)
	{
		MALLOC(s->table[i], sizeof(symTable));
		s->table[i]->name = NULL;
		s->table[i]->next = NULL;
		s->table[i]->type = ERR_TYPE;
		s->table[i]->attr = ERR_ATTR;
		s->tableHead[i] = s->table[i];	
	}
}

symTable *search(scope *s, char* token)
{
	/* Search identifier at symbol table which is at scope s.
	   Found then return pointer. Not found return NULL. */
	char temp = tolower(token[0]);
	int pos = temp%26;

	symTable *trail = s->tableHead[pos];

	// The pointer is not point to the head of symbol table.
	// and Head Pointer isn't point to the NULL.
	if(trail->name != NULL)
	{
		do{
			if(strcmp(trail->name, token) == 0)
				break;
			trail = trail->next;
		} while (trail != NULL);
	}	
	else
	{
		trail = NULL;
	}

	return trail;
}

symTable *insert(scope *s, char* token)
{
	/* Insert function. When recongized an identifier,
	   then insert to symbol table. */
	char temp = tolower(token[0]);
	int pos = temp%26;

	// Determine is this identifier insert before?
	if(search(s, token) == NULL)
	{
		// The pointer is not point to the head of symbol table.
		// and Head Pointer isn't point to the NULL.
		if(s->tableHead[pos]->name != NULL)
		{
			symTable *newNode;
			MALLOC(newNode, sizeof(symTable));
			newNode->name = token;
			//newNode->type = .....
			newNode->next = NULL;
			newNode->type = ERR_TYPE;
			newNode->attr = ERR_TYPE;
			s->table[pos]->next = newNode;
			s->table[pos] = newNode;
			return newNode;
		}
		// Pointer is point to the head of symbol table.
		else
		{
			s->table[pos]->name = token;
			return s->table[pos];
		}
	}
	else
		return NULL;
}

void printSym(symTable *sym)
{
	printf("Varible name : %s.\n", sym->name);
	printf("Varible type : %d.\n", sym->type);
	printf("Varible attr : %d.\n", sym->attr);
}

void dump(scope *s)
{
	/* Clean whole symbol table's identifiers */
	int i;
	symTable *trail;

	printf("Symbol Table : \n");
	for (i = 0; i < 26; i++) {
		trail = s->tableHead[i];

		if(trail->name != NULL)
			do {
				printf("identifier:%s\n", trail->name);
				trail = trail->next;
			} while(trail != NULL);
	}
	// ....
}
