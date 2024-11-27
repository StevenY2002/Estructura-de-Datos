
#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
private:
    T dato;
    Nodo* siguiente;

public:
    Nodo(T valor);
    T getDato() const;
    void setDato(T valor);
    Nodo* getSiguiente() const;
    void setSiguiente(Nodo* nodo);
};

template <typename T>
Nodo<T>::Nodo(T valor) : dato(valor), siguiente(nullptr) {}

template <typename T>
T Nodo<T>::getDato() const {
    return dato;
}

template <typename T>
void Nodo<T>::setDato(T valor) {
    dato = valor;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente() const {
    return siguiente;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo* nodo) {
    siguiente = nodo;
}

#endif
