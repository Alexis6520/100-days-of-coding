#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct alumno //Se define la estructura de los alumnos
{
	char nombre[9];
	int matricula;
	int promedio;
    struct alumno *siguiente;
};
typedef struct alumno Alumno; //se define la estructura como tipo de variable
Alumno *iniciar_lista(int cant);
void imprimir_lista(Alumno *lista);
void liberar_memoria (Alumno *lista);

int main()
{
	int cant;
	srand(time(NULL));
	cant=rand()%26 + 5; //se define la variable aleatoria que determina la cantidad de alumnos
	Alumno *lista=NULL; //se crea un apuntador vacio que se usara como lista
	lista=iniciar_lista(cant); //se iguala la lista ala funcion de iniciar
	imprimir_lista(lista); //se llama a la funcion imprimir y se mete *lista como parametro
	liberar_memoria(lista);
	return 0;
}
Alumno *iniciar_lista(int cant)
{
	Alumno *nueva_lista=NULL,*auxiliar=NULL; //se crea una varible nueva_lista que sera devuelto por la funcion y un apuntador que servira de referencia
	for (cant; cant > 0; cant--) //se inicia un ciclo en cuenta regresiva
	{
		nueva_lista=(Alumno*)malloc(sizeof(Alumno)); //se agrega un nuevo elemnto al apuntador
		strcpy(nueva_lista->nombre, "Alexis");
		nueva_lista->matricula=cant;
		nueva_lista->promedio=rand()%11;//se capturan los datos
		nueva_lista->siguiente=auxiliar;//se iguala la propiedad siguiente al apuntador de referencia (esta en null)
		auxiliar=nueva_lista; //se iguala el apuntador auxiliar al nuevo elemento
	}
	return nueva_lista; //se devuelve la lista creada
}
void imprimir_lista(Alumno *lista)
{
 Alumno *ap=lista; //se iguala un apuntador a la cabecera de la lista
 printf("|NOMBRE|PROMEDIO|MATRICULA|\n");
	while (ap != NULL)
	{
		printf("%s 	   %i 	    %i\n",ap->nombre,ap->promedio,ap->matricula); //imprime datos
		ap=ap->siguiente;//se recorre al siguiente elemto
	}
}
void liberar_memoria (Alumno *lista)
{
    Alumno *backup=NULL;
    while (lista != NULL)
    {
        backup=lista->siguiente;
        free(lista);
        lista=backup;
    }
}
