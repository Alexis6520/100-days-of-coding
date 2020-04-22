#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 20
typedef struct T_pila 
{
	int tope;
	int arre[max];
}T_pila;
T_pila *iniciar_pila();
int aleatorio(int a, int b);
int pila_llena(T_pila *pila);
void push(T_pila *pila,int x);
int pila_vacia(T_pila *pila);
void imprime_pila(T_pila *pila);
int pop(T_pila *pila);

int main()
{
	srand(time(NULL));
	printf("Iniciando pila...\n");
	T_pila *pila=iniciar_pila(); //se inicia la pila 
	printf("\n|Ciclo de MAX vueltas, Push|\n");//llena la pila
	for (int i = 0; i < max; ++i)
	{
		int x=aleatorio(0,99);
		push(pila,x);
	}
	imprime_pila(pila);//imprime la pila
	int result=pila_llena(pila);//verifica si la pila esta llena
	if (result==1)
	{
		printf("\nPila llena\n");
	}
	else
	{
		printf("Pila no llena\n");
	}
	printf("\n|Ciclo de MAX/2 vueltas, pop|\n");//vacia 10 elementos de la pila
	for (int i = 0; i < max/2; ++i)
	{
		int x=pop(pila);
		printf("El elemento extraido es: %i\n",x);
	}
	imprime_pila(pila);
	while (pila->tope!=0)//vacia el resto de la pila
	{
		int x=pop(pila);
		printf("El elemento extraido es: %i\n",x);
	}
	result=pila_vacia(pila);//verifica si la pila esta vacia
	if (result==1)
	{
		printf("\nPila vacia\n");
	}
	else
	{
		printf("Pila no vacia\n");
	}
	free(pila);
	return 0;
}
T_pila *iniciar_pila()
{
	T_pila *pila=malloc(sizeof(T_pila));//asigna uns espacio de memoria a la pila
	pila->tope=0;//inicia tope a 0
	for (int i = 0; i < max; ++i)
	{
		pila->arre[i]=0;//inicia todo el arreglo a 0
	}
	return pila;//devuelve la pila inicializada
}
int pila_llena(T_pila *pila)
{
	if (pila->tope==max-1)//compara tope con max-1 para ver si esta llena
	{
		return 1;//devuelve 1 si esta llena
	}
	else
	{
		return 0;
	}
}
int pila_vacia(T_pila *pila)//compara tope con 0 para ver si esta vacia
{
	if (pila->tope==0)
	{
		return 1;//devuelve 1 si esta vacia
	}
	else
	{
		return 0;
	}
}
void push(T_pila *pila,int x)
{
	if (pila_llena(pila)!=1)//verifica que la pila no este llena
	{
		pila->tope++;//aumenta tope
		pila->arre[pila->tope]=x;//llena el espacio que indica el tope
	}
}
int pop(T_pila *pila)
{
	if (pila_vacia(pila)!=1)//checa que la pila no este vacia
	{
		int x=pila->arre[pila->tope];//extrae el dato
		pila->arre[pila->tope]=0;//iguala el elemento a 0
		pila->tope--;//disminuye tope
		return x;//devuelve elemento extraido
	}
}
int aleatorio(int a, int b)
{
	int dato=rand()%(b-a+1)+a;//devuelve un numero aleatorio
	return dato;
}
void imprime_pila(T_pila *pila)
{
	printf("\n");
	for (int i = 0; i < max; ++i)
	{
		printf("Arreglo[%i]=%i\n",i,pila->arre[i]);//recorre e imprime cada elemento del arreglo
	}
	printf("\n");
}