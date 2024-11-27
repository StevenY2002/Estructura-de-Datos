#include <iostream>
using namespace std;

// Función para calcular el máximo común divisor (MCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Clase para la fracción
class Fraccion {
private:
    int numerador, denominador;

public:
    // Constructor
    Fraccion(int num, int den) : numerador(num), denominador(den) {
        if (den == 0) {
            throw invalid_argument("El denominador no puede ser cero.");
        }
    }

    // Método para mostrar la fracción
    void mostrarFraccion() const {
        cout << numerador << "/" << denominador << endl;
    }

    // Método para sumar dos fracciones
    Fraccion sumar(const Fraccion& otra) const {
        int nuevoNumerador = numerador * otra.denominador + otra.numerador * denominador;
        int nuevoDenominador = denominador * otra.denominador;
        return Fraccion(nuevoNumerador, nuevoDenominador);
    }

    // Método para simplificar la fracción
    void simplificar() {
        int gcdValue = gcd(numerador, denominador);
        numerador /= gcdValue;
        denominador /= gcdValue;
    }
};

int main() {
    int num1, den1, num2, den2;
    cout << "Ingrese el numerador y denominador de la primera fracción: ";
    cin >> num1 >> den1;
    cout << "Ingrese el numerador y denominador de la segunda fracción: ";
    cin >> num2 >> den2;

    try {
        Fraccion fraccion1(num1, den1);
        Fraccion fraccion2(num2, den2);

        Fraccion suma = fraccion1.sumar(fraccion2);
        suma.simplificar();

        cout << "La suma de las fracciones es: ";
        suma.mostrarFraccion();
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
