#include <iostream>
#include <limits>

using namespace std;

double ingresar(const string& mensaje) {
    cout << mensaje;
    double valor;
    while (!(cin >> valor)) {
        cin.clear(); // Limpia el estado de error de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
        cout << "Entrada inválida. Por favor, ingrese un valor decimal: ";
    }
    return valor;
}

int main() {
    double valor = ingresar("Ingrese un valor decimal: ");
    cout << "\n" << valor << endl;
    return 0;
}

