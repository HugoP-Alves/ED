#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoPilha* PtrNoPilha;

typedef struct NoPilha{
  Objeto obj;
  PtrNoPilha proximo;
} NoPilha;

typedef struct {
  PtrNoPilha topo;
  int tamanho;
} PilhaDinamica;

void iniciaPilha(PilhaDinamica *p){
    p->topo = NULL;
    p->tamanho = 0;
}
bool estaVazia(PilhaDinamica *p){
    return (p->tamanho == 0);
}
void empilha(Objeto obj, PilhaDinamica *p){

    PtrNoPilha Aux = (PtrNoPilha)malloc(sizeof(PtrNoPilha));
    Aux->obj = obj;
    Aux->proximo = p->topo;
    p->topo = Aux;
    p->tamanho++;
}
void desempilha(PilhaDinamica *p){
    if(!estaVazia(p)){
        PtrNoPilha Aux = p->topo;
        p->topo = Aux->proximo;
        free(Aux);
        p->tamanho--;
    }
    else
        printf("Pilha vazia!");
}
int tamanhoPilha(PilhaDinamica *p){
    return p->tamanho;
}
    /*Outra opção seria usar retorno de Objeto: 
    Objeto topo(PilhaDinamica *p){
    return p->topo->obj; 
    }
    */
void topo(PilhaDinamica *p){
    printf("Topo: %i\n", p->topo->obj.chave);
}
void imprimePilha(PilhaDinamica *p){
    if(!estaVazia(p)){
    PtrNoPilha Aux;
    printf("Pilha: { ");
        for(Aux = p->topo; Aux != NULL; Aux = Aux->proximo) {
            printf("%i ", Aux->obj.chave);
        }
    printf("}");
    }
    else
        printf("Está vazia");
}

int main(){
    Objeto objeto;
    PilhaDinamica pilha;

    iniciaPilha(&pilha);

    for(int i = 1; i < 10; i++) {
        objeto.chave = i;
        empilha(objeto, &pilha);
    }
    printf("\n\nEMPILHOU\n");
    printf("Tamanho: %i\n",tamanhoPilha(&pilha));
    topo(&pilha);
    imprimePilha(&pilha);

    /*Utilizando retorno de Objeto:
    Objeto Aux = topo(&pilha);
    printf("Topo: %i\n", Aux.chave);
    */
    for(int i = 1; i < 10; i++) {
        desempilha(&pilha);
    }
    printf("\n\nDESEMPILHOU\n");
    printf("Tamanho: %i\n",tamanhoPilha(&pilha));

    return 0;
}