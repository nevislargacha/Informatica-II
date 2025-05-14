#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void problema1();
void problema2();
void problema3();
void problema4();
void problema5();
void problema6();
void problema7();
void problema8();
void problema9();
void problema10();
void problema11();
void problema12();
void problema13();
void problema14();
void problema15();
void problema16();
void problema17();
void problema18();

int main()
{
    //problema2();
    //problema3();
    //problema4();
    //problema5();
    //problema7();
    //problema8();
    //problema9();
    //problema11();
    //problema12();
    //problema13();
    //problema14();
    //problema15();
    //problema16();
    //problema18();



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



void convertirnumacad(int num, char cad[]) {

    int i = 0;
    bool neg = false;


        if (num < 0) {
            neg = true;
            num = -num;
        }

        do {
            cad[i++] = (num % 10) + '0';
            num /= 10;
        } while (num > 0);


        if (neg) {
            cad[i++] = '-';
        }


        cad[i] = '\0';

        for (int j = 0; j < i / 2; ++j) {
            char temp = cad[j];
            cad[j] = cad[i - j - 1];
            cad[i - j - 1] = temp;
        }
    }


void problema5() {
        int N;
        char resultado[15];

        cout << "Ingresa un número entero: ";
        cin >> N;

        convertirnumacad(N, resultado);

        cout << "El número convertido a cadena es: " << resultado << endl;


    }


void problema7() {
    int n = 0;
    bool repetido = false;
    char usuario[100];
    char norepetidos[100];
    cout << "Ingresa una cadena: ";
    cin.getline(usuario, 100);


    for (int i = 0; usuario[i] != '\0'; ++i) {
            repetido= false;
        for (int j = 0; j < n; ++j) {
            if (usuario[i] == norepetidos[j]) {
                repetido = true;
                break;
            }
        }
        if (!repetido) {
            norepetidos[n] = usuario[i];
            ++n;
        }
    }

    norepetidos[n] = '\0';

    cout << "Original: " << usuario << endl;
    cout << "Sin repetidos: " << norepetidos << endl;
}

void problema8() {
    char usuario;
    char cadenaoriginal[100], caracterestexto[100], caracteresnumericos[100];
    int i = 0, t = 0, n = 0;

    cout << "Introduce una cadena (sin espacios): ";
    while (cin.get(usuario) && usuario != '\n') {
        cadenaoriginal[i++] = usuario;

        if (usuario >= '0' && usuario <= '9') {
            caracteresnumericos[n++] = usuario;
        } else {
            caracterestexto[t++] = usuario;
        }
    }

    cadenaoriginal[i] = '\0';
    caracterestexto[t] = '\0';
    caracteresnumericos[n] = '\0';

    cout << "Original: " << cadenaoriginal << "." << endl;
    cout << "Texto: " << caracterestexto << ". Numero: " << caracteresnumericos << "." << endl;
}

void problema9(){

    int n, cerosfaltantes,cadenalongitud = 0, sumabloques = 0, bloqueactual = 0 ;
    char usuario[100];
    char cadenacompleta[200];

    cout << "Ingresa el valor de n: ";
    cin >> n;

    cout << "Ingresa la cadena numerica: ";
    cin >> usuario;

    while (usuario[cadenalongitud] != '\0') {
        cadenalongitud++;
    }

    cerosfaltantes = (n - (cadenalongitud % n)) % n;

    for (int i = 0; i < cerosfaltantes; ++i) {
        cadenacompleta[i] = '0';
    }

    for (int i = 0; i < cadenalongitud; ++i) {
        cadenacompleta[cerosfaltantes + i] = usuario[i];
    }

    cadenacompleta[cerosfaltantes + cadenalongitud] = '\0';

    cout << "Original:\n " << usuario << "." << endl;

    for (int i = 0; cadenacompleta[i] != '\0'; ++i) {
        bloqueactual = bloqueactual * 10 + (cadenacompleta[i] - '0');
        if ((i + 1) % n == 0) {
            sumabloques += bloqueactual;
            bloqueactual = 0;
        }
    }

    cout << "Suma: " << sumabloques << "." << endl;
}

const int filas = 15;
const int asientos = 20;

void problema11() {
    char sala[filas][asientos];
    int opcion;
    char filachar;
    int numero;

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < asientos; ++j) {
            sala[i][j] = '-';
        }
    }

    do {

        cout << "\nEstado de la sala:\n";
        for (int i = 0; i < filas; ++i) {
            char letraFila = 'A' + i;
            cout << letraFila << " ";
            for (int j = 0; j < asientos; ++j) {
                cout << sala[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nMenú:\n";
        cout << "1. Reservar asiento\n";
        cout << "2. Cancelar reserva\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1 || opcion == 2) {
            cout << "Ingrese la fila (A-O): ";
            cin >> filachar;
            cout << "Ingrese el número de asiento (1-20): ";
            cin >> numero;

            if (opcion == 1) {
                int filanumero = filachar - 'A';
                if (filanumero < 0 || filanumero >= filas || numero < 1 || numero > asientos) {
                    cout << "Entrada inválida.\n";
                }else if (sala[filanumero][numero - 1] == '+') {
                    cout << "El asiento ya está reservado.\n";
                } else {
                    sala[filanumero][numero - 1] = '+';
                    cout << "Reserva realizada con éxito.\n";
                }
            } else {
                int filanumero = filachar - 'A';
                if (filanumero < 0 || filanumero >= filas || numero < 1 || numero > asientos) {
                    cout << "Entrada inválida.\n";
                }else if (sala[filanumero][numero - 1] == '-') {
                    cout << "El asiento ya estaba disponible.\n";
                } else {
                    sala[filanumero][numero - 1] = '-';
                    cout << "Reserva cancelada con éxito.\n";
                }
            }
        } else if (opcion != 3) {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 3);

    cout << "Gracias por usar el sistema de reservas.\n";
}

const int tamañomaximomatriz = 10;

bool escuadromagico(int matriz[tamañomaximomatriz][tamañomaximomatriz], int n) {
    int sumamagica = 0;
    bool usados[tamañomaximomatriz * tamañomaximomatriz + 1] = {false};

    for (int j = 0; j < n; j++) {
        int num = matriz[0][j];
        sumamagica += num;

        if (num < 1 || num > n * n || usados[num]) return false;
        usados[num] = true;
    }

    for (int i = 1; i < n; i++) {
        int sumaFila = 0;
        for (int j = 0; j < n; j++) {
            int num = matriz[i][j];
            sumaFila += num;

            if (num < 1 || num > n * n || usados[num]) return false;
            usados[num] = true;
        }
        if (sumaFila != sumamagica) return false;
    }

    for (int j = 0; j < n; j++) {
        int sumaCol = 0;
        for (int i = 0; i < n; i++) {
            sumaCol += matriz[i][j];
        }
        if (sumaCol != sumamagica) return false;
    }

    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += matriz[i][i];
        diag2 += matriz[i][n - i - 1];
    }
    if (diag1 != sumamagica || diag2 != sumamagica) return false;

    return true;
}

void problema12() {
    int n;
    int matriz[tamañomaximomatriz][tamañomaximomatriz];

    cout << "Ingrese el tamaño de la matriz cuadrada (n <= " << tamañomaximomatriz << "): ";
    cin >> n;

    if (n < 1 || n > tamañomaximomatriz) {
        cout << "Tamaño no válido.\n";
    }

    cout << "Ingrese los elementos de la matriz (" << n * n << " números):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << "\nMatriz ingresada:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    if (escuadromagico(matriz, n)) {
        cout << "La matriz ES un cuadro mágico.\n";
    } else {
        cout << "La matriz NO es un cuadro mágico.\n";
    }
}

const int filasmatrizestrellas = 6;
const int columnasmatrizestrellas = 8;
int conteoestrellas = 0;

void contarestrellas(int (*matriz)[filasmatrizestrellas][columnasmatrizestrellas]) {
    float promedio;
    conteoestrellas = 0;
    // Recorremos la matriz sin tocar los bordes
    for (int i = 1; i < filasmatrizestrellas - 1; i++) {
        for (int j = 1; j < columnasmatrizestrellas - 1; j++) {
            promedio = ((*matriz)[i][j] + (*matriz)[i][j - 1] + (*matriz)[i][j + 1] +
                        (*matriz)[i - 1][j] + (*matriz)[i + 1][j]) / 5.0;

            if (promedio > 6) {
                conteoestrellas++;
                cout << "Estrella encontrada en posición (" << i << ", " << j << ") con promedio: " << promedio << endl;
            }
        }
    }
}

void problema13() {
    int matriz[filasmatrizestrellas][columnasmatrizestrellas] = {
        {0, 3, 4, 0, 0, 0, 6, 8},
        {5,13, 6, 0, 0, 0, 2, 3},
        {2, 6, 2, 7, 3, 0,10, 0},
        {0, 0, 4,15, 4, 1, 6, 0},
        {0, 0, 7,12, 6, 9,10, 4},
        {5, 0, 6,10, 6, 4, 8, 0}
    };

    contarestrellas(&matriz);

    cout << "\nNúmero total de estrellas encontradas: " << conteoestrellas << endl;
}

const int n = 5;

void imprimirmatriz(int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void problema14() {
    int matriz[n][n];
    int rotada90[n][n], rotada180[n][n], rotada270[n][n];

    int contador = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matriz[i][j] = contador++;

    cout << "Matriz original:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matriz rotada 90°:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotada90[j][n - 1 - i] = matriz[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << rotada90[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matriz rotada 180°:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotada180[n - 1 - i][n - 1 - j] = matriz[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << rotada180[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matriz rotada 270°:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotada270[n - 1 - j][i] = matriz[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << rotada270[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void problema15() {
    int rectanguloa[4], rectangulob[4], rectanguloc[4];

    cout << "Ingrese los datos del rectángulo A (x, y, ancho, alto): ";
    for (int i = 0; i < 4; i++) {
        cin >> rectanguloa[i];
    }

    cout << "Ingrese los datos del rectángulo B (x, y, ancho, alto): ";
    for (int i = 0; i < 4; i++) {
        cin >> rectangulob[i];
    }

    int rectanguloax1 = rectanguloa[0], rectanguloay1 = rectanguloa[1];
    int rectanguloax2 = rectanguloa[0] + rectanguloa[2], rectanguloay2 = rectanguloa[1] + rectanguloa[3];

    int rectangulobx1 = rectangulob[0], rectanguloby1 = rectangulob[1];
    int rectangulobx2 = rectangulob[0] + rectangulob[2], rectanguloby2 = rectangulob[1] + rectangulob[3];

    int rectangulocx1 = (rectanguloax1 > rectangulobx1) ? rectanguloax1 : rectangulobx1;
    int rectangulocy1 = (rectanguloay1 > rectanguloby1) ? rectanguloay1 : rectanguloby1;
    int rectangulocx2 = (rectanguloax2 < rectangulobx2) ? rectanguloax2 : rectangulobx2;
    int rectangulocy2 = (rectanguloay2 < rectanguloby2) ? rectanguloay2 : rectanguloby2;

    if (rectangulocx1 < rectangulocx2 && rectangulocy1 < rectangulocy2) {
        rectanguloc[0] = rectangulocx1;
        rectanguloc[1] = rectangulocy1;
        rectanguloc[2] = rectangulocx2 - rectangulocx1;
        rectanguloc[3] = rectangulocy2 - rectangulocy1;

        cout << "Rectángulo intersección C: {";
        for (int i = 0; i < 4; i++) {
            cout << rectanguloc[i];
            if (i < 3) cout << ", ";
        }
        cout << "}" << endl;
    } else {
        cout << "No hay intersección entre los rectángulos." << endl;
    }
}

void problema16() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    unsigned long long factorialden = 1;
    unsigned long long factorialdenpor2 = 1;

    for (int i = 2; i <= n; ++i)
        factorialden *= i;

    for (int i = 2; i <= 2 * n; ++i)
        factorialdenpor2 *= i;

    unsigned long long caminos = factorialdenpor2 / (factorialden * factorialden);

    cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;
}
