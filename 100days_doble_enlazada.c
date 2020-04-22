#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct alumno 
{
	char nombre[9];
	int matricula;
	int promedio;
    struct alumno *siguiente;
    struct alumno *anterior;
};
typedef struct alumno Alumno; //se define el tipo de varible Alumno del que se compondran los nodos
struct T_lista
{
	Alumno *cabecera;
	Alumno *ultimo;
	int tamanio;
};
typedef struct T_lista T_lista; //Se define el tipo de variable lista que usara la lista
T_lista *iniciar_lista_doble(int cant);
void imprimir_lista_doble_ida(T_lista *lista);
void imprimir_lista_doble_vuelta(T_lista *lista);
Alumno *llenar_nodo(Alumno *nuevo,char nombre[10],int matricula);
T_lista *insertar_en_posicion(T_lista *lista,int pos, Alumno *nuevo);
T_lista *borrar_posicion(T_lista *lista,int pos);
int aleatorio(int a, int b);
void libera_memoria(Alumno *cabecera);
int main()
{
	srand(time(NULL));
	T_lista *lista=(T_lista*)malloc(sizeof(T_lista));//se asigna espacio de memoria para lista
	lista->tamanio=aleatorio(5,30); printf("%i\n",lista->tamanio); //se establece el tamaño de la lista de 5 a 30
	lista=iniciar_lista_doble(lista->tamanio);//se inicializa la lista en base al tamaño
	imprimir_lista_doble_ida(lista);//imprime de ida y vuelta
	imprimir_lista_doble_vuelta(lista);
	Alumno *nuevo41=(Alumno*)malloc(sizeof(Alumno));//genera un nuevo nodo
	nuevo41=llenar_nodo(nuevo41,"Nuevo41",41);
	printf("\nINSERTAR AL FINAL\n"); 
	lista=insertar_en_posicion(lista,lista->tamanio-1,nuevo41); //inserta nuevo nodo al final
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	Alumno *nuevo42=(Alumno*)malloc(sizeof(Alumno));
	nuevo41=llenar_nodo(nuevo42,"Nuevo42",42);
	printf("\nINSERTAR AL INICIO\n"); 
	lista=insertar_en_posicion(lista,0,nuevo41);//inserta nuevo nodo al inicio
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	int pos=(lista->tamanio)/2;//se inicializa una variable de tipo entero igual a la mitad del tamaño de la lista
	printf("BORRAR AL DE POS EN MEDIO\n");
	lista=borrar_posicion(lista,pos); //borra el nodo en la posicion anteriormente indicada
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	printf("\nBORRAR AL PRIMERO\n");
	lista=borrar_posicion(lista,0); //borra al primer nodo
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	printf("\nBORRAR AL ULTIMO\n");
	lista=borrar_posicion(lista,lista->tamanio-1);//borra el ultimo nodo
	imprimir_lista_doble_ida(lista);
	imprimir_lista_doble_vuelta(lista);
	libera_memoria(lista->cabecera);//vacia la lista
	free(lista);//libera la lista
	printf("MEMORIA LIBERADA\n");
	return 0;
}
T_lista *iniciar_lista_doble(int cant)
{
	Alumno *nuevo=NULL,*auxiliar;
	T_lista *lista=(T_lista*)malloc(sizeof(T_lista)); //se genera una lista
	for (int i = cant; i > 0; i--)//contador en reversa que va desde tamaño a 1
	{
		nuevo=(Alumno*)malloc(sizeof(Alumno)); //se genera el nodo
		nuevo=llenar_nodo(nuevo,"Alexis",i);
		if (i==cant)	
		{	
			nuevo->siguiente=NULL; //si el nodo a generar es el ultimo, siguiente=NULL y se declara como el ultimo de la lista
			lista->ultimo=nuevo;
		}
		else
		{
			nuevo->siguiente=auxiliar; //Para el resto de los nodos, su apartado siguiente es igual a donde apunta auxiliar
		}
		auxiliar->anterior=nuevo;//se enlaza el nodo viejo al nuevo
		auxiliar=nuevo; //se mueve el auxiliar al nodo nuevo
	}
	lista->cabecera=nuevo;//al terminar, la cabecera apuntara al ultimo nodo generado ya que la lista se creo en reversa
	lista->tamanio=cant;//se iguala el tamaño a la nueva lista
	return lista;//devuelve la lista creada
}
void imprimir_lista_doble_ida(T_lista *lista)
{
	Alumno *ap=lista->cabecera; //auxiliar apunta a la cabecera
	int i=0;//se usa i para señalar la posicion
 	printf("|POSICION|NOMBRE|PROMEDIO|MATRICULA|\n");
	while (ap != NULL)//imprime mientras ap sea diferente a NULL
	{
		printf("%i        %s   %i 	    %i\n",i,ap->nombre,ap->promedio,ap->matricula); 
		ap=ap->siguiente;//se mueve al siguiente nodo
		i++;//indica la siguiente posicion 
	}
}
void imprimir_lista_doble_vuelta(T_lista *lista)
{
	Alumno *ap=lista->ultimo; //auxiliar apunta a la cola o el ultimo
	int i=(lista->tamanio)-1;//se iguala i al tamaño-1 para indicar la posicion
 	printf("|POSICION|NOMBRE|PROMEDIO|MATRICULA|\n");
	while (ap != NULL)
	{
		printf("%i        %s   %i 	    %i\n",i,ap->nombre,ap->promedio,ap->matricula); 
		ap=ap->anterior;//se recorre al nodo anterior
		i--;//indica la posicion anterior
	}
}
Alumno *llenar_nodo(Alumno *nuevo,char nombre[10],int matricula)
{
	strcpy(nuevo->nombre, nombre);//llena el nombre del alumno
	nuevo->matricula=matricula;//llena la matricula
	nuevo->promedio=rand()%11;//lena el promedio
	return nuevo;//devuelve el nodo
}
T_lista *insertar_en_posicion(T_lista *lista,int pos, Alumno *nuevo)
{
	Alumno *auxiliar=lista->cabecera,*back=NULL,*cola=lista->ultimo;//se apunta aux a la cabecera y cola al ultimo
	int i;
	for (i = 0; i < pos; ++i)//va de 0 a la posicion indicada
	{
		auxiliar=auxiliar->siguiente;//se mueve el auxiliar al siguinte nodo
		back=auxiliar->anterior;//y back conserva al nodo anterior
	}
	if (i==0) //si es al inicio
	{
		nuevo->siguiente=auxiliar;//se enlaza nuevo al que era el primero
		auxiliar->anterior=nuevo;//se enlaza el que era el primero al nuevo
		lista->cabecera=nuevo;//se iguala la cabecera al nuevo
		lista->tamanio=lista->tamanio+1;//se actualiza el tamaño
		return lista; //devuelve la lista
	}
	else 
	{
		if (auxiliar==cola)// si es el ultimo
		{
			cola->siguiente=nuevo;//se enlaza el que era el ultimo al nuevo
			nuevo->anterior=cola;//se enlaza el nuevo al que era el ultimo
			nuevo->siguiente=NULL;
			lista->ultimo=nuevo;//se actualiza el ultimo
			lista->tamanio=lista->tamanio+1;//se actualiza el tamaño
			return lista;
		}
		else //si esta en medio
		{
			back->siguiente=nuevo;//se enlaza el anterior al nuevo
			nuevo->anterior=back;//enlaza el nuevo al anterior
			nuevo->siguiente=auxiliar;//enlaza el nuevo al siguinte
			auxiliar->anterior=nuevo;//enlaza el siguiente al nuevo
			lista->tamanio=lista->tamanio+1;
			return lista;
		}
	}
}
T_lista *borrar_posicion(T_lista *lista,int pos)
{
	Alumno *auxiliar=lista->cabecera,*back=NULL,*front=NULL;//se crea auxiliar=cabecera
	int i;
	for (i = 0; i < pos; ++i)//va de 0 a la posicion indicada
	{
		auxiliar=auxiliar->siguiente;
		front=auxiliar->siguiente;
		back=auxiliar->anterior;
	}
	if (i==0)//si es al inicio
	{
		lista->cabecera=auxiliar->siguiente;//se actualiza la cabecera
		(lista->cabecera)->anterior=NULL;
		free(auxiliar);//borra
		lista->tamanio=lista->tamanio-1;//actualiza el tamaño
		return lista;
	}
	else 
	{
		if (auxiliar==lista->ultimo)//si es el ultimo
		{
			back->siguiente=NULL;
			lista->ultimo=back,//actualiza el ultimo
			free(auxiliar);//borra
			lista->tamanio=lista->tamanio-1;
			return lista;
		}
		else
		{
			back->siguiente=front;//se enlaza el anterior al siguiente
			front->anterior=back;//enlaza el de enfrente al anterior
			free(auxiliar);//borra
			lista->tamanio=lista->tamanio-1;
			return lista;
		}
	}
}
int aleatorio(int a, int b)
{
	int tamanio;
	tamanio=rand()%(b-a+1)+a;
	return tamanio;
}
void libera_memoria(Alumno *cabecera)
{
	Alumno *backup=NULL;
	while (cabecera!=NULL)
	{
		backup=cabecera->siguiente;//se apunta al siguiente elemento
		free(cabecera); //se borra a donde apunta la cabecera
		cabecera=backup;//se actualiza la cabecera a donde apunta backup
	}
}
