#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "funciones.h"
#define intBuffer 50000

int main(){
	int menu=0;
	char pause[intBuffer];
	showTitle();
	do{
		printf("		MENU\n" );
		printf("1) Codificar texto en Cifrado/Entrada.in.txt\n");
		printf("2) Decodificar texto en Descifrado/Entrada.in.txt\n");
		printf("3) Salir\n\n");
		printf("Ingrese una opcion: ");
		fflush(stdin);
		scanf("%d",&menu);
		switch (menu){
			case 1:
				encode();
				printf("El texto ha codificado, puedes verlo en Cifrado/Salida.out.txt\n");
				printf("Presione 'Enter' para continuar...");
				fflush(stdin);
				gets(pause);
				break;
			case 2:
				decode();
				printf("El texto ha decodificado, puedes verloen Descifrado/Salida.out.txt\n");
				printf("Presione 'Enter' para continuar...");
				fflush(stdin);
				gets(pause);
				break;
		}
		printf("\n\n\n");
	}while(menu!=3);

	return 0;
}