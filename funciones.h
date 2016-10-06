/**
 * @file funciones.h
 * Este es un ejemplo de como organizar los programas en C
 * este archivo contiene las firmas de las funciones a definir
 * en funciones.c
 * 
 * @author Andres Muñoz
 * @version 1.0.1
 */

#include "estructuras.h"

#ifndef _FUNCIONES_H
#define _FUNCIONES_H

/**
 * Funcion createNodo
 * crea un nodo con el caracter entregado
 * @param char letter, caracter a guardar en el nodo a crear
 * @return nodo con la informacion guardada

*/
Nodo* createNodo(char letter); // crea un nodo con una letra dentro 
/**
 * Funcion createList
 * crea un tipo de dato List inicializado listo para ocupar
 * @return List*, Puntero a una lista
*/
List* createList(); //crea una lsita incializada
/**
 * Funcion add
 * agrega un elemento a una lista al final de esta
 * @param List* list, lista a la cual se le agregara el elemento
 * @param char letter,caracter que se agregara a la lista
*/
void add(List* list, char letter); // arega una letra a la lista
/**
 * Funcion invert
 * crea un nueva lista invertida a partir de una lista anterior
 * @param List* list,lista a invertir
 * @return List*, puntero a la nueva lista invertida
*/
List* invert(List* list);
/**
 * Funcion delete
 * funcion que elimina un nodo en una posicion especifica
 * @param List* list, lista a la cual se le eliminara un nodo
 * @param int position, correstponde a la posicion del nodo que se quiere eliminar
*/
void delete(List* list,int position);
/**
 * Funcion deleteList
 * funcion que elimina todos los nodos de una lista
 * @param List* list, corresponde a la lista que se le eliminaran los nodos
*/
void deleteList(List* list);
/**
 * Funcion deleteSpaceLast
 * funcion que elimina de una lista todos los nodos al final de esta que
 * contengan un espacio como informacion guardada dentro de este.
 * @param List list, corresponde a la lista que se le quieren eliminar los espacio al final
*/
void deleteSpaceLast(List* list);
/**
 * Funcion find
 * funcion que busca una letra dentro de un lista 
 * @param List* list, corresponde a la lista en la cual se buscara la letra.
 * @param char letter, corresponde a la letra a buscar dentro de la lista.
 * @return int, esta funcion retorna 0 en caso de no encontrar la letra y 1 en caso de si encontrala.
*/
int find(List* list,char letter); // verifica si se encuentra la letra en la lista ->0:no esta , 1:si esta
/**
 * Funcion findPosition
 * funcion que busca dentro de un a lista la posicion de un letra.
 * @param List* list, corresponde a la lista en la cual se buscara la posicion de la letra
 * @param char letter, corresponde a la letra que se esta buscando para obtener la posicion.
 * @return int, corresponde a la posicion de la letra buscada, entrega -1 en caso de no encotrala.
*/
int findPosition(List* list,char letter);
/**
 * Funcion getLetter
 * funcion que busca una letra segun la posicion entregada
 * @param List* list, corresponde a la lista en la cual se obtendra la letra
 * @param int position, corresponde a la posicion de la letra en la lista
 * @retrun char, corresponde a la letra de la lista en la posicion entregada como parametro.
*/
char getLetter(List* list,int position);
/**
 * Funcion isVowel
 * funcion que verifica si un caracter(letra) es una vocal.
 * @param char letter, corresponde a la letra a verficar
 * @return int, entrega 0 en caso de no ser vocal y 1 en caso de serlo.
*/
int isVowel(char letter);
/**
 * Funcion isConsonant
 * funcion que verifica si un caracter (letra) es una consonante.
 * @param char letter, corresponde a la letra a verificar.
 * @return int, entrega 0 en caso de no ser una consonate y 1 en caso de serlo.
*/
int isConsonant(char letter);
/**
 * Funcion showListFL
 * funcion que muestra por pantalla una lista desde el inicio a fin.
 * @param List* list, corresponde a la lista que se desea mostrar.
*/
void showListFL(List* list); //muestra la lista adelante hacia atras
/**
 * Funcion showListLF
 * funcion que muestra por pantalla una lsita desde el fin a inicio.
 * @param List* list, corresponde a la lsita que se desea mostrar.
*/
void showListLF(List* list); //muestra la lista desde atras hacia delante
/**
 * Funcion moveLeft
 * funion mueve todos los datos de una lista una posicion a la izquierda
 * @param List* list, puntero a lista de la cual se le desean mover los datos
*/
void moveLeft(List* list); // desplaza la lsita hacia la izquierda
/**
 * Funcion moveRight
 * funcion que mueve todos los datos de una lsita una posicion a la derecha
 * @param List* list, puntero a lista de la cual se le desean mover los datos
*/
void moveRight(List* list); //desplaza la lsita hacia la derecha
/**
 * Funcion stringToList
 * funcion que a partir de un string forma una una lista que contiene todos los caracteres del string
 * @param char* string, string que se desea transformar a lista.
 * @return List*, puntero a lista con los datos guardados. 
*/
List* stringToList(char* string); //ingresa todas las letras sin repeticion y en minusculas a una lista
/**
 * Funcion listToString
 * funcion que crea un string con los datos de una lista
 * @param List* list, lista que contiene los datos(caracteres) del string
 * @return char*, string formado a partir de la lista.
*/
char* listToString(List* list);
/**
 * Funcion createListEncode
 * funcion que crea una con los datos de otra pero en la nueva lista creada
 * los datos no se repiten, estan ordenados alfabeticamente y 
 * se le agrega un caracter espacio al final de la lista
 * @param List* list, lista que contiene los datos para formar la nueva lista
 * @return List*, corresponde a la lista que se ocupara para codificar
*/
List* createListEncode(List* list);
/**
 * Funcion listcpy
 * funcion que copia los datos de una lista
 * @param List* list, corresponde a la lista que se desea copiar
 * @return List*, puntero a la nueva lista creada con los mismos datos de la lista entregada como parametro
*/
List* listcpy(List* list);
/**
 * Funcion compareList
 * funcion utilizada para saber el desface entre dos listas iguales que fueron movidad hacia la derecha o izquierda
 * @param List* list1, puntero a la primera lista que se desea comparar
 * @param List* list2, puntero a la segunda lista que se desea comparar
 * @retrun int, corresponde al desface entre las dos listas.
*/
int compareList(List* list,List* list2); // devuelve el desface entre dos listas de caracteres
/**
 * Funcion encode
 * lee un archivo codifica, el texto dentro de el y luego entrega en otro archivo de texto el resultado
*/
int  encode();
/**
 * Funcion deencode
 * lee un archivo decodifica, el texto dentro de el y luego entrega en otro archivo de texto el resultado
*/
int decode();
/**
 * Funcion showTitle
 * funcion que muestra por pantalla el titulo del programa
*/
void showTitle();
/**
 * Funcion bubbleSort
 * ordena alfabaticamente una lista
 * @param List* list, corresponde a la lista que se desea ordenar
*/
void bubbleSort(List* list); //ordena alfabeticamente las letras de una lista!
/**
 * Funcion pause
 * es utilizada para hacer una pausa dentro de la ejecucion del programa
*/
void pause();
#endif