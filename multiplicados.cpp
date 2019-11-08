#include <fstream>
#include <iostream>
#include <string.h>
using namespace std; 

float * read_file(string filename, int *n_points);
void multiplica(float *t, float *x_d, float *y_d, int n_points);
void writefile(string filename, float *t, int n_points);

int main()
{
    // En esta parte se cargan los datos de valores en x, y
    float *x=NULL;
    float *y=NULL;
    int n_x=0;
    int n_y=0;
    x = read_file("valores_x.txt", &n_x);
    y = read_file("valores_y.txt", &n_y);
    
    // Aquí se reserva espacio en memoria para el arreglo de la multiplicacion y se crea un puntero hacia este
    float *mul = NULL;
    mul = new float[n_x];
    float *p = mul;
    
    // En esta parte se efectua la multiplicacion pasando el puntero hacia los arreglos y su tamaño
    multiplica(p, x, y, n_x);
    
    // En esta parte se realiza la escritura del arreglo de la multiplicación en un archivo con nombre dado, se pasa el puntero de este arreglo y su tamaño
    writefile("multiplicados.dat", p, n_x);
    
    // Elimina de la memoria los arreglos creados durante la ejecución
    delete [] x;
    delete [] y;
    delete [] mul;
    
    return 0;
}

void multiplica(float *t, float *x_d, float *y_d, int n_points)
{
    // En este método se recibe el arreglo para guardar los productos
    for (int i=0; i < n_points; i++)
    {
        *(t+i)=x_d[i]*y_d[i];
    }
}

void writefile(string filename, float *t, int n_points)
{
    // Aquí se abre el archivo con el nombre dado por parámetro
    ofstream outfile;
    outfile.open(filename);
    
    // Luego se va imprimiendo en este los valores
    for (int j=0; j < n_points; j++)
    {
        outfile << *(t+j) << endl;
    }
    
    outfile.close();
}

float * read_file(string filename, int *n_points)
{
    int n_lines=0;
    ifstream infile; 
    string line;
    int i;
    float *array;
    /*cuenta lineas*/
    infile.open(filename); 
    getline(infile, line);
    while(infile)
    {
        n_lines++;
        getline(infile, line);
    }
    infile.close();
    *n_points = n_lines;
    
    /*reserva la memoria necesaria*/
    array = new float[n_lines];
    
    /*carga los valores*/
    i=0;
    infile.open(filename); 
    getline(infile, line);  
    while(infile)
    {
        array[i] = atof(line.c_str());
        i++;
        getline(infile, line);
    }
    infile.close();
    return array;
}