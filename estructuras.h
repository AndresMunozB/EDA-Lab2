#ifndef _STRUCTS_H_
#define _STRUCTS_H_

typedef	struct Nodo
{
	char letter;
	struct Nodo* next;
	struct Nodo* back;
}Nodo;

typedef struct List
{
	int length;
	Nodo* first;
	Nodo* last;
	
}List;

#endif

