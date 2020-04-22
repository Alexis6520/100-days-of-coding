/*Autor: Alexis Ortega Matus
Fecha:20/02/2020
Generacion de lista de cantidad aleatoria con nodos y manipulacion de los mismos*/
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
Alumno *insertar_inicio(Alumno *lista);
void insertar_ultimo(Alumno *lista);
void imprimir_lista(Alumno *lista);
void insertar_desp_matri(int cant, Alumno *lista);
Alumno *borrar_con_matricula(Alumno *lista, int matri);
void liberar_memoria (Alumno *lista);

int main()
{
	int cant;
	srand(time(NULL));
	cant=rand()%26 + 5; //se define la variable aleatoria que determina la cantidad de alumnos
	Alumno *lista=NULL; //se crea un apuntador vacio que se usara como lista
	lista=iniciar_lista(cant); //se iguala la lista ala funcion de iniciar
	imprimir_lista(lista); //se llama a la funcion imprimir y se mete *lista como parametro
	printf("\n**INSERTA ULTIMO NUEVO31**\n");
	insertar_ultimo(lista); //se llama a la funcion ultimo
	imprimir_lista(lista); //imprime
	printf("\n**INSERTA PRIMERO NUEVO32**\n");
	lista=insertar_inicio(lista); //se llama a la funcion primero
	imprimir_lista(lista);//imprime
	printf("\n**INSERTA DESPUES DE MATRICULA NUEVO33**\n");
	insertar_desp_matri(cant,lista); //se llama a la funcion despues de matricula
	imprimir_lista(lista);//imprime
	printf("\n**BORRAR NUEVO31**\n");
	lista=borrar_con_matricula(lista,31); //se llama a la funcion borrar
	imprimir_lista(lista);//imprime
	printf("\n**BORRAR NUEVO32**\n");
	lista=borrar_con_matricula(lista,32); //se llama a la funcion borrar
	imprimir_lista(lista);//imprime
	printf("\n**BORRAR NUEVO33**\n");
	lista=borrar_con_matricula(lista,33);//se llama a la funcion borrar
	imprimir_lista(lista);//imprime
	printf("MEMORIA LIBERADA\n");
	liberar_memoria(lista);//se libera la memoria
	return 0;
}
Alumno *iniciar_lista(int cant)
{
	Alumno *nuevo=NULL,*auxiliar=NULL,*lista=NULL; //se declara el nodo, el auxiliar y una cabecera con nombre lista
	Alumno *primero=(Alumno*)malloc(sizeof(Alumno));
	strcpy(primero->nombre, "Alexis");//se genera el primer nodo
	primero->matricula=1;
	primero->promedio=rand()%11;
	lista=primero; //se apunta la cabecera al primer nodo
	auxiliar=lista; //se apunta el auxiliar al primer nodo
	for (int i=2; i <= cant; i++) //se inicia un ciclo de 2 a cant
	{
		nuevo=(Alumno*)malloc(sizeof(Alumno)); //se agrega un nuevo elemnto
		strcpy(nuevo->nombre, "Alexis");
		nuevo->matricula=i;
		nuevo->promedio=rand()%11;
		auxiliar->siguiente=nuevo; //se enlaza el nodo anterior al nodo nuevo
		auxiliar=nuevo; //se iguala el apuntador auxiliar al nuevo elemento
	}
	return lista; //se devuelve la lista creada
}
Alumno *insertar_inicio(Alumno *lista)
{
	Alumno *pri=lista,*inicio=NULL; //se declara una variable auxiliar que apunta al primer nodo
	inicio=(Alumno*)malloc(sizeof(Alumno));//se crea el nuevo nodo que sera el primer elemento
	strcpy(inicio->nombre, "Nuevo32");
	inicio->matricula=32;
	inicio->promedio=rand()%11;//se capturan los datos
	inicio->siguiente=pri; //se enlaza el nuevo nodo al que anteriormente era el primero
	lista=inicio;//apuntamos la cabecera al nuevo primer nodo
	return lista;//se devuelve la nueva cabecera
}
void insertar_ultimo(Alumno *lista)
{
	Alumno *ap=lista, *nuevo=NULL; //se iguala un auxiliar a la cabecera
	while(ap->siguiente!=NULL) //inicia un ciclo que continuara mientras el apartado siguiente sea diferente a NULL
	{
		ap=ap->siguiente; //se iguala el auxiliar al siguiente
	}
	nuevo=(Alumno*)malloc(sizeof(Alumno)); //se crea el nuevo nodo
	strcpy(nuevo->nombre, "Nuevo31");
	nuevo->matricula=31;
	nuevo->promedio=rand()%11;
	ap->siguiente=nuevo; //se enlaza el ultimo nodo al nuevo 
	nuevo->siguiente=NULL;	//se enlaza el nuevo nodo a NULL y se convierte en el ultimo elemento	
}
void insertar_desp_matri(int cant, Alumno *lista)
{
	int matri=rand ()%(cant-2)+2; //se saca una matricula aleatoria 
	Alumno *auxiliar=lista,*nuevo=NULL; //se iguala un auxiliar al primer nodo
	while(auxiliar->matricula != matri)//inicia un ciclo que se repite mientras la matricula del auxiliar sea diferente a matri
	{
		auxiliar=auxiliar->siguiente; //se apunta al siguiente nodo
	}
	Alumno *front=auxiliar->siguiente; //se declara un auxiliar que apunta al nodo despues de la matricula
	nuevo=(Alumno*)malloc(sizeof(Alumno));// se crea el nuevo nodo
	strcpy(nuevo->nombre, "Nuevo33");
	nuevo->matricula=33;
	nuevo->promedio=rand()%11;
	nuevo->siguiente=front; //se enlaza el nuevo nodo al siguiente nodo
	auxiliar->siguiente=nuevo;//se enlaza el nodo anterior al nuevo 		
}
void imprimir_lista(Alumno *lista)
{
 Alumno *ap=lista; //se iguala un apuntador a la cabecera de la lista
 printf("|NOMBRE|PROMEDIO|MATRICULA|\n");
	while (ap != NULL)
	{
		printf("%s 	   %i 	    %i\n",ap->nombre,ap->promedio,ap->matricula); //imprime datos
		ap=ap->siguiente;//se recorre al siguiente elemento
	}
}
Alumno *borrar_con_matricula(Alumno *lista, int matri)
{
	Alumno *borrar=lista,*back=NULL,*front=NULL; //se apunta un auxiliar al primer elemento
	switch(matri) //se crea un switch para elegir el metodo de eliminacion del nodo
	{
		case 31:	while(borrar->matricula != matri) //inicia ciclo que se cumple si la matricula del auxiliar es diferente a la indicada
					{
						back=borrar;//se apunta un back a lo que apuntaba borrar
						borrar=borrar->siguiente;//se apunta borrar al siguiente elemento
					}
					free(borrar);//se borra el nodo
					back->siguiente=NULL;//back se iguala a NULL para convertirse en el ultimo elemento
		break;
		case 32:	lista=borrar->siguiente;//se apunta la cabecera al segundo elemento
					free(borrar);//se borra el primer elemnto con el auxiliar
		break;
		case 33:	while(borrar->matricula != matri)//inicia ciclo que se cumple si la matricula del auxiliar es diferente a la indicada
					{
						back=borrar;//se apunta un back a lo que apuntaba borrar
						borrar=borrar->siguiente;//se apunta borrar al siguiente elemento
					}
					front=borrar->siguiente; //se apunta front al elemento despues de la matricula indicada
					back->siguiente=front; //se enlaza el elemento anterior al posterior
					free(borrar);//se borra el nodo indicado
		break;
		default: printf("PARAMETRO MATRI INVALIDO\n");
	}
	return lista;//se devuelve la lista actualizada
}
void liberar_memoria (Alumno *lista)
{
    Alumno *backup=NULL; //se declara un auxiliar 
    while (lista != NULL)//inicia ciclo que sigue mientras sea diferente a NULL
    {
        backup=lista->siguiente;//se apunta el auxiliar al siguiente nodo
        free(lista);//se borra el nodo
        lista=backup;//se iguala la cabecera al auxiliar
    }
}
