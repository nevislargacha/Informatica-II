#include <iostream> // Inclusión de la biblioteca estándar para entrada y salida

using namespace std; // Uso del espacio de nombres estándar para evitar escribir std::

// Declaraciones anticipadas (prototipos) de las funciones utilizadas en el programa
void ejercicio1(); // Prototipo de la función ejercicio1
void fun_a(int *px, int *py); // Prototipo de la función que intercambia dos valores enteros por punteros
void fun_b(int a[], int tam); // Prototipo de la función que invierte un arreglo

/*
Comentarios de reflexión del ejercicio 1:

¿Cuál es su dirección en memoria? ¿Cuántos bytes se dedican para almacenar cada elemento de array?
R// La dirección en memoria es algo como @0x5995bff7b0 y como se almacenan valores de tipo int,
se dedican 4 bytes por cada valor.

¿Cuál es la dirección y el contenido en memoria del elemento array[3]?
R// El contenido o valor es 3 y su dirección en memoria sería algo como 0x5995bff7bc (dependiendo de la arquitectura).

Describe el efecto que tiene la función fun_b sobre el arreglo array.
R// La función fun_b invierte los elementos del arreglo, cambiando el primer valor por el último y así sucesivamente.
*/

void ejercicio2(); // Prototipo de la función ejercicio2
void fun_c(double *a, int n, double *promedio, double *suma); // Prototipo de la función que calcula la suma y el promedio de un arreglo

void ejercicio3(); // Prototipo de una función no implementada aquí

/*
Comentarios teóricos sobre punteros y acceso a arreglos bidimensionales:

● b
R// 77

● b+2
R// 28

● *(b+2)
R// 28

● *(b+2)+1
R// 39

● *(*(b+2)+1)
R// 39

● b[3][1]
R// 3

● *b++
R// *b++ no se puede usar directamente porque b es un arreglo y no puede incrementarse (es un puntero constante)
*/

int main() {
    ejercicio1(); // Llamada a la función ejercicio1
    // ejercicio2(); // Comentado: llamada opcional a ejercicio2
}

// Función que ejecuta el ejercicio 1
void ejercicio1() {
    // Declaración e inicialización de un arreglo de 10 enteros del 0 al 9
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Llamada a la función que invierte el arreglo
    fun_b(array, 10);
}

// Función que intercambia dos valores enteros utilizando punteros
void fun_a(int *px, int *py) {
    int tmp = *px;  // tmp almacena el valor apuntado por px
    *px = *py;      // el valor apuntado por px se reemplaza por el valor apuntado por py
    *py = tmp;      // el valor apuntado por py se reemplaza por el valor original de px (almacenado en tmp)
}

// Función que invierte los valores de un arreglo utilizando punteros
void fun_b(int a[], int tam) {
    int f, l;        // f es el índice inicial, l es el índice final
    int *b = a;      // b es un puntero que apunta al arreglo a

    // Ciclo para recorrer el arreglo desde ambos extremos hacia el centro
    for (f = 0, l = tam - 1; f < l; f++, l--) {
        // Se intercambian los valores en las posiciones f y l
        fun_a(&b[f], &b[l]);
    }
}

// Función que ejecuta el ejercicio 2
void ejercicio2() {
    // Declaración e inicialización de un arreglo de valores double
    double valores[] = {2.6, 2.4, 5.6, 3.2, 4.4, 9.8};

    double promedio, suma; // Variables para almacenar el promedio y la suma
    int cantidad_valores = size(valores); // Obtiene el número de elementos del arreglo

    // Llamada a la función que calcula la suma y el promedio
    fun_c(valores, cantidad_valores, &promedio, &suma);

    // Muestra los resultados por pantalla
    cout << "la suma de los valores es: " << suma << endl;
    cout << "el promedio de los valores es: " << promedio << endl;
}

// Función que calcula la suma y el promedio de un arreglo de double
void fun_c(double *a, int n, double *promedio, double *suma) {
    int i;
    *suma = 0.0; // Inicializa la suma

    // Recorre el arreglo y acumula la suma de sus elementos
    for (i = 0; i < n; i++)
        *suma += a[i];

    // Calcula el promedio
    *promedio = *suma / n;
}


