#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>

Cola::Cola() : cabeza(nullptr), cola(nullptr) {}

Cola::~Cola() {
    while (cabeza != nullptr) {
        Nodo* aux = cabeza;
        cabeza = cabeza->getSiguiente();
        delete aux;
    }
}

void Cola::ingresarPorCola(int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (cola == nullptr) {
        cabeza = cola = nuevo;
    } else {
        cola->setSiguiente(nuevo);
        cola = nuevo;
    }
}

void Cola::ingresarPorCabeza(int valor) {
    Nodo* nuevo = new Nodo(valor);
    if (cabeza == nullptr) {
        cabeza = cola = nuevo;
    } else {
        nuevo->setSiguiente(cabeza);
        cabeza = nuevo;
    }
}

bool Cola::eliminar(int valor) {
    if (cabeza == nullptr) return false;

    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

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

bool Cola::buscar(int valor) const {
    return buscarRecursivo(cabeza, valor) != nullptr;
}

Nodo* Cola::buscarRecursivo(Nodo* nodo, int valor) const {
    if (nodo == nullptr) return nullptr;
    if (nodo->getDato() == valor) return nodo;
    return buscarRecursivo(nodo->getSiguiente(), valor);
}

void Cola::reemplazar(int valorBuscado, int nuevoValor) {
    reemplazarRecursivo(cabeza, valorBuscado, nuevoValor);
}

void Cola::reemplazarRecursivo(Nodo* nodo, int valorBuscado, int nuevoValor) {
    if (nodo == nullptr) return;
    if (nodo->getDato() == valorBuscado) nodo->setDato(nuevoValor);
    reemplazarRecursivo(nodo->getSiguiente(), valorBuscado, nuevoValor);
}

void Cola::mostrar() const {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        printf("%d ", actual->getDato());
        actual = actual->getSiguiente();
    }
    printf("\n");
}
