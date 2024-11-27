#include "Cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

template <typename T>
T ingresar(const char* mensaje) {
    char buffer[50];
    T numero;
    int valido;

    do {
        valido = 1;
        printf("%s", mensaje);
        scanf("%s", buffer);

        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isdigit(buffer[i])) {
                printf("Error: ingrese un número válido.\n");
                valido = 0;
                break;
            }
        }
    } while (!valido);

    numero = static_cast<T>(atoi(buffer));
    return numero;
}

int main() {
    Cola<int> cola;
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Ingresar por cola\n");
        printf("2. Ingresar por cabeza\n");
        printf("3. Eliminar elemento\n");
        printf("4. Buscar elemento\n");
        printf("5. Reemplazar elemento\n");
        printf("6. Mostrar cola\n");
        printf("7. Salir\n");
        opcion = ingresar<int>("Seleccione una opción: ");

        switch (opcion) {
        case 1:
            cola.ingresarPorCola(ingresar<int>("Ingrese el valor: "));
            break;
        case 2:
            cola.ingresarPorCabeza(ingresar<int>("Ingrese el valor: "));
            break;
        case 3:
            if (cola.eliminar(ingresar<int>("Ingrese el valor a eliminar: ")))
                printf("Elemento eliminado.\n");
            else
                printf("Elemento no encontrado.\n");
            break;
        case 4:
            if (cola.buscar(ingresar<int>("Ingrese el valor a buscar: ")))
                printf("Elemento encontrado.\n");
            else
                printf("Elemento no encontrado.\n");
            break;
        case 5:
            cola.reemplazar(
                ingresar<int>("Ingrese el valor a buscar: "),
                ingresar<int>("Ingrese el nuevo valor: ")
            );
            break;
        case 6:
            cola.mostrar();
            break;
        case 7:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción inválida.\n");
        }
    } while (opcion != 7);

    return 0;
}