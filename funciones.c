#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "funciones.h"
#include "estructuras.h"
#define intBuffer 50000



Nodo* createNodo(char letter){ // crea un nodo con una letra dentro 
	Nodo* new= (Nodo*)malloc(sizeof(Nodo));
	if(new!=NULL){
		new->letter=letter;
		new->next=NULL;
		new->back=NULL;
	}
	return new;
}
List* createList(){ //crea una lsita incializada
	List* list=(List*)malloc(sizeof(List));
	list->first=NULL;
	list->last=NULL;
	return list;
}


void add(List* list, char letter){ // arega una letra a la lista
	Nodo* new=(Nodo*)createNodo(letter);
	if(list->first==NULL){
		list->first=new;
		list->first->next=list->first;
		list->last=list->first;
		list->first->back=list->last;
	}
	else{
		list->last->next=new;
		new->next=list->first;
		new->back=list->last;
		list->last=new;
		list->first->back=list->last;
	}
}
int find(List* list,char letter){ // verifica si se encuentra la letra en la lista ->0:no esta , 1:si esta
	Nodo* actual=list->first;
	if(list->first==NULL){
		return 0;
	}
	do{
		if(actual->letter==letter){
			return 1;
		}
		else{
			actual=actual->next;
		}
	}while(actual!=list->first);
	return 0;
}



void showListFL(List* list){ //muestra la lista adelante hacia atras
	Nodo* actual=list->first;
	do{
		printf("%c ",actual->letter );
		actual=actual->next;
	}while(actual!=list->first);
	printf(";\n");
}

void showListLF(List* list){ //muestra la lista desde atras hacia delante
	Nodo* actual=list->last;
	do{
		printf("%c ",actual->letter );
		actual=actual->back;
	}while(actual!=list->last);
	printf(";\n");
}
void moveLeft(List* list){ // desplaza la lsita hacia la izquierda
	Nodo* actual=list->first;
	char aux=actual->letter;
	do{
		actual->letter=actual->next->letter;
		actual=actual->next;
	}while(actual->next!=list->first);
	list->last->letter=aux;
}
void moveRight(List* list){ //desplaza la lsita hacia la derecha
	Nodo* actual=list->last;
	char aux=actual->letter;
	do{
		actual->letter=actual->back->letter;
		actual=actual->back;
	}while(actual->back!=list->last);
	list->first->letter=aux;
}

List* stringToList(char* string){ //ingresa todas las letras sin repeticion y en minusculas a una lista
	int i;
	for(i = 0; string[i]; i++){
	   	string[i] = tolower(string[i]);
	}
	List* list=(List*)createList();
	int position=0;
	char letter=string[position];
	while(letter!='\0'){
		if(!find(list,letter) && letter!=' '){
			add(list,letter);
		}
		position+=1;
		letter=string[position];
	}
	//ordenar alfabeticamente
	bubbleSort(list);
	//agregar el espacio al final
	add(list,' ');
	return list;
}
void bubbleSort(List* list){ //ordena alfabeticamente las letras de una lista!
	int t;
	Nodo* actual = list->first;
	while(actual->next != list->first){
	Nodo* next = actual->next;

		while(next!=list->first){
		   	if(actual->letter > next->letter){
		    	t = next->letter;
		        next->letter = actual->letter;
		        actual->letter = t;          
		   	}
		   	next = next->next;                    
		}    
	actual = actual->next;
	next = actual->next;
	}
}

List*  encode(){
	int count=0;

}

