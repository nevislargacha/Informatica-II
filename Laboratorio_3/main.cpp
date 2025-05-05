#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <algorithm>

using namespace std;

// Constantes
const int COSTO_TRANSACCION = 1000;

// Funciones auxiliares para binario
string textoABinario(const string& texto) {
    string binario;
    for (char c : texto) {
        binario += bitset<8>(c).to_string();
    }
    return binario;
}

string binarioATexto(const string& binario) {
    string texto;
    for (size_t i = 0; i < binario.size(); i += 8) {
        bitset<8> b(binario.substr(i, 8));
        texto += char(b.to_ulong());
    }
    return texto;
}

string invertirBits(const string& bits) {
    string invertido = bits;
    for (char& c : invertido) {
        c = (c == '1') ? '0' : '1';
    }
    return invertido;
}

string codificarMetodo1(const string& binario, int n) {
    string resultado;
    vector<string> bloques;

    // Separar en bloques
    for (size_t i = 0; i < binario.size(); i += n) {
        bloques.push_back(binario.substr(i, n));
    }

    for (size_t i = 0; i < bloques.size(); ++i) {
        string bloque = bloques[i];
        if (bloque.size() < n) bloque.append(n - bloque.size(), '0');

        if (i == 0) {
            resultado += invertirBits(bloque);
        } else {
            int unos = count(bloques[i - 1].begin(), bloques[i - 1].end(), '1');
            int ceros = n - unos;
            if (unos == ceros) {
                resultado += invertirBits(bloque);
            } else if (ceros > unos) {
                for (int j = 0; j < n; ++j) {
                    if ((j + 1) % 2 == 0) bloque[j] = (bloque[j] == '1') ? '0' : '1';
                }
                resultado += bloque;
            } else {
                for (int j = 0; j < n; ++j) {
                    if ((j + 1) % 3 == 0) bloque[j] = (bloque[j] == '1') ? '0' : '1';
                }
                resultado += bloque;
            }
        }
    }
    return resultado;
}

string codificarMetodo2(const string& binario, int n) {
    string resultado;
    for (size_t i = 0; i < binario.size(); i += n) {
        string bloque = binario.substr(i, n);
        if (bloque.size() < n) bloque.append(n - bloque.size(), '0');
        string nuevoBloque(n, '0');
        for (int j = 0; j < n; ++j) {
            nuevoBloque[(j + 1) % n] = bloque[j];
        }
        resultado += nuevoBloque;
    }
    return resultado;
}

void codificarArchivo(const string& archivoEntrada, const string& archivoSalida, int n, int metodo) {
    ifstream inFile(archivoEntrada);
    if (!inFile) throw runtime_error("No se pudo abrir archivo de entrada.");

    stringstream buffer;
    buffer << inFile.rdbuf();
    string texto = buffer.str();
    string binario = textoABinario(texto);
    string binarioCodificado = (metodo == 1) ? codificarMetodo1(binario, n) : codificarMetodo2(binario, n);

    ofstream outFile(archivoSalida, ios::binary);
    if (!outFile) throw runtime_error("No se pudo abrir archivo de salida.");

    for (size_t i = 0; i < binarioCodificado.size(); i += 8) {
        bitset<8> b(binarioCodificado.substr(i, 8));
        outFile.put(static_cast<char>(b.to_ulong()));
    }
    cout << "Archivo codificado correctamente.\n";
}
string decodificarMetodo1(const string& binario, int n) {
    string resultado;
    vector<string> bloques;

    for (size_t i = 0; i < binario.size(); i += n) {
        string bloque = binario.substr(i, n);
        if (bloque.size() < n) bloque.append(n - bloque.size(), '0');
        bloques.push_back(bloque);
    }

    for (size_t i = 0; i < bloques.size(); ++i) {
        string bloque = bloques[i];
        if (i == 0) {
            resultado += invertirBits(bloque);
        } else {
            string prevBloque = resultado.substr((i - 1) * n, n);
            int unos = count(prevBloque.begin(), prevBloque.end(), '1');
            int ceros = n - unos;
            if (unos == ceros) {
                resultado += invertirBits(bloque);
            } else if (ceros > unos) {
                for (int j = 0; j < n; ++j) {
                    if ((j + 1) % 2 == 0) bloque[j] = (bloque[j] == '1') ? '0' : '1';
                }
                resultado += bloque;
            } else {
                for (int j = 0; j < n; ++j) {
                    if ((j + 1) % 3 == 0) bloque[j] = (bloque[j] == '1') ? '0' : '1';
                }
                resultado += bloque;
            }
        }
    }
    return resultado;
}
string decodificarMetodo2(const string& binario, int n) {
    string resultado;
    for (size_t i = 0; i < binario.size(); i += n) {
        string bloque = binario.substr(i, n);
        if (bloque.size() < n) bloque.append(n - bloque.size(), '0');

        // Revertimos el cambio de la codificación moviendo los bits en la dirección opuesta
        string bloqueOriginal(n, '0');
        for (int j = 0; j < n; ++j) {
            bloqueOriginal[(j + n - 1) % n] = bloque[j]; // Movimiento inverso
        }

        resultado += bloqueOriginal;
    }
    return resultado;
}



