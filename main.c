#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "funciones.h"
#define intBuffer 50000

int main(){
	printf("Ingrese una palabra: ");
	char string[intBuffer];
	fflush(stdin);
	gets(string);;
	printf("%s\n", string);
	List* list=(List*)stringToList(string);
	List* list2=(List*)stringToList(string);
	int i;
	printf("forrr\n");
	for(i = 0; string[i]; i++){
	   	printf("%c ",string[i]);
	}
	printf("\n");
	showListFL(list2);
	showListFL(list);

	return 0;
}