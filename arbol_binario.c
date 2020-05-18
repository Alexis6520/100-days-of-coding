/*Autor: KAREN YAMILI GUEVARA SALAZAR y ALEXIS ORTEGA MATUS
Fecha:13/05/2020
Generacion, recorrido e impresion de un arbol binario de n elementos*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct nodo
{
	struct nodo *izquierda;
	struct nodo *derecha;
	int index;
	int info;
} NODO;
NODO *crear_arbol_altas(int arre[], int tamanio);
NODO *generar_nodo(int info,int index);
void copiar_izq(int arre_izq[],int arre[],int tamanio);
void copiar_der(int arre_der[],int arre[],int tamanio,int desde);
void preorden_indice2(NODO *raiz,int tabulaciones,int tamanio);
void llenado(int arre[],int tamanio);
void preorden(NODO *raiz);
void inorden(NODO *raiz);
void posorden(NODO *raiz);
void vaciar_memoria(NODO *raiz);
void alta(NODO *raiz,int info,int index);
NODO *buscar(NODO *raiz,int info);

int main()
{
	srand(time(NULL));
	int tamanio=9; //Establece el tamaño del arreglo
	int arre[]={120,87,43,65,140,99,130,22,56};//define el arreglo con el tamaño
	NODO *raiz=crear_arbol_altas(arre,tamanio);//Genera el arbol
	preorden_indice2(raiz,0,tamanio);
	int x=arre[4];
	NODO *res_busqueda=buscar(raiz,x);
	if (res_busqueda!=NULL)
	{
		printf("%i/%i\n",res_busqueda->info,res_busqueda->index);
	}
	else
	{
		printf("No existe: %i\n",x);
	}
	x=rand()%51+200;
	res_busqueda=buscar(raiz,x);
	if (res_busqueda!=NULL)
	{
		printf("%i/%i\n",res_busqueda->info,res_busqueda->index);
	}
	else
	{
		printf("No existe: %i\n",x);
	}
	printf("||---------------------------------------------------------||\n");
	vaciar_memoria(raiz);
	tamanio=10;
	llenado(arre,10);
	raiz=crear_arbol_altas(arre,tamanio);//Genera el arbol
	preorden_indice2(raiz,0,tamanio);
	x=arre[4];
	res_busqueda=buscar(raiz,x);
	if (res_busqueda!=NULL)
	{
		printf("%i/%i\n",res_busqueda->info,res_busqueda->index);
	}
	else
	{
		printf("No existe: %i\n",x);
	}
	x=rand()%51+200;
	res_busqueda=buscar(raiz,x);
	if (res_busqueda!=NULL)
	{
		printf("%i/%i\n",res_busqueda->info,res_busqueda->index);
	}
	else
	{
		printf("No existe: %i\n",x);
	}
	printf("||---------------------------------------------------------||\n");
	vaciar_memoria(raiz);
	return 0;
}

NODO *crear_arbol_altas(int arre[], int tamanio)
{
	NODO *raiz=generar_nodo(arre[0],0);
	for (int i = 1; i < tamanio; ++i)
	{
		alta(raiz,arre[i],i);
	}
	return raiz;
}
void copiar_izq(int arre_izq[],int arre[],int tamanio)
{
	for (int i = 0; i < tamanio; ++i)//Copia la cantidad de elementos segun tamaño
	{
		arre_izq[i]=arre[i];
	}
}
void copiar_der(int arre_der[],int arre[],int tamanio,int desde)
{
	for (int i = 0; i < tamanio; i++)//Copia cantidadd de elemtos segun tamaño desde el elemento indicado
	{
		arre_der[i]=arre[desde+i];
	}
}
void preorden_indice2(NODO *raiz,int tabulaciones,int tamanio)
{
	if (raiz!=NULL)
	{
		NODO *izquierda=raiz->izquierda;//Genera auxiliares a la izquierda y derecha
		NODO *derecha=raiz->derecha;
		for (int i = 0; i <tabulaciones; ++i)//usa el index del nodo para determinar la cantidad de tabulaciones
		{
			printf("	");
		}
		printf("%i/%i",raiz->info,raiz->index);//imprime dato
		for (int i = 0; i < tamanio; ++i)//agrega n cantidad de -- para que se vea bonito :)
		{
			printf("--");
		}
		printf("\n");
		preorden_indice2(izquierda,tabulaciones+1,tamanio-1);//llamada recursiva con la izquierda
		preorden_indice2(derecha,tabulaciones+1,tamanio-1);//llamada recursiva con la derecha
	}
	else
	{
		for (int i = 0; i <tabulaciones; ++i)//usa el index del nodo para determinar la cantidad de tabulaciones
		{
			printf("	");
		}
		printf("vacio");
		for (int i = 0; i < tamanio; ++i)//agrega n cantidad de -- para que se vea bonito :)
		{
			printf("--");
		}
		printf("\n");
	}
}
void llenado(int arre[], int tamanio)
{
	for (int i = 0; i < tamanio; ++i)
	{
		arre[i]=rand()%41+10;
	}
}
void preorden(NODO *raiz)
{
	if (raiz!=NULL)
	{
		NODO *izquierda=raiz->izquierda;
		NODO *derecha=raiz->derecha;
		printf("%i-",raiz->info);
		preorden(izquierda);
		preorden(derecha);
	}
}
void inorden(NODO *raiz)
{
	if (raiz!=NULL)
	{
		inorden(raiz->izquierda);
		printf("%i-",raiz->info);
		inorden(raiz->derecha);
	}
}
void posorden(NODO *raiz)
{
	if (raiz!=NULL)
	{
		posorden(raiz->izquierda);
		posorden(raiz->derecha);
		printf("%i-",raiz->info);
	}
}
void vaciar_memoria(NODO *raiz)
{
	if (raiz!=NULL)
	{
		vaciar_memoria(raiz->izquierda);
		vaciar_memoria(raiz->derecha);
		free(raiz);
	}
}
NODO *generar_nodo(int info,int index)
{
	NODO *nuevo=malloc(sizeof(NODO));
	nuevo->izquierda=NULL;
	nuevo->derecha=NULL;
	nuevo->info=info;
	nuevo->index=index;
	return nuevo;
}
void alta(NODO *raiz,int info,int index)
{
	if (raiz!=NULL)
	{
		if (info < raiz->info)
		{
			if (raiz->izquierda!=NULL)
			{
				alta(raiz->izquierda,info,index);
			}
			else
			{
				raiz->izquierda=generar_nodo(info,index);
			}
		}
		else if (info > raiz->info)
		{
			if (raiz->derecha!=NULL)
			{
				alta(raiz->derecha,info,index);
			}
			else
			{
				raiz->derecha=generar_nodo(info,index);
			}
		}
		else
		{
			printf(">La informacion ya se encuentra en el arbol, bro.\n");
		}
	}
}
NODO *buscar(NODO *raiz,int info)
{
	if (raiz!=NULL)
	{
		if (info < raiz->info)
		{
			buscar(raiz->izquierda,info);
		}
		else if (info > raiz->info)
		{
			buscar(raiz->derecha,info);
		}
		else
		{
			return raiz;
		}
	}
	else
	{
		return NULL;
	}
}