void decodificarArchivo(const string& archivoEntrada, const string& archivoSalida, int n, int metodo) {
    ifstream inFile(archivoEntrada, ios::binary);
    if (!inFile) throw runtime_error("No se pudo abrir archivo de entrada.");

    string binario;
    char c;
    while (inFile.get(c)) {
        binario += bitset<8>(static_cast<unsigned char>(c)).to_string();
    }

    string binarioDecodificado = (metodo == 1) ? decodificarMetodo1(binario, n) : decodificarMetodo2(binario, n);
    string texto = binarioATexto(binarioDecodificado);

    ofstream outFile(archivoSalida);
    if (!outFile) throw runtime_error("No se pudo abrir archivo de salida.");

    outFile << texto;
    cout << "Archivo decodificado correctamente.\n";
}


// Funciones de administración y usuarios
bool autenticarAdmin(const string& claveIngresada) {
    int n, metodo;
    cout << "Ingrese semilla (n) usada para codificar sudo.txt: ";
    cin >> n;
    cout << "Ingrese metodo (1 o 2) usado para codificar sudo.txt: ";
    cin >> metodo;

    ifstream inFile("sudo.txt", ios::binary);
    if (!inFile) {
        cout << "No se pudo abrir sudo.txt\n";
        return false;
    }

    string binario;
    char c;
    while (inFile.get(c)) {
        binario += bitset<8>(static_cast<unsigned char>(c)).to_string();
    }

    string binarioDecodificado = (metodo == 1) ? decodificarMetodo1(binario, n)
                                               : decodificarMetodo2(binario, n);

    string claveGuardada = binarioATexto(binarioDecodificado);

    // Elimina posibles caracteres nulos o basura al final
    claveGuardada.erase(find(claveGuardada.begin(), claveGuardada.end(), '\0'), claveGuardada.end());

    return claveGuardada == claveIngresada;
}



void registrarUsuario(const string& cedula, const string& clave, int saldo) {
    ofstream file("usuarios.txt", ios::app);
    file << cedula << "," << clave << "," << saldo << "\n";
    cout << "Usuario registrado.\n";
}

map<string, tuple<string, int>> cargarUsuarios() {
    map<string, tuple<string, int>> usuarios;
    ifstream file("usuarios.txt");
    string linea;
    while (getline(file, linea)) {
        stringstream ss(linea);
        string cedula, clave;
        int saldo;
        getline(ss, cedula, ',');
        getline(ss, clave, ',');
        ss >> saldo;
        usuarios[cedula] = make_tuple(clave, saldo);
    }
    return usuarios;
}

void guardarUsuarios(const map<string, tuple<string, int>>& usuarios) {
    ofstream file("usuarios.txt");
    for (const auto& [cedula, datos] : usuarios) {
        file << cedula << "," << get<0>(datos) << "," << get<1>(datos) << "\n";
    }
}

void registrarTransaccion(const string& cedula, const string& operacion, int monto, int n, int metodo) {
    stringstream ss;
    ss << "Usuario: " << cedula << "\n";
    ss << "Operacion: " << operacion << "\n";
    ss << "Monto: " << monto << "\n";

    string binario = textoABinario(ss.str());
    string binarioCodificado = (metodo == 1) ? codificarMetodo1(binario, n) : codificarMetodo2(binario, n);

    ofstream outFile("transacciones.txt", ios::app | ios::binary);
    if (!outFile) throw runtime_error("No se pudo abrir transacciones.txt para guardar.");

    for (size_t i = 0; i < binarioCodificado.size(); i += 8) {
        bitset<8> b(binarioCodificado.substr(i, 8));
        outFile.put(static_cast<char>(b.to_ulong()));
    }
}

