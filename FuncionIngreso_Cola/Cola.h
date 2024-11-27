#ifndef COLA_H
#define COLA_H

#include "Nodo.h"
#include <stdio.h>

template <typename T>
class Cola {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

    Nodo<T>* buscarRecursivo(Nodo<T>* nodo, T valor) const;
    void reemplazarRecursivo(Nodo<T>* nodo, T valorBuscado, T nuevoValor);

public:
    Cola();
    ~Cola();
    void ingresarPorCola(T valor);
    void ingresarPorCabeza(T valor);
    bool eliminar(T valor);
    bool buscar(T valor) const;
    void reemplazar(T valorBuscado, T nuevoValor);
    void mostrar() const;
};

template <typename T>
Cola<T>::Cola() : cabeza(nullptr), cola(nullptr) {}

template <typename T>
Cola<T>::~Cola() {
    while (cabeza != nullptr) {
        Nodo<T>* aux = cabeza;
        cabeza = cabeza->getSiguiente();
        delete aux;
    }
}

template <typename T>
void Cola<T>::ingresarPorCola(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    if (cola == nullptr) {
        cabeza = cola = nuevo;
    } else {
        cola->setSiguiente(nuevo);
        cola = nuevo;
    }
}

template <typename T>
void Cola<T>::ingresarPorCabeza(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    if (cabeza == nullptr) {
        cabeza = cola = nuevo;
    } else {
        nuevo->setSiguiente(cabeza);
        cabeza = nuevo;
    }
}

template <typename T>
bool Cola<T>::eliminar(T valor) {
    if (cabeza == nullptr) return false;

    Nodo<T>* actual = cabeza;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr && actual->getDato() != valor) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (actual == nullptr) return false;

    if (actual == cabeza) {
        cabeza = cabeza->getSiguiente();
        if (cabeza == nullptr) cola = nullptr;
    } else {
        anterior->setSiguiente(actual->getSiguiente());
        if (actual == cola) cola = anterior;
    }

    delete actual;
    return true;
}

template <typename T>
bool Cola<T>::buscar(T valor) const {
    return buscarRecursivo(cabeza, valor) != nullptr;
}

template <typename T>
Nodo<T>* Cola<T>::buscarRecursivo(Nodo<T>* nodo, T valor) const {
    if (nodo == nullptr) return nullptr;
    if (nodo->getDato() == valor) return nodo;
    return buscarRecursivo(nodo->getSiguiente(), valor);
}

template <typename T>
void Cola<T>::reemplazar(T valorBuscado, T nuevoValor) {
    reemplazarRecursivo(cabeza, valorBuscado, nuevoValor);
}

template <typename T>
void Cola<T>::reemplazarRecursivo(Nodo<T>* nodo, T valorBuscado, T nuevoValor) {
    if (nodo == nullptr) return;
    if (nodo->getDato() == valorBuscado) nodo->setDato(nuevoValor);
    reemplazarRecursivo(nodo->getSiguiente(), valorBuscado, nuevoValor);
}

template <typename T>
void Cola<T>::mostrar() const {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        printf("%d ", actual->getDato());
        actual = actual->getSiguiente();
    }
    printf("\n");
}

#endif
