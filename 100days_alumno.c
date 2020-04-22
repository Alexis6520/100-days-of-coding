#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
	char nombre[15];
	int matricula,promedio;
}alumno;
void iniciar_arreglo_alumno(alumno *arre,int cant);
void imprime_arre_alumnos(alumno *arre,int cant);

int main()
{
	srand(time(NULL));
	int cant=rand()%(31-5+1)+5;
	alumno *arre=(alumno*)malloc(cant*sizeof(alumno));
	iniciar_arreglo_alumno(arre,cant);
	imprime_arre_alumnos(arre,cant);
	printf("MEMORIA LIBERADA\n");
	free(arre);
	return 0;
}
void iniciar_arreglo_alumno(alumno *arre,int cant)
{
	for (int i = 0; i < cant; ++i)
	{
		strcpy((arre+i)->nombre,"Alexis");
		(arre+i)->matricula=i+1;
		(arre+i)->promedio=rand()%11;
	}
}
void imprime_arre_alumnos(alumno *arre,int cant)
{
	printf("Nombre | Matricula | Promedio\n");
	for (int i = 0; i < cant; ++i)
	{
		printf("%s       %i          %i\n",(arre+i)->nombre,(arre+i)->matricula,(arre+i)->promedio);
	}
}