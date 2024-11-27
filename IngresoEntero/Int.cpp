#include <iostream>
#include <limits>

using namespace std;

int ingresarInt(const string& mensaje) {
    cout << mensaje;
    int valor;
    while (!(cin >> valor)) {
        cin.clear(); // Limpia el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la l�nea
        cout << "Entrada inv�lida. Por favor, ingrese un valor entero: ";
    }
    return valor;
}

int main() {
    int valor = ingresarInt("Ingrese un valor entero (int): ");
    cout << "\nEl valor ingresado es: " << valor << endl;
    return 0;
}

