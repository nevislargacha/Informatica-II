#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Ruta {
    int costo = INF;
    vector<string> camino;
};

class Enrutador {
public:
    string nombre;
    unordered_map<string, int> vecinos;

    Enrutador(string n = "") : nombre(n) {}

    void agregarVecino(const string& destino, int costo) {
        vecinos[destino] = costo;
    }

    void eliminarVecino(const string& destino) {
        vecinos.erase(destino);
    }
};

class Red {
private:
    unordered_map<string, Enrutador> enrutadores;

public:
    void agregarEnrutador(const string& nombre) {
        if (!existe(nombre))
            enrutadores[nombre] = Enrutador(nombre);
    }

    void eliminarEnrutador(const string& nombre) {
        enrutadores.erase(nombre);
        for (auto& [_, r] : enrutadores) r.eliminarVecino(nombre);
    }

    void conectar(const string& a, const string& b, int costo) {
        agregarEnrutador(a);
        agregarEnrutador(b);
        enrutadores[a].agregarVecino(b, costo);
        enrutadores[b].agregarVecino(a, costo);
    }

    void desconectar(const string& a, const string& b) {
        if (existe(a)) enrutadores[a].eliminarVecino(b);
        if (existe(b)) enrutadores[b].eliminarVecino(a);
    }

    bool existe(const string& nombre) const {
        return enrutadores.find(nombre) != enrutadores.end();
    }

    Ruta caminoMasCorto(const string& origen, const string& destino) {
        unordered_map<string, int> dist;
        unordered_map<string, string> prev;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

        for (auto& [nombre, _] : enrutadores)
            dist[nombre] = INF;

        dist[origen] = 0;
        pq.push({0, origen});

        while (!pq.empty()) {
            auto [costo, actual] = pq.top(); pq.pop();
            if (actual == destino) break;
            for (auto& [vecino, peso] : enrutadores[actual].vecinos) {
                int nuevo = costo + peso;
                if (nuevo < dist[vecino]) {
                    dist[vecino] = nuevo;
                    prev[vecino] = actual;
                    pq.push({nuevo, vecino});
                }
            }
        }

        Ruta ruta;
        ruta.costo = dist[destino];
        if (ruta.costo == INF) return ruta;

        string actual = destino;
        while (actual != origen) {
            ruta.camino.insert(ruta.camino.begin(), actual);
            actual = prev[actual];
        }
        ruta.camino.insert(ruta.camino.begin(), origen);
        return ruta;
    }

    void imprimirCamino(const string& origen, const string& destino) {
        Ruta r = caminoMasCorto(origen, destino);
        if (r.costo == INF) {
            cout << "No hay ruta disponible de " << origen << " a " << destino << ".\n";
            return;
        }
        cout << "Costo: " << r.costo << ", Ruta: ";
        for (const string& n : r.camino) cout << n << " ";
        cout << endl;
    }

    void cargarDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        if (!archivo) {
            cerr << "No se pudo abrir el archivo." << endl;
            return;
        }
        string a, b;
        int costo;
        while (archivo >> a >> b >> costo)
            conectar(a, b, costo);
        archivo.close();
    }

    void generarRedAleatoria(int numNodos, int enlacesMax, int costoMax) {
        srand(time(nullptr));
        for (int i = 0; i < numNodos; ++i)
            agregarEnrutador(string(1, 'A' + i));
        for (int i = 0; i < numNodos; ++i) {
            int enlaces = rand() % enlacesMax + 1;
            for (int j = 0; j < enlaces; ++j) {
                int vecino = rand() % numNodos;
                if (vecino != i) {
                    int costo = rand() % costoMax + 1;
                    conectar(string(1, 'A' + i), string(1, 'A' + vecino), costo);
                }
            }
        }
    }
};


int main() {
    Red red;
    int opcion;
    string origen, destino;

    do{
        cout << "Bienvenido\n";
        cout << "1. Cargar red desde archivo\n";
        cout << "2. Generar red aleatoria\n";
        cout << "3. Salir del programa\n";
        cin >> opcion;

        if (opcion == 1) {
            string archivo;
            cout << "Nombre del archivo: ";
            cin >> archivo;
            cout << "Origen: "; cin >> origen;
            cout << "Destino: "; cin >> destino;
            red.cargarDesdeArchivo(archivo);
            red.imprimirCamino(origen, destino);
        } else if (opcion == 2){
            int nodos, enlaces, costo;
            cout << "Nodos, enlaces por nodo, costo maximo: ";
            cin >> nodos >> enlaces >> costo;
            cout << "Origen: "; cin >> origen;
            cout << "Destino: "; cin >> destino;
            red.generarRedAleatoria(nodos, enlaces, costo);
            red.imprimirCamino(origen, destino);
        }
    } while (opcion != 3);
}
