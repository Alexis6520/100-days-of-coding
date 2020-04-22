#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void intercambiar (int *a, int *b);

int main() 
{
	srand(time(NULL)); 
	int x=rand() % 100,y=rand() % 100;
	cout<<"X="<<x<<" Y="<<y<<endl;
	cout<<endl<<"INTERCAMBIANDO VALORES..."<<endl; 
	intercambiar(&x,&y);
	cout<<endl<<"VALORES INTERCAMBIADOS"<<endl<<"X="<<x<<" Y="<<y<<endl;
	return 0;
}
void intercambiar (int *a, int *b)
{
	int i=*a;
	*a=*b;
	*b=i;
}
