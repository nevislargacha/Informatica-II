#include "Enrutador.h"

Enrutador::Enrutador(string n) : nombre(n) {}

void Enrutador::agregarVecino(const string& destino, int costo) {
    vecinos[destino] = costo;
}

void Enrutador::eliminarVecino(const string& destino) {
    vecinos.erase(destino);
}
