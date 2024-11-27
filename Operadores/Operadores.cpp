#include <iostream>
#include <cstdlib> // Para malloc y free

using namespace std;

class MiClase {
private:
    int* datos;
    size_t tamano;

public:
    // Constructor
    MiClase(size_t tam) : tamano(tam) {
        datos = new int[tamano];
        cout << "Constructor: Memoria asignada para " << tamano << " enteros." << endl;
    }

    // Destructor
    ~MiClase() {
        delete[] datos;
        cout << "Destructor: Memoria liberada." << endl;
    }

    // Sobrecarga del operador new
    void* operator new(size_t tam) {
        cout << "Sobrecarga de new: Asignando " << tam << " bytes de memoria." << endl;
        void* p = malloc(tam);
        if (!p) {
            throw bad_alloc();
        }
        return p;
    }

    // Sobrecarga del operador delete
    void operator delete(void* p) {
        cout << "Sobrecarga de delete: Liberando memoria." << endl;
        free(p);
    }
};

int main() {
    try {
        MiClase* obj = new MiClase(10); // Usando la sobrecarga de new
        delete obj; // Usando la sobrecarga de delete
    } catch (const bad_alloc& e) {
        cerr << "Error de asignación de memoria: " << e.what() << endl;
    }

    return 0;
}

