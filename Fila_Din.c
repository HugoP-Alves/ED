#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int chave;
} Objeto;

typedef struct NoFila *PtrNoFila;

typedef struct NoFila{
  Objeto obj;
  PtrNoFila proximo;
} NoFila;

typedef struct {
  PtrNoFila inicio;
  PtrNoFila fim;
  int tamanho;
} FilaDinamica;

void iniciaFila(FilaDinamica *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}
bool estaVazia(FilaDinamica *fila){
    return (fila->tamanho == 0);
}
void imprimeFila(FilaDinamica *fila){
    PtrNoFila aux;
    printf("Fila: { ");
    //percorrerá toda a fila exibindo seus elementos
    for(aux = fila->inicio; aux != NULL; aux=aux->proximo){
        printf("%i ", aux->obj.chave);
    }
    printf("}\n");
}
void enfileira(Objeto x, FilaDinamica *fila){
    PtrNoFila aux = (PtrNoFila)malloc(sizeof(PtrNoFila)); //aloca
    aux->obj = x; //auxiliar recebe o objeto
    if(estaVazia(fila)){ 
        fila->inicio = fila->fim = aux; //início e fim apontam para aux caso seja a primeira inserção
        aux->proximo = NULL; // próximo aponta para NULL
    }
    else{ //caso não esteja vazia
        aux->proximo = NULL;
        fila->fim->proximo = aux; // próxima aponta para aux (objeto que será inserido na fila)
        fila->fim = aux; // atualiza "fim", que agora é aux
    }
    fila->tamanho++;
}
 
int desenfileira(FilaDinamica *fila){
    if(!estaVazia(fila)){
        PtrNoFila aux;
        aux = fila->inicio; //aux recebe início
        fila->inicio = fila->inicio->proximo; //atualiza início ("próximo" é o novo início)
        int x = aux->obj.chave; //x recebe chave para depois ser retornado
        free(aux); //libera
        fila->tamanho--;
        return x;
    }
    else
        printf("FILA VAZIA!\n");
}

int tamanhoFila(FilaDinamica *fila){
    return fila->tamanho;
}
Objeto inicioFila(FilaDinamica *fila){
    return fila->inicio->obj;
}
Objeto fimFila(FilaDinamica *fila){
    return fila->fim->obj;
}


int main(){
    FilaDinamica fila;
    Objeto obj;

    iniciaFila(&fila);

    for(int i = 1; i <= 11; i+=2){
        obj.chave = i;
        enfileira(obj, &fila);
        printf("Enfileira: %i\n", i);
    }
    imprimeFila(&fila);
    printf("Tamanho: %i\n\n", tamanhoFila(&fila));

    for(int i = 0; i <= 5; i+=2){
        printf("Desenfileirar: %i\n", desenfileira(&fila));
    }
    imprimeFila(&fila);
    printf("Tamanho: %i\n\n", tamanhoFila(&fila));

    obj = inicioFila(&fila);
    printf("Primeiro: %i\n", obj.chave);
    obj = fimFila(&fila);
    printf("Último: %i\n", obj.chave);

    return 0;
}