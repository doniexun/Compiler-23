#include "symTable.h"

scope *createScope()
{
	scope *s;
	MALLOC(s, sizeof(*s));
	s->varNum = 0;
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
	int pos = (temp-'a');

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

symTable *searchRecu(scope *s, char* token)
{
	/* Search identifier at symbol table which is at scope s.
	   If not found then find the global scope's symbol table.
	   Found then return pointer. Not found return NULL. */
	char temp = tolower(token[0]);
	int pos = (temp-'a');
	scope *sc = s;
	int found = 0;

	symTable *trail;

	// The pointer is not point to the head of symbol table.
	// and Head Pointer isn't point to the NULL.

	while(sc != NULL)
	{
		trail = sc->tableHead[pos];

		if(trail->name != NULL)
		{
			do{
				if(strcmp(trail->name, token) == 0)
				{
					found = 1;
					break;
				}
				trail = trail->next;
			} while (trail != NULL);
		}	
		else
		{
			trail = NULL;
		}

		if(found == 1)
			break;
		
		sc = sc->prevLink;
	}
	
	return trail;
}
	

symTable *insert(scope *s, char* token)
{
	/* Insert function. When recongized an identifier,
	   then insert to symbol table. */
	char temp = tolower(token[0]);
	int pos = (temp-'a');


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
			newNode->index= s->varNum++;
			s->table[pos]->next = newNode;
			s->table[pos] = newNode;
			return newNode;
		}
		// Pointer is point to the head of symbol table.
		else
		{
			s->table[pos]->name = token;
			s->table[pos]->index= s->varNum++;
			return s->table[pos];
		}
	}
	else //token was existed. return NULL
		return NULL;
}

void deleteSym(scope *s, symTable *sym)
{
	/* Search identifier at symbol table which is at scope s.
	   Found then delete it. Not found then do nothing. */
	char temp = tolower(sym->name[0]);
	int pos = (temp-'a');
	int limitIndex, i;

	symTable *trail = s->tableHead[pos];
	symTable *before = NULL;
	// The pointer is not point to the head of symbol table.
	// and Head Pointer isn't point to the NULL.
	if(trail->name != NULL)
	{
		do{
			if(strcmp(trail->name, sym->name) == 0)
			{
				limitIndex = trail->index;
				s->varNum--;
				break;
			}
			before = trail;
			trail = trail->next;
		} while (trail != NULL);

		if(trail != s->tableHead[pos])
		{
			before->next = trail->next;
		}
		else
		{
			if(trail->next) {
				s->tableHead[pos] = trail->next;
				printf("trailN:%s\n",trail->next->name);
			}
			else {
				s->tableHead[pos]->name = NULL;
				s->tableHead[pos]->next = NULL;
			}
		}
							
		//trail = NULL;
	}

	for (i = 0; i < 26; i++) {
		trail = s->tableHead[i];

		if(trail->name != NULL)
		{
			do {
				if(trail->index > limitIndex)
					trail->index--;
				trail = trail->next;
			} while(trail != NULL);
		}
	}
}

void printSym(symTable *sym)
{
	printf("%d\t%s\t%d\t%d\n", sym->index, sym->name, sym->type, sym->attr);
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
		{
			do {
				printSym(trail);
				trail = trail->next;
			} while(trail != NULL);
		}
	}
	// ....
}
