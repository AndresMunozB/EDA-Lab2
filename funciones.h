#include "estructuras.h"

#ifndef _FUNCIONES_H
#define _FUNCIONES_H
Nodo* createNodo(char letter); // crea un nodo con una letra dentro 
List* createList(); //crea una lsita incializada
void add(List* list, char letter); // arega una letra a la lista
List* invert(List* list);
void delete(List* list,int position);
void deleteList(List* list);
void deleteSpaceLast(List* list);
int find(List* list,char letter); // verifica si se encuentra la letra en la lista ->0:no esta , 1:si esta
int findPosition(List* list,char letter);
char getLetter(List* list,int position);
int isVowel(char letter);
int isConsonant(char letter);
void showListFL(List* list); //muestra la lista adelante hacia atras
void showListLF(List* list); //muestra la lista desde atras hacia delante
void moveLeft(List* list); // desplaza la lsita hacia la izquierda
void moveRight(List* list); //desplaza la lsita hacia la derecha
List* stringToList(char* string); //ingresa todas las letras sin repeticion y en minusculas a una lista
char* listToString(List* list);
List* createListEncode(List* list);
List* listcpy(List* list);
int compareList(List* list,List* list2); // devuelve el desface entre dos listas de caracteres
int  encode();
int decode();
void showTitle();

void bubbleSort(List* list); //ordena alfabeticamente las letras de una lista!

#endif