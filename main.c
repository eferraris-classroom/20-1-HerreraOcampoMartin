#include <stdio.h>
#include "src/ListaDoble.h"

int main() {

    Lista *lista = crearLista();

    agregarNodo(lista, crearNodo(43));
    agregarNodo(lista, crearNodo(456));
    agregarNodo(lista, crearNodo(654));
    agregarNodo(lista, crearNodo(324));
    agregarNodo(lista, crearNodo(1));
    agregarNodo(lista, crearNodo(54));
    printf("\nLista original:\n");
    imprimirLista(lista);


    int valorAEliminar = 43;
    eliminarNodo(lista, valorAEliminar);
    printf("\nNodo %d eliminado:\n", valorAEliminar);
    imprimirLista(lista);


    int valorOriginal = 456, valorNuevo = 46;
    modificarNodo(lista, valorOriginal, valorNuevo);
    printf("\nValor %d cambiado por %d:\n", valorOriginal, valorNuevo);
    imprimirLista(lista);


    ordenarLista(lista);
    printf("\nLista ordenada:\n");
    imprimirLista(lista);

    printf("\nLista invertida:\n");
    imprimirListaInvertida(lista);

    liberarLista(lista);

    return 0;
}
