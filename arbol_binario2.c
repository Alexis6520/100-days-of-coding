/*Autor: KAREN YAMILI GUEVARA SALAZAR y ALEXIS ORTEGA MATUS <3
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
void preorden_indice2(NODO *raiz,int tabulaciones,int tamanio);
void llenado(int arre[],int tamanio);
void vaciar_memoria(NODO *raiz);
void alta(NODO *raiz,int info,int index);
NODO *buscar(NODO *raiz,int info);
void imprimir_resultado(NODO *res_busqueda, int x);

int main()
{
	srand(time(NULL));
	printf("||--------INICIANDO FASE 1 >:v -----------------------------||\n");
	int tamanio=9; //Establece el tamaño del arreglo
	int arre[]={120,87,43,65,140,99,130,22,56};//define el arreglo con el tamaño
	NODO *raiz=crear_arbol_altas(arre,tamanio);//Genera el arbol
	preorden_indice2(raiz,0,tamanio);
	int x=arre[4]; printf(">Buscando...\"%i\"\n",x);
	NODO *res_busqueda=buscar(raiz,x);
	imprimir_resultado(res_busqueda,x);
	x=rand()%51+200;
	res_busqueda=buscar(raiz,x); printf(">Buscando...\"%i\"\n",x);
	imprimir_resultado(res_busqueda,x);
	printf("||---------------FIN DE FASE 1 :) ---------------------------||\n");
	vaciar_memoria(raiz);
	printf("||--------INICIANDO FASE 2 >:v -----------------------------||\n");
	tamanio=10;
	llenado(arre,10);
	raiz=crear_arbol_altas(arre,tamanio);//Genera el arbol
	preorden_indice2(raiz,0,tamanio);
	x=arre[4];
	res_busqueda=buscar(raiz,x); printf(">Buscando...\"%i\"\n",x);
	imprimir_resultado(res_busqueda,x);
	x=rand()%51+200;
	res_busqueda=buscar(raiz,x); printf(">Buscando...\"%i\"\n",x);
	imprimir_resultado(res_busqueda,x);
	printf("||---------------FIN DE FASE 2 :) ---------------------------||\n");
	vaciar_memoria(raiz);
	printf(">Memoria liberada\n");
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
void preorden_indice2(NODO *raiz,int tabulaciones,int tamanio)
{
	if (raiz!=NULL)
	{
		NODO *izquierda=raiz->izquierda;//Genera auxiliares a la izquierda y derecha
		NODO *derecha=raiz->derecha;
		for (int i = 0; i <tabulaciones; ++i)
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
		for (int i = 0; i <tabulaciones; ++i)
		{
			printf("	");
		}
		printf("vacio");
		for (int i = 0; i < tamanio; ++i)
		{
			printf("--");
		}
		printf("\n");
	}
}
void llenado(int arre[], int tamanio)//llena el arreglo con tamanio numeros aleatorios
{
	for (int i = 0; i < tamanio; ++i)
	{
		arre[i]=rand()%41+10;
	}
}
void vaciar_memoria(NODO *raiz)//recorre el arbol en posorden y va liberando memoria
{
	if (raiz!=NULL)
	{
		vaciar_memoria(raiz->izquierda);
		vaciar_memoria(raiz->derecha);
		free(raiz);
	}
}
NODO *generar_nodo(int info,int index)//genera y devuelve el nodo
{
	NODO *nuevo=malloc(sizeof(NODO));
	nuevo->izquierda=NULL;
	nuevo->derecha=NULL;
	nuevo->info=info;
	nuevo->index=index;
	return nuevo;
}
void alta(NODO *raiz,int info,int index)//ubica e inserta el nuevo dato en la posicion correcta
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
			printf(">\"%i\" ya se encuentra en el arbol, bro.\n",info);//Si se repite devuelve un mensaje
		}
	}
}
NODO *buscar(NODO *raiz,int info)//ubica y devuelve el nodo con el valor solicitado
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
void imprimir_resultado(NODO *res_busqueda,int x)//imprime el resultado de la busqueda
{
	if (res_busqueda!=NULL)
	{
		printf("%i/%i\n",res_busqueda->info,res_busqueda->index);
	}
	else
	{
		printf("No existe: %i\n",x);
	}
}