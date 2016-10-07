#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "estructuras.h"
#define intBuffer 50000


/**
 * Funcion pause
*/
void pause(){
	printf("Press 'Enter' to continue: ... ");
	fflush(stdin);
	while ( getchar() != '\n'){
		fflush(stdin);
	}
}

/**
 * Funcion createNodo
*/
Nodo* createNodo(char letter){ // crea un nodo con una letra dentro
	Nodo* new= (Nodo*)malloc(sizeof(Nodo));
	if(new!=NULL){
		new->letter=letter;
		new->next=NULL;
		new->back=NULL;
	}
	return new;
}

/**
 * Funcion  createList
*/
List* createList(){ //crea una lsita incializada
	List* list=(List*)malloc(sizeof(List));
	list->first=NULL;
	list->last=NULL;
	list->length=0;
	return list;
}

/**
 * Funcion add
*/
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
	list->length+=1;

}

/**
 * Funcion invert
*/
List* invert(List* list){
	List* listInvert= (List*)createList();
	Nodo* actual=list->last;
	do{
		//printf("letter: %c\n",actual->letter );
		add(listInvert,actual->letter);
		actual=actual->back;
	}while(actual!=list->last);
	return listInvert;
}

/**
 * Funcion delete
*/
void delete(List* list,int position){
	Nodo* actual=list->first;

	if(list->first!=NULL){
		//printf("caracter eliminado: %c\n",actual->letter );
		int i;
		for (i = 0; i < position; i++){
			actual = actual->next;
		}

		 if (actual==list->first){
			list->first=list->first->next;
			list->first->back=list->last;
			list->last->next=list->first;
		}
		else if(actual==list->last){
			list->last=list->last->back;
			list->last->next=list->first;
			list->first->back=list->last;
		}
		else{
			actual->back->next=actual->next;
			actual->next->back=actual->back;
		}
	}
	list->length-=1;
	free(actual);
}

/**
 * Funcion deleteList
*/
void deleteList(List* list){
	//printf("holaaa entre al deleteList\n");
	int i;
	int length=list->length;
	if (list->first!=NULL){
		int contador=0;
		for(i=0;i<length;i++){
			delete(list,0);
			//printf("contador deteleList: %d\n",contador );
			contador+=1;
			//printf("holaa\n");
			//printf("eleimine\n");
			//showListFL(list);
		}
	}
	//printf("largo : %d\n",list->length );
	if (list->length==0){

		//printf("entre a la cabeza\n");
		//printf("caracter eliminado: %c\n",list->first->letter );
		//free(list->first);
		list->first=NULL;
		list->last=NULL;
		free(list);
	}
	
}

/**
 * Funcion deleteSpaceLast
*/
void deleteSpaceLast(List* list){
	while(list->last->letter==' '){
		delete(list,list->length-1);
	}
}

/**
 * Funcion find
*/
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

/**
 * Funcion findPosition
*/
int findPosition(List* list,char letter){
	if (list->first==NULL){
		return -1;
	}
	int position,finded;
	Nodo* actual=list->first;
	position=0;
	finded=0;
	do{
		if(letter==actual->letter){
			return position;
		}
		else{
			actual=actual->next;
			position+=1;
		}
		
	}while(actual!=list->first);
	return -1;
}

/**
 * Funcion getLetter
*/
char getLetter(List* list,int position){
	Nodo* actual=list->first;
	if(list->first==NULL){
		return '\0';
	}
	if(position==0){
		return actual->letter;
	}
	else{
		do{
			actual=actual->next;
			position-=1;
		}while(position>0);

	}
	return actual->letter;
}

/**
 * Funcion isVowel
*/
int isVowel(char letter){
	letter=tolower(letter);
	List* vowels=(List*) createList();
	add(vowels,'a');
	add(vowels,'e');
	add(vowels,'i');
	add(vowels,'o');
	add(vowels,'u');
	if(find(vowels,letter)){
		//liberar lista
		deleteList(vowels);
		return 1;
	}
	else{
		//liberar lista
		deleteList(vowels);
		return 0;
	}
}

