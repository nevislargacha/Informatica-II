#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void problema1();
void problema2();
void problema3();
void problema4();

int main()
{
    //problema2();
    //problema3();
    problema4();
}
void problema1(){}
void problema2(){
    const int TAM = 200;
    char arreglo[TAM];
    int contador[26] = {0};

    srand(time(0));


    for (int i = 0; i < TAM; i++) {
        char letra = 'A' + rand() % 26;
        arreglo[i] = letra;
        contador[letra - 'A']++;
    }


    cout << "Arreglo generado:" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << arreglo[i];
    }
    cout << endl << endl;

    cout << "Frecuencia de cada letra:" << endl;
    for (int i = 0; i < 26; i++) {
        if (contador[i] > 0) {
            cout << char('A' + i) << ": " << contador[i] << endl;
        }
    }
}

void problema3(){

    char primera_cadena[100];
    char segunda_cadena[100];
    int i = 0;

    cout << "ingresa la primera cadena: " << endl;
    cin.getline(primera_cadena, 100);
    cout << "ingresa la segunda cadena: " << endl;
    cin.getline(segunda_cadena, 100);

    while (primera_cadena[i] != '\0' && segunda_cadena[i] != '\0') {

        if(primera_cadena[i] != segunda_cadena[i]){
            cout << "el caracter " << primera_cadena[i] << " de la primera cadena es diferente al caracter " <<
            segunda_cadena[i] << " de la segunda cadena";
            return;
        }
        i++;
    }

    if(primera_cadena[i] == '\0' && segunda_cadena[i] == '\0'){
        cout << "El tamaño de las cadenas son iguales";
    }else{
        cout << "El tamaño de las cadenas no son iguales";
    }
}

void problema4(){
    char cadena[100];
    int numero_entero = 0;

    cout << "ingresa la cadena de numeros: " << endl;
    cin.getline(cadena, 100);

    for (int i = 0; cadena[i] != '\0'; ++i) {
        if(cadena[i] >= '0' && cadena[i] <= '9'){
            numero_entero = numero_entero * 10 + (cadena[i] - '0');
        }else{
            cout << "el caracter no es valido";
            return;
        }
    }

    cout << "el numero es: " << numero_entero;
}















