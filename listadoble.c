#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int val;
    struct nodo *siguiente;
    struct nodo *anterior;
} NODO;


NODO *CrearNodo(int val);
int insertar(NODO **start, int val);
void mostrar(NODO *start);
int borrar(NODO **start, int val);


int main()
{
    NODO *start = NULL;
    int i, num, num1;
    do{
		printf("Ingresa un numero: \t 1. Ingresar números a la lista \t 2. Mostrar la lista \t 3. Eliminar un número \t 0. Salir\n");
		scanf("%i",&i);	
        switch (i) {
            case 1:
                printf("Ingresa un numero: ");
                scanf("%i",&num);
                insertar(&start, num);
                break;

            case 2:
                mostrar(start);
                break;
            case 3:
                printf("Ingresa el número que deseas eliminar: ");
                scanf("%i",&num1);
                borrar(&start,num1);
                break;
        }
	}while(i > 0);

    return 0;
}

int borrar(NODO **start, int val)
{
    NODO *actual = *start, *ant = NULL, *sig = NULL;

    while(actual != NULL)
    {
        if(actual->val == val)
        {
            if( actual == *start)
            {
                *start = actual->siguiente;
                if( actual->siguiente != NULL)
                    actual->siguiente->anterior = NULL;
            }
            else if( actual->siguiente == NULL)
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                ant->siguiente = NULL;
            }
            else
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                sig = actual->siguiente;
                actual->siguiente = NULL;
                ant->siguiente = sig;
                sig->anterior = ant;
            }
            free(actual);
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

void mostrar(NODO *start)
{
    NODO *nAux = start;

    while(nAux != NULL)
    {
        printf("|%x||%d||%x| ",nAux, nAux->val, nAux->siguiente);
        nAux = nAux->siguiente;
    }
    printf("\n");
}

int insertar(NODO **start, int val)
{
    NODO *nuevo = NULL;

    nuevo = CrearNodo(val);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *start;
        nuevo->anterior = NULL;
        if( *start != NULL)
            (*start)->anterior = nuevo;
        *start = nuevo;
        return 1;
    }
    return 0;
}

NODO *CrearNodo(int val)
{
    NODO* nuevo = NULL;

    nuevo = (NODO*)malloc(sizeof(NODO));
    if( nuevo != NULL)
    {
        nuevo->val = val;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    return nuevo;
}
