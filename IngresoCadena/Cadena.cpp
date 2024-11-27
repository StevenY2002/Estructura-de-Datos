#include <iostream>
#include <string>

using namespace std;

string ingresarCadena(const string& mensaje) {
    cout << mensaje;
    string cadena;
    getline(cin, cadena);
    return cadena;
}

int main() {
    string cadena = ingresarCadena("Ingrese una cadena de texto: ");
    cout << "\nLa cadena ingresada es: " << cadena << endl;
    return 0;
}

