#include "ListaDoble.h"
#include <stdlib.h>
#include <stdio.h>

Lista *crearLista(){
    Lista *lista = (Lista *) malloc(sizeof (Lista));

    if (lista == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    lista->tam = 0;
    lista->primero = NULL;

    return lista;
}

Nodo *crearNodo(int valor){
    Nodo *nuevo = (Nodo*) malloc(sizeof (Nodo));

    if(nuevo == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    nuevo->valor = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}

void agregarNodo(Lista *lista, Nodo *nuevo){
    if(lista->primero != NULL){
        lista->primero->anterior = nuevo;
    }
    nuevo->siguiente = lista->primero;
    lista->primero = nuevo;
    lista->tam++;
}

void eliminarNodo(Lista *lista, int valorAEliminar){
    Nodo *aux = lista->primero;

    while (aux != NULL && aux->valor != valorAEliminar){
        aux = aux->siguiente;
    }

    if(aux == NULL){
        return;
    }

    if(aux->anterior == NULL){
        aux->siguiente->anterior = NULL;
        lista->primero = aux->siguiente;
    }else {
        aux->anterior->siguiente = aux->siguiente;
        if(aux->siguiente != NULL){
            aux->siguiente->anterior = aux->anterior;
        }
    }

    free(aux);
    lista->tam--;
}

void modificarNodo(Lista *lista, int valorOriginal, int valorNuevo){
    Nodo *aux = lista->primero;

    while (aux != NULL && aux->valor != valorOriginal){
        aux = aux->siguiente;
    }

    if(aux == NULL){
        return;
    }

    aux->valor = valorNuevo;
}

void intercambiarNodos(Lista *lista, Nodo *nodo1, Nodo *nodo2){
    /*int aux = nodo1->valor;
    nodo1->valor = nodo2->valor;
    nodo2->valor = aux;*/

    // Alternativa, por si hay más valores que intercambiar. En este caso es fácil cambiar los
    // valores porque solo es un int, pero si fuera una estructura más compleja conviene más:
    Nodo *auxAnterior = nodo1->anterior;
    nodo1->siguiente = nodo2->siguiente;
    nodo1->anterior = nodo2;
    nodo2->siguiente = nodo1;
    nodo2->anterior = auxAnterior;

    if(nodo2->anterior != NULL){
        nodo2->anterior->siguiente = nodo2;
    }else {
        lista->primero = nodo2;
        // Si el nodo2->anterior es NULL, entonces es el primer elemento de la lista, así que
        // lo tengo que modificar
    }

    if(nodo1->siguiente != NULL){
        nodo1->siguiente->anterior = nodo1;
    }
}

void ordenarLista(Lista *lista){
    Nodo *aux = lista->primero;

    if (aux == NULL){
        printf("La lista está vacía.\n");
        return;
    }

    for (int i = 0; i < lista->tam; i++){
        for(; aux != NULL; aux = aux->siguiente){
            if(aux->siguiente != NULL && aux->valor > aux->siguiente->valor){
                intercambiarNodos(lista, aux, aux->siguiente);
            }
        }

        aux = lista->primero;
    }
}

void imprimirLista(Lista *lista){
    Nodo *aux = lista->primero;

    for(; aux != NULL; aux = aux->siguiente){
        printf("%d ", aux->valor);
    }

    printf("\n");
}

void imprimirListaInvertida(Lista *lista){
    Nodo *aux = lista->primero;

    if(aux == NULL){
        printf("La lista está vacía.\n");
        return;
    }

    for(; aux->siguiente != NULL; aux = aux->siguiente){} // Me muevo al final

    for(; aux != NULL; aux = aux->anterior){
        printf("%d ", aux->valor);
    }
}

void liberarLista(Lista *lista){
    Nodo *aux = lista->primero;

    if(aux != NULL){
        while(aux->siguiente != NULL){
            Nodo *ant = aux;
            aux = aux->siguiente;
            free(ant);
        }

        free(aux);
    }

    free(lista);
}

