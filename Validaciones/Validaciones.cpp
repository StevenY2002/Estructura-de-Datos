#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Función para validar la entrada de un entero
int ingresarEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            cout << "Entrada inválida. Por favor, ingrese un valor entero." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            return valor;
        }
    }
}

// Función para validar la entrada de un número de punto flotante
float ingresarFloat(const string& mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            cout << "Entrada inválida. Por favor, ingrese un valor decimal." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            return valor;
        }
    }
}

// Función para validar la entrada de una cadena de texto
string ingresarCadena(const string& mensaje) {
    string cadena;
    while (true) {
        cout << mensaje;
        getline(cin, cadena);
        if (cadena.empty()) {
            cout << "Entrada inválida. Por favor, ingrese una cadena de texto." << endl;
        } else {
            return cadena;
        }
    }
}

int main() {
    int entero = ingresarEntero("Ingrese un valor entero: ");
    cout << "Valor entero ingresado: " << entero << endl;

    float decimal = ingresarFloat("Ingrese un valor decimal: ");
    cout << "Valor decimal ingresado: " << decimal << endl;

    string cadena = ingresarCadena("Ingrese una cadena de texto: ");
    cout << "Cadena de texto ingresada: " << cadena << endl;

    return 0;
}

