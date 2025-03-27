#include <cmath>
#include <iostream>

using namespace std;

void ejercicio1();

void ejercicio2();

void ejercicio3();

void ejercicio4();

void ejercicio5();

void ejercicio7();

void ejercicio9();

void ejercicio11();

void ejercicio13();

void ejercicio15();

void ejercicio17();

void ejercicio19();

void ejercicio21();

void ejercicio23();

void ejercicio25();

void ejercicio27();

void ejercicio29();

int main()
{
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    //ejercicio4();
    //ejercicio5();
    //ejercicio7();
    //ejercicio9();
    //ejercicio11();
    //ejercicio13();
    //ejercicio15();
    //ejercicio17();
    ejercicio19();
    //ejercicio21();
    //ejercicio23();
    //ejercicio25();
    //ejercicio27();
    //ejercicio29();

    return 0;
}

void ejercicio1(){

    int a, b, c = 0;

    cout << "Ingrese el primer numero:";
    cin >> a;
    cout << "Ingrese el segundo numero:";
    cin >> b;

    c = a%b;

    cout << "El residuo de la division " << a << "/" << b << " es: " << c << endl;
}

void ejercicio2(){

    int a;

    cout << "Ingrese un numero para validar:";
    cin >> a;

    if( a%2 == 0)
        cout << "el numero " << a << " es par" << endl;
    else{
        cout << "el numero " << a << " es impar" << endl;
    }
}

void ejercicio3(){

    int a, b;

    cout << "Ingrese el primer numero:";
    cin >> a;
    cout << "Ingrese el segundo numero:";
    cin >> b;

    if(a > b)
        cout << "El mayor es: " << a << endl;
    else{
        cout << "El mayor es: " << b << endl;
    }
}

void ejercicio4(){

    int a, b;

    cout << "Ingrese el primer numero:";
    cin >> a;
    cout << "Ingrese el segundo numero:";
    cin >> b;

    if(a < b)
        cout << "El menor es: " << a << endl;
    else{
        cout << "El menor es: " << b << endl;
    }
}

void ejercicio5(){

    float a, b;
    float c;

    cout << "Ingrese el primer numero:";
    cin >> a;
    cout << "Ingrese el segundo numero:";
    cin >> b;
    c = a / b;

    cout << "el resultado es " << a << "/" <<  b << " = " << round(c) << endl;

}

void ejercicio7(){

    int a, b;


    cout << "Ingrese el numero N:";
    cin >> a;

    for (int i = 1; i <= a; ++i) {
        b = i + b;
    }

    cout << "La sumatoria desde 0 hasta " << a << "es: " << b << endl;

}

void ejercicio9(){

    float N, pi = 3.1416;

    cout << "Ingrese el valor del radio:";
    cin >> N;
    float perimetro = 2 * pi * N;
    float area = pi * N * N;

    cout << "Perimetro: " << perimetro << endl;
    cout << "Area: " << area << endl;


}
void ejercicio11() {
    int N;

    cout << "Ingrese un número: ";
    cin >> N;

    for (int i = 1; i <= 10; i++) {
        cout << i << "x" << N << "=" << i * N << endl;
    }
}

void ejercicio13() {
    int n;

    cout << "Ingrese un número: ";
    cin >> n;

    cout << "Los divisores de " << n << " son:" << endl;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
        }

    }
}

void ejercicio15() {
    int numero, suma = 0;

    while (true) {
        cout << "Ingresa un número (0 para finalizar): ";
        cin >> numero;


        if (numero == 0) {
            break;
        }


        suma += numero;
    }


    cout << "El resultado de la sumatoria es: " << suma << endl;
}

void ejercicio17() {

    int numero;
    int mayor = -1;

    cout << "Ingrese un número: ";
    cin >> numero;

    while (numero != 0) {
        if (numero > mayor) {
            mayor = numero;
        }

        cout << "Ingrese un número: ";
        cin >> numero;
    }

    cout << "El numero mayor fue: " << mayor << endl;


}

void ejercicio19() {

    int numero, cantidad_divisores = 0;

    cout << "Ingrese un número: ";
    cin >> numero;

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            cantidad_divisores += 1;
        }
    }

    if(cantidad_divisores == 2){
        cout << numero << " es un numero primo.";
    }else{
        cout << numero << " NO es un numero primo.";
    }

    cout << cantidad_divisores;
}


