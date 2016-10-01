#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "funciones.h"
#define intBuffer 50000

int main(){

	encode();
	//imprimir();
	decode();
	/*while(1){
		char letra;
		fflush(stdin);
		scanf("%c",&letra);
		printf("vocal:      %d \n",isVowel(letra) );
		printf("consonante: %d \n",isConsonant(letra) );
	}*/
	
	//int position=findPosition(listLetters,'r');

	//printf("position: %d , letra: %c",position,getLetter(listLetters,position));


	/*int i;
	printf("forrr\n");
	for(i = 0; string[i]; i++){
	   	printf("%c ",string[i]);
	}
	printf("\n");
	moveRight(list2);
	moveRight(list2);
	moveRight(list2);
	moveRight(list2);
	moveRight(list2);
	showListFL(list);	
	showListFL(list2);
	//encode();
	printf("\n %d \n",compareList(list,list2) );*/
	
	/*printf("copiando sin la funcion\n");
	List* list2New=list2;
	list2New->first->letter='v';
	showListFL(list2);
	showListFL(list2New);
	printf("\n");
	printf("copiando con la funcion\n");
	List* listNew=(List*)listcpy(list);
	listNew->first->letter='v';
	showListFL(list);
	showListFL(listNew);*/
	return 0;
}