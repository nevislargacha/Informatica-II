#include <iostream>

using namespace std;

void ejercicio1();
void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
/*
¿Cuál es su dirección en memoria? ¿Cuántos bytes se dedican para almacenar cada elemento de array?
R// La direccion en memoria es @0x5995bff7b0 y debido a que se estan almacenando valores de tipo int para estos
se dedican 4 bytes para cada valor

¿Cuál es la dirección y el contenido en memoria del elemento array [3]?
R//El contenido o valor es 3 y su direccion en memoria es 0x5995bff7bc

Describe el efecto que tiene la función fun_b, sobre el arreglo array.
R//El efecto que tiene la funcion-b sobre el array es intercalar los valores, es decir,
el primer valor pasa a ser el ultimo y el ultimo valor pasa a ser el primero
*/

void ejercicio2();
void fun_c(double *a, int n, double *promedio, double*suma);

void ejercicio3();
/*
● b
R//
77

● b+2
R//
28

● *(b+2)
R//
28

● *(b+2)+1
R//
39

● *(*(b+2)+1)
R//
39

● b[3][1]
R//
3
● *b++
R//
*b++ no se puede usar directamente porque b es un arreglo y no puede incrementarse
*/

int main()
{
    ejercicio1();
    //ejercicio2();
}

void ejercicio1(){
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fun_b(array, 10);
}

void fun_a(int *px,int*py){
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
void fun_b(int a[], int tam){
    int f, l;
    int *b = a;
    for (f = 0, l = tam -1; f < l; f++, l--) {
        fun_a(&b[f], &b[l]);
    }
}

void ejercicio2(){
    double valores [] = {2.6,2.4,5.6,3.2,4.4,9.8};
    double promedio, suma;
    int cantidad_valores = size(valores);
    fun_c(valores, cantidad_valores, &promedio, &suma);

    cout << "la suma de los valores es: " << suma << endl;
    cout << "el promedio de los valores es: " << promedio << endl;
}

void fun_c(double *a, int n, double *promedio, double*suma){
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++)
        *suma += a[i];
    *promedio = *suma / n;
}