/**
 * Funcion isConsonant
*/
int isConsonant(char letter){
	letter=tolower(letter);
	List* consonants=(List*) createList();
	add(consonants,'b');
	add(consonants,'c');
	add(consonants,'d');
	add(consonants,'f');
	add(consonants,'g');
	add(consonants,'h');
	add(consonants,'j');
	add(consonants,'k');
	add(consonants,'l');
	add(consonants,'m');
	add(consonants,'n');
	add(consonants,'p');
	add(consonants,'q');
	add(consonants,'r');
	add(consonants,'s');
	add(consonants,'t');
	add(consonants,'v');
	add(consonants,'w');
	add(consonants,'x');
	add(consonants,'y');
	add(consonants,'z');
	if(find(consonants,letter)){
		//liberar lista
		deleteList(consonants);
		return 1;
	}
	else{
		//liberar lista
		deleteList(consonants);
		return 0;
	}

}


/**
 * Funcion showListFL
*/
void showListFL(List* list){ //muestra la lista adelante hacia atras
	Nodo* actual=list->first;
	if(list->first==NULL){
		printf("()\n");
	}
	else{
		printf("(" );
		do{
			printf("%c ",actual->letter );
			actual=actual->next;
		}while(actual!=list->first);
		printf(")\n");
	}
}

/**
 * Funcion showListLF
*/
void showListLF(List* list){ //muestra la lista desde atras hacia delante
	Nodo* actual=list->last;
	if(list->first==NULL){
		printf("()\n");
	}
	else{
		printf("(");
		do{
			printf("%c ",actual->letter );
			actual=actual->back;
		}while(actual!=list->last);
		printf(")\n");
	}
}

/**
 * Funcion moveLeft
*/
void moveLeft(List* list){ // desplaza la lsita hacia la izquierda
	Nodo* actual=list->first;
	char aux=actual->letter;
	do{
		actual->letter=actual->next->letter;
		actual=actual->next;
	}while(actual->next!=list->first);
	list->last->letter=aux;
}

/**
 * Funcion moveRigth
*/
void moveRight(List* list){ //desplaza la lsita hacia la derecha
	Nodo* actual=list->last;
	char aux=actual->letter;
	do{
		actual->letter=actual->back->letter;
		actual=actual->back;
	}while(actual->back!=list->last);
	list->first->letter=aux;
}

/**
 * Funcion stringToList
*/
List* stringToList(char* string){ //ingresa todas las letras sin repeticion y en minusculas a una lista
	int i;
	//printf("hola\n");
	//printf("stirngToList: %s\n",string );
	for(i = 0; string[i]; i++){
	   	string[i] = tolower(string[i]);
	}
	List* list=(List*)createList();

	for(i = 0; string[i]; i++){
		if(string[i]!='\n' && string[i]!='\r')add(list,string[i]);
	}
	return list;
}

/**
 * Funcion listToString
*/
char* listToString(List* list){
	int length=list->length+1;
	char* string=(char*)malloc(sizeof(char)*(length));
	memset(string,0,length);
	Nodo* actual=list->first;
	int position=0;
	if (list->first==NULL){
		return string;
	}
	else{
		do{
			string[position]=actual->letter;
			actual=actual->next;
			position+=1;
		}while(actual!=list->first);
	}
	return string;
}

/**
 * Funcion createListEncode
*/
List* createListEncode(List* list){
	Nodo* actual=list->first;
	List* listEncode=(List*)createList();
	if(list->first==NULL){
		return listEncode;
	}
	else{
		do{
			if(!find(listEncode,actual->letter) && actual->letter!=' '){
				add(listEncode,actual->letter);
			}
			actual=actual->next;

		}while(actual!=list->first);
	}
	bubbleSort(listEncode);
	add(listEncode,' ');
	return	listEncode;
}

