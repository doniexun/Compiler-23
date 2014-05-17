#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int hashFunction(char *token)
{
	int pos = 0;
	int i = 0;
	while(token[i] != '\0')
	{
		key = ((temp << 4) + token[i])%SIZE;
		i++;
	}
	return pos;
}

void initTable()
{
	int i;
	for (i = 0; i < 26; i++)
	{
		
		symTable[i]->name = NULL;
		symTable[i]->link = NULL;
		symTable[i]->type = NULL;
		tableHead[i] = symTable[i];
		
	}
}

void insert(char* token)
{
	int posAlpha = token[0]%26;
	int pos = hashFunction(token);
	
	// When First Linked List is empty
	if(tableHead[pos]->s != NULL)
	{
		listPointer newNode;
		newNode->name = token;
		//newNode->type = .....
		newNode->link = NULL;
		symTable[pos]->link = newNode;
	}
	else
	{
		symTable[pos]->name = token;
	}
}

listPointer serach(char* token)
{
	int pos = token[0]%26;

	listPointer trail = tableHead[pos];

	if(trail->s != NULL)
	{
		do{
			if(strcmp(trail-s, token) == 0)
				break;
			trail = trail->link;
		} while (trail != NULL);
	}	
	else
	{
		printf("%s is NOT a identifier.\n", token);
		trail = NULL;
	}

	return trail;
}

void dump()
{
	listPointer trail;
	for (i = 0; i < 26; i++) {
		trail = tableHead[i];

		if(trail->s != NULL)
			do {
				printf("identifier:%s\n", trail->s);
				trail = trail->link;
			} whiel(trail != NULL);
	}
}
