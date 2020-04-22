#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct //Se define la estrcutura como un tipo de variable
{
	char nombre[15];
	int matricula,promedio;
}alumno;
void iniciar_arreglo_alumno(alumno *arre,int cant);
void imprime_arre_alumnos(alumno *arre,int cant);
void alta_alumno(alumno *arre, int *apuntador_cant);

int main()
{
	srand(time(NULL));
	int cant=rand()%(31-5+1)+5; //Se le asigna un valor aleatorio a una variable del 5 al 30
	alumno *arre=(alumno*)malloc(cant*sizeof(alumno)); //Se reserva un espacio de memoria a un apuntador del tamaño de la variable anterior
	iniciar_arreglo_alumno(arre,cant); //Llena todos los espacios que se reservaron para el apuntador *arre con promedio aleatorio del 0 al 10
	imprime_arre_alumnos(arre,cant); //Imprime la lista creada anteriormente
	arre=(alumno*)realloc(arre,(cant+1)*sizeof(alumno)); //Se amplia el apuntador *arre un espacio de tamaño "alumno" para agregar al nuevo estudiante
	alta_alumno(arre,&cant); //Coloca un nuevo estudiante a la mitad de la lista y recorre a los demas
	imprime_arre_alumnos(arre,cant);//Imprime la nueva lista
	printf("MEMORIA LIBERADA\n");
	free(arre);//Se libera la memoria reservada por *arre
	return 0;
}
void iniciar_arreglo_alumno(alumno *arre,int cant)
{
	for (int i = 0; i < cant; ++i)				//Se hace un ciclo que inicia en 0 y termina en cant para llenar cada espacio
	{
		strcpy((arre+i)->nombre,"Alexis");
		(arre+i)->matricula=i+1;
		(arre+i)->promedio=rand()%11;
	}
}
void imprime_arre_alumnos(alumno *arre,int cant)
{
	printf("\nNombre | Matricula | Promedio\n"); 
	for (int i = 0; i < cant; ++i) //Se hace un ciclo que empieza en 0 y termina en cant para imprimir el arreglo
	{
		printf("%s       %i          %i\n",(arre+i)->nombre,(arre+i)->matricula,(arre+i)->promedio);
	}
}
void alta_alumno(alumno *arre, int *apuntador_cant)
{
	*apuntador_cant=*apuntador_cant+1; //El apuntador le suma 1 a la variable cant
	int div=(*apuntador_cant-1)/2; //Se saca la mitad de los alumnos creados
	for (int i = *apuntador_cant; i >= div; i--) //Se hace un ciclo que empieza desde el ultimo espacio disponible hasta la mitad y recorre los valores
	{
		strcpy((arre+i)->nombre,(arre+i-1)->nombre);
		(arre+i)->promedio=(arre+i-1)->promedio;
		(arre+i)->matricula=(arre+i-1)->matricula;
	}
	strcpy((arre+div)->nombre,"NUEVO"); //Se asignan los datos del nuevo alumno a la mitad de la lista
	(arre+div)->matricula=31;
	(arre+div)->promedio=rand()%11;
}
