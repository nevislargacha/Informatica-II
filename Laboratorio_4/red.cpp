#include "Red.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

const int INF = numeric_limits<int>::max();

void Red::agregarEnrutador(const string& nombre) {
    if (!existe(nombre))
        enrutadores[nombre] = Enrutador(nombre);
}

void Red::eliminarEnrutador(const string& nombre) {
    enrutadores.erase(nombre);
    for (auto& [_, r] : enrutadores)
        r.eliminarVecino(nombre);
}

void Red::conectar(const string& a, const string& b, int costo) {
    agregarEnrutador(a);
    agregarEnrutador(b);
    enrutadores[a].agregarVecino(b, costo);
    enrutadores[b].agregarVecino(a, costo);
}

void Red::desconectar(const string& a, const string& b) {
    if (existe(a)) enrutadores[a].eliminarVecino(b);
    if (existe(b)) enrutadores[b].eliminarVecino(a);
}

bool Red::existe(const string& nombre) const {
    return enrutadores.find(nombre) != enrutadores.end();
}

Ruta Red::caminoMasCorto(const string& origen, const string& destino) {
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

    for (const auto& [nombre, _] : enrutadores)
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

void Red::imprimirCamino(const string& origen, const string& destino) {
    Ruta r = caminoMasCorto(origen, destino);
    if (r.costo == INF) {
        cout << "No hay ruta disponible de " << origen << " a " << destino << ".\n";
        return;
    }
    cout << "Costo: " << r.costo << ", Ruta: ";
    for (const auto& n : r.camino)
        cout << n << " ";
    cout << endl;
}

void Red::cargarDesdeArchivo(const string& nombreArchivo) {
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

void Red::guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    for (const auto& [origen, enr] : enrutadores) {
        for (const auto& [destino, costo] : enr.vecinos) {
            if (origen < destino)
                archivo << origen << " " << destino << " " << costo << endl;
        }
    }
    archivo.close();
}

void Red::mostrarRed() {
    for (const auto& [nombre, enrutador] : enrutadores) {
        cout << nombre << " conectado con: ";
        for (const auto& [vecino, costo] : enrutador.vecinos)
            cout << vecino << "(" << costo << ") ";
        cout << endl;
    }
}

void Red::generarRedAleatoria(int numNodos, int enlacesMax, int costoMax) {
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
