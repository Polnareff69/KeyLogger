#pragma once
#ifndef TRADUCTORASCII_H
#define TRADUCTORASCII_H
#include <string>
#include <fstream>
#include <iostream> //Libreria input output
#include <Windows.h> //Libreria Manejo de SOS windows 
#include "TraductorASCII.h"
using namespace std;

void TraductorASCII(string ruta) {
    ifstream archivo(ruta);

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
    }
    string linea;
    // Lee el archivo línea por línea
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

#endif 