void cajero() {
    auto usuarios = cargarUsuarios();
    string cedula, clave;
    cout << "Ingrese su cedula: "; cin >> cedula;
    cout << "Ingrese su clave: "; cin >> clave;

    if (usuarios.find(cedula) == usuarios.end() || get<0>(usuarios[cedula]) != clave) {
        cout << "Credenciales invalidas.\n";
        return;
    }

    int& saldo = get<1>(usuarios[cedula]);

    int n, metodo;
    cout << "Para registrar transacciones, indique semilla (n): "; cin >> n;
    cout << "Metodo de encriptacion para transacciones (1 o 2): "; cin >> metodo;

    int opcion;
    cout << "1. Consultar saldo\n2. Retirar dinero\nOpcion: ";
    cin >> opcion;

    if (opcion == 1) {
        if (saldo >= COSTO_TRANSACCION) {
            saldo -= COSTO_TRANSACCION;
            cout << "Saldo actual: " << saldo << " COP\n";
            registrarTransaccion(cedula, "Consulta de saldo", 0, n, metodo);
        } else {
            cout << "Saldo insuficiente para la consulta (requiere " << COSTO_TRANSACCION << " COP).\n";
        }
    } else if (opcion == 2) {
        int cantidad;
        cout << "Ingrese cantidad a retirar: ";
        cin >> cantidad;

        int total = cantidad + COSTO_TRANSACCION;

        if (total <= saldo) {
            saldo -= total;
            cout << "Retiro exitoso. Se descontó " << COSTO_TRANSACCION << " COP por transacción.\n";
            registrarTransaccion(cedula, "Retiro", cantidad, n, metodo);
        } else {
            cout << "Saldo insuficiente para retirar esa cantidad (requiere " << total << " COP).\n";
        }
    } else {
        cout << "Opcion invalida. No se realizó ninguna operación.\n";
    }

    guardarUsuarios(usuarios);
}

int main() {
    while (true) {
        try {
            int opcion;
            cout << "\n----- MENU -----\n";
            cout << "1. Codificar archivo\n";
            cout << "2. Cajero\n";
            cout << "3. Registrar usuario (admin)\n";
            cout << "4. Decodificar archivo\n";
            cout << "0. Salir\n";
            cout << "Opcion: ";
            cin >> opcion;

            if (opcion == 1) {
                string archivoEntrada, archivoSalida;
                int n, metodo;
                cout << "Archivo fuente: "; cin >> archivoEntrada;
                cout << "Archivo salida: "; cin >> archivoSalida;
                cout << "Semilla (n): "; cin >> n;
                cout << "Metodo (1 o 2): "; cin >> metodo;
                codificarArchivo(archivoEntrada, archivoSalida, n, metodo);
            } else if (opcion == 2) {
                cajero();
            } else if (opcion == 3) {
                string claveAdmin;
                cout << "Ingrese clave admin: "; cin >> claveAdmin;
                if (autenticarAdmin(claveAdmin)) {
                    string cedula, clave;
                    int saldo;
                    cout << "Cedula: "; cin >> cedula;
                    cout << "Clave: "; cin >> clave;
                    cout << "Saldo inicial: "; cin >> saldo;
                    registrarUsuario(cedula, clave, saldo);
                } else {
                    cout << "Clave admin incorrecta.\n";
                }
            } else if (opcion == 4) {
                string archivoEntrada, archivoSalida;
                int n, metodo;
                cout << "Archivo codificado (entrada): "; cin >> archivoEntrada;
                cout << "Archivo de salida (texto decodificado): "; cin >> archivoSalida;
                cout << "Semilla (n): "; cin >> n;
                cout << "Metodo (1 o 2): "; cin >> metodo;
                decodificarArchivo(archivoEntrada, archivoSalida, n, metodo);
            } else if (opcion == 0) {
                cout << "Saliendo del programa.\n";
                break;
            } else {
                cout << "Opcion invalida.\n";
            }

        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
