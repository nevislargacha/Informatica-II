#ifndef RED_H
#define RED_H

#include "Enrutador.h"
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Ruta {
    int costo;
    vector<string> camino;
};

class Red {
private:
    unordered_map<string, Enrutador> enrutadores;

public:
    void agregarEnrutador(const string& nombre);
    void eliminarEnrutador(const string& nombre);
    void conectar(const string& a, const string& b, int costo);
    void desconectar(const string& a, const string& b);
    bool existe(const string& nombre) const;
    Ruta caminoMasCorto(const string& origen, const string& destino);
    void imprimirCamino(const string& origen, const string& destino);
    void cargarDesdeArchivo(const string& nombreArchivo);
    void guardarEnArchivo(const string& nombreArchivo);
    void mostrarRed();
    void generarRedAleatoria(int numNodos, int enlacesMax, int costoMax);
};

#endif