/**
 * Funcion listcpy
*/
List* listcpy(List* list){
	List* listNew=(List*)createList();
	if(list->first==NULL){
		return listNew;
	}
	else{
		Nodo* actual=list->first;
		do{
			add(listNew,actual->letter);
			actual=actual->next;
		}while(actual!=list->first);
	}
	return listNew;
}

/**
 * Funcion buubleSort
*/
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

/**
 * Funcion compareList
*/
int compareList(List* list,List* list2){ // devuelve el desface entre dos listas de caracteres
	int counter=0;
	Nodo* actual=list2->first;
	//printf("\n%d while counter\n",counter );
	do{
		if(list->first->letter==actual->letter){
			//printf("%d counter\n", counter);
			return counter;
		}
		else{
			//printf("hola\n");
			actual=actual->next;
			counter+=1;
		}

	}while(actual!=list2->first);
}

/**
 * Funcion encode
*/
int  encode(){

	//obteniendo el string a cifrar
	FILE* fp= fopen("Cifrado/Entrada.in.txt","r");
   	if(fp == NULL){
      	printf("archivo no existe\n");
     	//return NULL;
   	}

   	char buffer[intBuffer];
	fgets(buffer,intBuffer,fp);
	fgets(buffer,intBuffer,fp);
	fclose(fp);


	//creando todas las lsitas a ocupar
	List* list=(List*)stringToList(buffer);
	deleteSpaceLast(list);
	List* listLetters=(List*)createListEncode(list);
	List* listEncode=(List*)listcpy(listLetters);
	List* listFinal=(List*)createList();

	//recorrer la lista original: Metodo para cifrar
	Nodo* an1=list->first;
	char letterEncoded;
	if(list->first==NULL){
		printf("null list\n");
		return 0;
	}
	else{
		do{
			int position=findPosition(listLetters,an1->letter);
			letterEncoded=getLetter(listEncode,position);
			//printf("position: %d letter: %c-> %c\n",position,an1->letter,letterEncoded );
			add(listFinal,letterEncoded);
			if(isVowel(letterEncoded) || letterEncoded==' '){
				moveLeft(listEncode);
				moveLeft(listEncode);
				moveLeft(listEncode);
			}
			else if(isConsonant(letterEncoded)){
				moveRight(listEncode);
			}
			
			an1=an1->next;
		}while(an1!=list->first);

	}

	//mostrarListas
	/*showListFL(list);
   	showListFL(listLetters);
   	showListFL(listEncode);
   	showListFL(listFinal);*/

	//esta es la salida:
	//showListFL(listFinal);
	char* stringEncoded =(char*)listToString(listFinal);
	int comparation=compareList(listLetters,listEncode);
	//printf("stringEncoded :(%s)\n",stringEncoded );
	
	//printf("comparacion: %d\n",comparation );
	//salida al archivo de texto con el string encriptado
	FILE* fileOut= fopen("Cifrado/Salida.out.txt","w");
   	if(fileOut == NULL){
      	printf("archivo no existe\n");
     	//return NULL;
   	}
   	char stringComparation[5];
   	memset(stringComparation,0,5);
   	sprintf(stringComparation,"%02d",comparation);
   	fputs(stringEncoded,fileOut);
   	fputs("\n",fileOut);
   	fputs(stringComparation,fileOut);

   	//sacar esto despues!! con esto se puede ingresa el alfabeto utilziado dentro del archivo de texto!
   	/*char* stringAlphabet=(char*)listToString(listLetters);
   	fputs("\n",fileOut);
   	fputs(stringAlphabet,fileOut);*/

   	deleteList(list);
	deleteList(listLetters);
	deleteList(listEncode);
	deleteList(listFinal);
	fclose(fileOut);
	return 1;

}

