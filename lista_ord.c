#include<stdio.h> 
#include<stdlib.h> 

struct nodo 
{ 
    int val; 
    struct nodo *next; 
}; 
  

void insertar(struct nodo **inicio, int dato); 

void sort(struct nodo *start); 

void swap(struct nodo *a, struct nodo *b); 

void mostrar(struct nodo *start); 

int borrar(struct nodo **inicio, int dato);

void main() { 
    int i;
    int num, num1, p;     
	struct nodo *start = NULL; 
	do{
		printf("Ingresa un numero: \t 1. Ingresar números a la lista \t 2. Mostrar la lista \t 0. Salir\n");
		scanf("%i",&i);	
        switch (i) {
            case 1:
                printf("Ingresa un numero: ");
                scanf("%i",&num);
                insertar(&start, num);
                sort(start);
                break;

            case 2:
                mostrar(start);
                break;

            case 3:
                printf("Ingresa la posición del número que deseas eliminar: ");
                scanf("%i",&num1);
                p = borrar(&start,num1);

                printf("Se ha borrado el valor %d",p);
        }
	}while(i > 0);

} 

void insertar(struct nodo **inicio, int dato) { 
    struct nodo *n1 = (struct nodo*)malloc(sizeof(struct nodo)); 
    n1->val = dato; 
    n1->next = *inicio; 
    *inicio = n1; 
} 

void mostrar(struct nodo *start) { 
    struct nodo *punt = start; 
    printf("\n"); 
    while (punt!=NULL) 
    { 
        printf("|%d||%x| ", punt->val,punt); 
        punt = punt->next; 
    } 
    printf("\n");
} 

void sort(struct nodo *start) { 
    int camb, i; 
    struct nodo *n1; 
    struct nodo *nult = NULL; 

    if (start == NULL) 
        return; 
  
    do
    { 
        camb = 0; 
        n1 = start; 
  
        while (n1->next != nult) 
        { 
            if (n1->val > n1->next->val) 
            {  
                swap(n1, n1->next); 
                camb = 1; 
            } 
            n1 = n1->next; 
        } 
        nult = n1; 
    } 
    while (camb); 
} 

void swap(struct nodo *a, struct nodo *b) { 
    int temp = a->val; 
    a->val = b->val; 
    b->val = temp; 
}

int borrar(struct nodo **inicio, int pos) {
    struct nodo *actual = *inicio;
    int r;

    while(actual != NULL){
        if(actual->val == pos){
            *inicio = actual->next;
            r = actual->val;
            free(actual);
        }

        for(int i=0; i<pos-1; i++)
            actual = actual->next;

        struct nodo *sig = actual->next->next;
        r = actual->next->val;
        free(actual->next);
        actual->next = sig;
    }
    return r;
}