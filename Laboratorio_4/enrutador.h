#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <string>
#include <unordered_map>
using namespace std;

class Enrutador {
public:
    string nombre;
    unordered_map<string, int> vecinos;

    Enrutador(string n = "");
    void agregarVecino(const string& destino, int costo);
    void eliminarVecino(const string& destino);
};

#endif