/**
 * Funcion decode
*/
int decode(){
	FILE* fp= fopen("Descifrado/Entrada.in.txt","r");
	//printf("decode\n");
   	if(fp == NULL){
      	printf("archivo no existe\n");
     	//return NULL;
   	}

   	char buffer[intBuffer];
   	char stringComparation[5];
   	char stringEncoded[intBuffer];
   	char stringAlphabet[intBuffer];
   	memset(stringComparation,0,5);
   	//recorriendo el arrchivo de texto y guardando los datos en las variables
	fgets(buffer,intBuffer,fp);
	fgets(buffer,intBuffer,fp);
   	memcpy(stringComparation,buffer,2);
   	fgets(stringEncoded,intBuffer,fp);
   	fgets(stringAlphabet,intBuffer,fp);
   	//cerrar el archivo, no se ocupara mas.
   	fclose(fp);

   	int comparation=atoi(stringComparation);
   	//crear las listas para trabajar:
   	List* list=(List*)stringToList(stringEncoded);
   	List* listLettersAux=(List*)stringToList(stringAlphabet);
   	//eliminar todos los espacios de sobra al final de las listas
   	deleteSpaceLast(list);
   	deleteSpaceLast(listLettersAux);
   	//ordenar las letras de abecedario y agregar el espacio al final
   	List* listLetters=(List*)createListEncode(listLettersAux);
   	//showListFL(listLetters);	
   	List* listEncode=(List*)listcpy(listLetters);
   	List* listFinal=createList();
   	//eliminar la lista utilizada para crear la lista del alfabeto
   	deleteList(listLettersAux);
   	//free(listLettersAux);


   	int i;
   	for(i=0;i<comparation;i++){
   		moveRight(listEncode);
   	}

   	//mostrarListas
   	/*showListFL(list);
   	showListFL(listLetters);
   	showListFL(listEncode);
   	showListFL(listFinal);*/

   	//descifrar el texto
   	Nodo* an1=list->last;
	char letterDecode;
	int position;
   	if(list->first==NULL){
		printf("null list\n");
		return 0;
	}
	else{
		do{
			if(isVowel(an1->letter) || an1->letter==' '){
				moveRight(listEncode);
				moveRight(listEncode);
				moveRight(listEncode);
			}
			else if(isConsonant(an1->letter)){
				
				moveLeft(listEncode);
			}
			position=findPosition(listEncode,an1->letter);
			letterDecode=getLetter(listLetters,position);
			//showListFL(listLetters);
   			//showListFL(listEncode);
			//printf("position: %d letter: %c-> %c\n",position,an1->letter,letterEncoded );
			add(listFinal,letterDecode);
			
			an1=an1->back;
		}while(an1!=list->last);

	}
	//showListFL(listFinal);
	List* listInvert=(List*)invert(listFinal);
	//printf("listainvert\n");
	//showListFL(listInvert);


	int comparationFinal=compareList(listLetters,listEncode);
	//printf("hola: %d\n",comparationFinal );
	char* stringDecode=(char*)listToString(listInvert);
	//printf("%s\n",stringDecode );
	FILE* fileOut=fopen("Descifrado/Salida.out.txt","w");
	fputs(stringDecode,fileOut);
	fputs("\n",fileOut);

   	memset(stringComparation,0,5);
   	sprintf(stringComparation,"%02d",comparationFinal);
	fputs(stringComparation,fileOut);



	//eliminar las listas:
	deleteList(list);
	deleteList(listLetters);
	deleteList(listEncode);
	deleteList(listFinal);
	deleteList(listInvert);
	fclose(fileOut);
	return 1;


   	//printf("comparation: %d\n",comparation );
   	
}

/**
 * Funcion showTitle
*/
void showTitle(){

 	printf("  _____   ____       _        \n");
 	printf(" | ____| |  _ \\     / \\       \n");
 	printf(" |  _|   | | | |   / _ \\      \n");
 	printf(" | |___  | |_| |  / ___ \\   _ \n");
 	printf(" |_____| |____/  /_/   \\_\\ (_)\n");
 	printf("\n\n");
}


