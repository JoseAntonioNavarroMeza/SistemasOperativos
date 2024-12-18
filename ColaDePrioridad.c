#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {//crear nodo
    char tarea[50];
    int prioridad;
    struct Nodo* siguiente;
};

typedef struct ColaPrioridad {//crear tipo de dato colaprioridad
    struct Nodo* cabeza;//puntero que apunta a la cabeza
} ColaPrioridad;

ColaPrioridad* crearCola() {//retorna un puntero
    ColaPrioridad* pq = (ColaPrioridad*)malloc(sizeof(ColaPrioridad));//reservar memoria
    pq->cabeza = NULL;
    return pq;
}
//insertar nodo
void insertar(ColaPrioridad* pq, char* tarea, int prioridad) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    strcpy(nuevoNodo->tarea, tarea);
    nuevoNodo->prioridad = prioridad;
    nuevoNodo->siguiente = NULL;
// si la cola esta vacia o el nuevo nodo tiene mayor prioridad que la cabeza
    if (pq->cabeza == NULL || pq->cabeza->prioridad < prioridad) {
        nuevoNodo->siguiente = pq->cabeza;
        pq->cabeza = nuevoNodo;
    } else {
        struct Nodo* actual = pq->cabeza;
//recorrer la lista
        while (actual->siguiente != NULL && actual->siguiente->prioridad >= prioridad) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

char* eliminar(ColaPrioridad* pq, int* prioridad) {
    if (pq->cabeza == NULL) {//verifica si la cola esta vacia
        return NULL;
    }
    struct Nodo* temp = pq->cabeza;
    pq->cabeza = pq->cabeza->siguiente;

    *prioridad = temp->prioridad;
    char* tarea = strdup(temp->tarea);
//liberar la memoria
    free(temp);
    return tarea;
}

char* peek(ColaPrioridad* pq) {
// Verificar si la cola está vacía
    if (pq->cabeza == NULL) {
        return NULL;
    }
// Retornar la tarea del nodo con mayor prioridad
    return pq->cabeza->tarea;
}

//checar si esta vacia
int isEmpty(ColaPrioridad* pq) {
    return pq->cabeza == NULL;
}
//eliminar todo
void liberarCola(ColaPrioridad* pq) {
    struct Nodo* actual = pq->cabeza;
    struct Nodo* siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(pq);
}

int main() {
    ColaPrioridad* pq = crearCola();

    insertar(pq, "Tarea 1", 1);
    insertar(pq, "Tarea 3", 5);
    insertar(pq, "Tarea 2", 2);

    printf("Tarea de mayor prioridad: %s\n", peek(pq));
// Variable para almacenar la prioridad de la tarea eliminada
    int prioridad;
// Mientras la cola no esté vacía, eliminar y mostrar tareas
    while (!isEmpty(pq)) {
// Eliminar la tarea con la mayor prioridad y obtener su prioridad
        char* tarea = eliminar(pq, &prioridad);
        printf("Ejecutando: %s (Prioridad: %d)\n", tarea, prioridad);
// Liberar la memoria de la tarea duplicada
        free(tarea);
    }

    liberarCola(pq);

    return 0;
}
