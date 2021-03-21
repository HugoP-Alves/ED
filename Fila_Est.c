#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM 5

typedef struct {
  int chave;
} Objeto;

typedef struct {
  Objeto array[MAXTAM];
  int tamanho;
  int inicio;
  int fim;
} FilaEstatica;

void iniciaFila(FilaEstatica *fila){
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = -1;
}

bool estaVazia(FilaEstatica *fila){
    return (fila->tamanho == 0);
}

bool estaCheia(FilaEstatica *fila){
    return (fila->tamanho == MAXTAM);
}

int tamanhoFila(FilaEstatica *fila){
    return fila->tamanho;
}

//verificar-------------------
int incrementaIndice(int i){
    if(i+1 >=  MAXTAM) //se já estiver na última casa, volta para a primeira (cíclico)
        i = 0;
        else
            i++;
            return i;
}

void enfileira(Objeto x, FilaEstatica *fila){
    if(!estaCheia(fila)){
        fila->fim = incrementaIndice(fila->fim); //chama função de incrementar
        fila->tamanho++;
        fila->array[fila->fim] = x; //enfileira o conteúdo passado por parâmetro
    }
    else
        printf("FILA CHEIA\n");
}

//verificar ----------------
void imprimeFila(FilaEstatica *fila){
    printf("\nFila: { ");
    //percorre a fila apresentando o conteúdo enfileirado
    for(int i = fila->inicio; i <= fila->fim; i = incrementaIndice(i)){
        printf("%i ", fila->array[i].chave);
    }
    printf("}\n");
}

Objeto desenfileira(FilaEstatica *fila){
    if(!estaVazia(fila)){
        Objeto aux = fila->array[fila->inicio]; //auxiliar recebe o conteúdo do início
        fila->inicio = incrementaIndice(fila->inicio); //chama a função de incrementar
        fila->tamanho--;
        return aux; //retorna o conteúdo que estava no início e foi desenfileirado
    }
    else
        printf("FILA VAZIA\n");
}

Objeto inicioFila(FilaEstatica *fila){
    return fila->array[fila->inicio];
}

Objeto fimFila(FilaEstatica *fila){
    return fila->array[fila->fim];
}

int main (){
    FilaEstatica fila;
    Objeto obj;

    iniciaFila(&fila);

    for(int i = 5; i < 9; i++){
        obj.chave = i;
        if(!estaCheia(&fila))
        printf("Enfileirou: %i\n", i);
        enfileira(obj, &fila);
    }
    imprimeFila(&fila);
    
    obj=desenfileira(&fila);
    printf("Desenfileirou: %i\n",obj.chave);
    imprimeFila(&fila);

    for(int i = 1; i < 4; i++){
        obj.chave = i;
        if(!estaCheia(&fila))
        printf("Enfileirou: %i\n", i);
        enfileira(obj, &fila);
    }
    printf("Tamanho: %i\n", tamanhoFila(&fila));

    obj=fimFila(&fila);
    printf("Último: %i\n",obj.chave);
    obj=inicioFila(&fila);
    printf("Primeiro: %i\n",obj.chave);
    return 0;
}