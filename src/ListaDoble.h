#ifndef INC_20_1_HERRERAOCAMPOMARTIN_LISTADOBLE_H
#define INC_20_1_HERRERAOCAMPOMARTIN_LISTADOBLE_H

typedef struct nodo{
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
} Nodo;

typedef struct lista {
    int tam;
    Nodo *primero;
} Lista;

Lista *crearLista();
Nodo *crearNodo(int valor);
void agregarNodo(Lista *lista, Nodo *nuevo);
void eliminarNodo(Lista *lista, int valorAEliminar);
void modificarNodo(Lista *lista, int valorOriginal, int valorNuevo);
void ordenarLista(Lista *lista);
void imprimirLista(Lista *lista);
void imprimirListaInvertida(Lista *lista);
void liberarLista(Lista *lista);

#endif
