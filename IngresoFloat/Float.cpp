#include <iostream>
#include <limits>

using namespace std;

float ingresarFloat(const string& mensaje) {
    cout << mensaje;
    float valor;
    while (!(cin >> valor)) {
        cin.clear(); // Limpia el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
        cout << "Entrada inválida. Por favor, ingrese un valor decimal: ";
    }
    return valor;
}

int main() {
    float valor = ingresarFloat("Ingrese un valor decimal (float): ");
    cout << "\nEl valor ingresado es: " << valor << endl;
    return 0;
}

