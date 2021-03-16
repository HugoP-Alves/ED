#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXTAM 100

/* tipo abstrato para item, que será inserido na pilha */
typedef struct {
  int chave;
} Objeto;

/* tipo abstrato de pilha */
typedef struct {
  Objeto array[MAXTAM];
  int topo;
} pilhaEstatica;

void iniciaPilha(pilhaEstatica *pilha) {
    pilha->topo = 0;
}

bool estaVazia(pilhaEstatica *pilha) {
    return(pilha->topo == 0);
}

bool estaCheia(pilhaEstatica *pilha) {
    return(pilha->topo == MAXTAM);
}

void empilha(Objeto item, pilhaEstatica *pilha) {
    if(estaCheia(pilha) == 0){
        pilha->array[pilha->topo] = item; 
    }
    else{
        printf("Pilha Cheia");
    }
    pilha->topo++;
}

void desempilha(pilhaEstatica *pilha) {
    int i = pilha->topo;
    if(estaVazia(pilha) == 0){
        pilha->topo--;
    }
    else
        printf("Pilha vazia");
}

int tamanhoPilha(pilhaEstatica *pilha) {
    return pilha->topo;
}

Objeto topo(pilhaEstatica *pilha) {
    return pilha->array[pilha->topo-1];
}

void imprimePilha(pilhaEstatica *pilha) {
    if(estaVazia(pilha) == 0){
        printf("Pilha: { ");
        for(int i = (pilha->topo-1); i>=0; i--){
            printf("%i ", pilha->array[i].chave);
        }
        printf("}\n");
    }
    else{
        printf("Pilha vazia");
    }
}

int main(){
    Objeto item;
    pilhaEstatica pilha;

    iniciaPilha(&pilha);
    
    for(int i = 0; i < 5; i++) {
        item.chave = i;
        empilha(item, &pilha);
    }
    printf("\n\nEMPILHOU\n");

    imprimePilha(&pilha);

    Objeto top = topo(&pilha);

    printf("Topo = %i\n", top.chave);

    printf("Tamanho: %i \n", tamanhoPilha(&pilha));

    for(int i = 0; i < 5; i++) {
       desempilha(&pilha);
    }

    printf("\nDESEMPILHOU\n");
    printf("Tamanho: %i \n", tamanhoPilha(&pilha));

    return 0;
}