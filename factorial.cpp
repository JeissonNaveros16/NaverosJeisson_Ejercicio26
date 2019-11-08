#include <iostream>
using namespace std;

int factorial(int t);

int main (int argc, char **argv)
{
    // Se crea el arreglo y el puntero con el tamaño ingresado por parámetro en la ejecución del main
    int n = atoi(argv[1]);
    int *lista = NULL;
    lista = new int[n * n];
    int *p = lista;
    
    // Se recorre el arreglo haciendo uso de los punteros y se saca el factorial del indice
    for(int i = 0; i<n; i++)
    {
        *(p+i) = factorial(i);
        cout << " "<< lista[i] << endl;
    }
    
    // Se borra el arreglo creado durante este proceso
    delete [] lista;
    return 0;
}

int factorial(int t)
{
    // Este método simplemente retorna el factorial de lo que le manden
    double p = 1;
    for( int j=t; j>0; j--)
    {
        p = p*j;
    }
    return p;
}