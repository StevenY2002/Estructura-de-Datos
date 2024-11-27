#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Función para generar matrices aleatorias
template <typename T>
void generarMatriz(vector<vector<T>>& matriz, int filas, int columnas, T min, T max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = dis(gen);
        }
    }
}

// Función recursiva para sumar matrices
template <typename T>
void sumarMatrices(const vector<vector<T>>& A, const vector<vector<T>>& B, vector<vector<T>>& C, int i, int j) {
    if (i == A.size()) return;
    if (j == A[0].size()) {
        sumarMatrices(A, B, C, i + 1, 0);
    } else {
        C[i][j] = A[i][j] + B[i][j];
        sumarMatrices(A, B, C, i, j + 1);
    }
}

int main() {
    const int filas = 3;
    const int columnas = 3;

    // Definimos las matrices de ejemplo
    vector<vector<int>> A(filas, vector<int>(columnas));
    vector<vector<int>> B(filas, vector<int>(columnas));
    vector<vector<int>> C(filas, vector<int>(columnas, 0)); // Matriz de resultado

    // Generamos matrices aleatorias
    generarMatriz(A, filas, columnas, 1, 10);
    generarMatriz(B, filas, columnas, 1, 10);

    // Llamamos a la función recursiva para sumar matrices
    sumarMatrices(A, B, C, 0, 0);

    // Imprimimos las matrices A, B y el resultado C
    cout << "Matriz A (aleatoria):" << endl;
    for (const auto& fila : A) {
        for (int elem : fila) {
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz B (aleatoria):" << endl;
    for (const auto& fila : B) {
        for (int elem : fila) {
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << "\nResultado de la suma de matrices (A + B):" << endl;
    for (const auto& fila : C) {
        for (int elem : fila) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
