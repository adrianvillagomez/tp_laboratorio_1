/*
 ============================================================================
 Name        : mathi.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int nota1;
	int nota2;
	float promedio;
} Alumno;

void SetNota1(void*);
void SetNota2(void*);
void CalcularPromedio(void*);
int main(void) {
	setbuf(stdout,NULL);
	LinkedList* listaAlumnos = ll_newLinkedList();
		Alumno* a;

		for(int i = 0; i<10; i++){
			a = (Alumno*)calloc(sizeof(Alumno), 1);
			if(a != NULL){
				ll_add(listaAlumnos, a);
			}
		}

		ll_map(listaAlumnos, SetNota1);
		ll_map(listaAlumnos, SetNota2);
		ll_map(listaAlumnos, CalcularPromedio);

		for(int i = 0; i<ll_len(listaAlumnos); i++){
			a = ll_get(listaAlumnos, i);
			printf("A%d)\tNota1: %d\tNota2: %d\tPromedio: %.2f\n", i+1, a->nota1, a->nota2, a->promedio);
		}


		return 0;



	return EXIT_SUCCESS;
}
void SetNota1(void* a){
	((Alumno*)a)->nota1 = rand()%10 + 1;
}
void SetNota2(void* a){
	((Alumno*)a)->nota2 = rand()%10 + 1;
}
void CalcularPromedio(void* a){
	((Alumno*)a)->promedio = (float)(((Alumno*)a)->nota1 + ((Alumno*)a)->nota2)/2;
}



