#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void iniciar_arreglo_pares (int *arre,int cant);
void imprimir_arreglo (int *arre,int cant);

int main()
{
	srand(time(NULL)); 
	int cant=rand() % 21,*arre=new int(cant);
	cout<<"valor random= "<<cant<<endl;
	iniciar_arreglo_pares(arre,cant);
	imprimir_arreglo(arre,cant);
	cout<<endl<<"MEMORIA LIBERADA"<<endl;
	delete arre;
	return 0;
}
void iniciar_arreglo_pares (int *arre,int cant)
{
	for (int i = 0; i < cant; ++i)
	{
		*(arre+i)=2*i;
	}
}
void imprimir_arreglo (int *arre,int cant)
{
	for (int i = 0; i < cant; ++i)
	{
		cout<<"Arre["<<i<<"]= "<<*(arre+i)<<endl;
	}
}