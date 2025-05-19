#include "Red.h"
#include <iostream>
using namespace std;

int main() {
    Red red;
    int opcion;
    string a, b;
    int costo;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Cargar red desde archivo\n";
        cout << "2. Generar red aleatoria\n";
        cout << "3. Agregar enrutador\n";
        cout << "4. Eliminar enrutador\n";
        cout << "5. Conectar enrutadores\n";
        cout << "6. Desconectar enrutadores\n";
        cout << "7. Mostrar red\n";
        cout << "8. Calcular camino más corto\n";
        cout << "9. Guardar red en archivo\n";
        cout << "10. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string archivo;
            cout << "Nombre del archivo: ";
            cin >> archivo;
            red.cargarDesdeArchivo(archivo);
            break;
        }
        case 2: {
            int nodos, enlaces, costoMax;
            cout << "Nodos, enlaces por nodo, costo máximo: ";
            cin >> nodos >> enlaces >> costoMax;
            cout << "Origen: "; cin >> a;
            cout << "Destino: "; cin >> b;
            red.generarRedAleatoria(nodos, enlaces, costoMax);
            cout << "\nRed generada aleatoriamente:\n";
            red.mostrarRed();
            cout << "\nCamino más corto desde " << a << " hasta " << b << ":\n";
            red.imprimirCamino(a, b);
            break;
        }
        case 3:
            cout << "Nombre del enrutador a agregar: ";
            cin >> a;
            red.agregarEnrutador(a);
            break;
        case 4:
            cout << "Nombre del enrutador a eliminar: ";
            cin >> a;
            red.eliminarEnrutador(a);
            break;
        case 5:
            cout << "Conectar enrutadores (a b costo): ";
            cin >> a >> b >> costo;
            red.conectar(a, b, costo);
            break;
        case 6:
            cout << "Desconectar enrutadores (a b): ";
            cin >> a >> b;
            red.desconectar(a, b);
            break;
        case 7:
            red.mostrarRed();
            break;
        case 8:
            cout << "Origen: ";
            cin >> a;
            cout << "Destino: ";
            cin >> b;
            red.imprimirCamino(a, b);
            break;
        case 9:
            cout << "Nombre del archivo para guardar: ";
            cin >> a;
            red.guardarEnArchivo(a);
            break;
        case 10:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción no válida\n";
        }

    } while (opcion != 10);

    return 0;
}
