#include <iostream>
#include <cmath>

using namespace std;

void problema1();

void problema3();

void problema5();

void problema7();

void problema9();

void problema11();

void problema13();

void problema15();

void problema17();

int main()
{
    //problema1();
    //problema3();
    //problema5();
    //problema7();
    //problema9();
    //problema11();
    //problema13();
    //problema15();
    problema17();

}


void problema1() {
    char caracter;


    cout << "Ingresa un caracter: ";
    cin >> caracter;

    if ((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z')) {
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u' ||
            caracter == 'A' || caracter == 'E' || caracter == 'I' || caracter == 'O' || caracter == 'U') {
            cout << caracter << " es una vocal." << endl;
        }

        else {
            cout << caracter << " es una consonante." << endl;
        }
    }
    // Si no es una letra, mostrar que no es una letra
    else {
        cout << "No es una letra." << endl;
    }
}

void problema3() {
    int mes, dia, ano;


    cout << "Introduce el numero del mes: ";
    cin >> mes;



    if (mes < 1 || mes > 12) {
        cout << mes << " es un mes invalido." << endl;
        return;
    }
    cout << "Introduce el dia: ";
    cin >> dia;
    cout << "Introduce el ano: ";
    cin >> ano;


    if (mes == 2) {
        if (dia < 1 || dia > 28) {

            if (dia == 29 && (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))) {
                cout << dia << "/" << mes << " es una fecha valida en bisiesto." << endl;
            } else {
                cout << dia << "/" << mes << " es una fecha invalida." << endl;
            }
        } else {
            cout << dia << "/" << mes << " es una fecha valida." << endl;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia < 1 || dia > 30) {
            cout << dia << "/" << mes << " es una fecha invalida." << endl;
        } else {
            cout << dia << "/" << mes << " es una fecha valida." << endl;
        }
    }
    else {
        if (dia < 1 || dia > 31) {
            cout << dia << "/" << mes << " es una fecha invalida." << endl;
        } else {
            cout << dia << "/" << mes << " es una fecha valida." << endl;
        }
    }
}

void problema5() {
    int n;


    cout << "Ingrese un numero impar: ";
    cin >> n;


    if (n % 2 == 0) {
        cout << "El numero debe ser impar." << endl;
        return;
    }


    for (int i = 1; i <= n; i += 2) {

        for (int j = 0; j < (n - i) / 2; ++j) {
            cout << " ";
        }

        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }


    for (int i = n - 2; i >= 1; i -= 2) {

        for (int j = 0; j < (n - i) / 2; ++j) {
            cout << " ";
        }

        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

}
void problema7()  {

    int n;
    cout << "Ingresa un numero n: ";
    cin >> n;

    int a = 1, b = 1, sum = 0;


    while (b < n) {
        if (b % 2 == 0) {
            sum += b;
        }


        int sigN = a + b;
        a = b;
        b = sigN;
    }

    cout << "El resultado de la suma es: " << sum << endl;

}

void problema9()  {
    int N, sum = 0;


    cout << "Ingrese un numero entero: ";
    cin >> N;


    int num = N;
    while (num > 0) {
        int dig = num % 10;
        sum += pow(dig, dig);
        num /= 10;
    }


    cout << "El resultado de la suma es: " << sum << endl;


}

void problema11() {

    int a, MCM = 1;

    cout << "Ingrese el primer numero:";
    cin >> a;

    for ( int i = 2; i <= a; i++){
        int b = (MCM>i) ? MCM : i;
        while(true){
            if(b % MCM == 0 && b % i == 0) {
            MCM = b;
            break;
            }
            b++;
        }
    }
    cout << "El MCM entre 1 y " << a << " es: " << MCM << endl;
}

void problema13() {

    int numero, cantidad_divisores = 0, resultado = 0;

    cout << "Ingrese un número: ";
    cin >> numero;

    for (int i = 1; i < numero; ++i) {
        for (int f = 1; f <= numero; f++) {
            if (i % f == 0) {
                cantidad_divisores += 1;
            }
        }

        if(cantidad_divisores == 2){
            resultado += i;
        }

        cantidad_divisores = 0;
    }

    cout << "El resultado de la suma es: " << resultado << endl;
}

void problema17() {

    int k, divisores, numero_triangular = 0, n = 1;

    cout << "Ingrese un numero";
    cin >> k;

    while(true){
        numero_triangular = n * (n + 1) / 2;

        divisores = 0;

        for (int i = 1; i < sqrt(numero_triangular); ++i) {
            if(numero_triangular % i == 0){
                if(i == numero_triangular / i){
                    divisores += 1;
                }else{
                    divisores += 2;
                }
            }
        }

        if (divisores > k) {
            cout << "El primer número triangular con más de " << k << " divisores es: " << numero_triangular << endl;
            break;
        }
        n += 1;
    }
}
