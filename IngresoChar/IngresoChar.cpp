#include <iostream>

using namespace std;

char ingresarChar(const string& mensaje) {
    cout << mensaje;
    char valor;
    cin >> valor;
    return valor;
}

int main() {
    char valor = ingresarChar("Ingrese un cardcter (char): ");
    cout << "\nEl carácter ingresado es: " << valor << endl;
    return 0;
}

