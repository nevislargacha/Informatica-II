#include <iostream>

using namespace std;

void ejercicio1();

void ejercicio2();

void ejercicio3();

void ejercicio4();

void ejercicio5();

int main()
{
    //ejercicio1();
    //ejercicio2();
    //ejercicio3();
    ejercicio4();
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

    if( a%2 == 0){
        cout << "el numero " << a << " es par" << endl;
    }else{
        cout << "el numero " << a << " es impar" << endl;
    }
}

void ejercicio3(){

    int a, b;

    cout << "Ingrese el primer numero:";
    cin >> a;
    cout << "Ingrese el segundo numero:";
    cin >> b;

    if(a > b){
        cout << "El mayor es: " << a << endl;
    }else{
        cout << "El mayor es: " << b << endl;
    }
}

void ejercicio4(){

    int a, b;

    cout << "Ingrese el primer numero:";
    cin >> a;
    cout << "Ingrese el segundo numero:";
    cin >> b;

    if(a < b){
        cout << "El menor es: " << a << endl;
    }else{
        cout << "El menor es: " << b << endl;
    }
}
