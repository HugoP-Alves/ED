#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  {
  int chave;
} Objeto;

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    Objeto elemento;
    PtrNoLista proximo;
} NoLista;

typedef struct {
    PtrNoLista primeiro;
    int tamanho;
} Lista;

void iniciaLista(Lista *list){
    list->primeiro = NULL;
    list->tamanho = 0;
}

bool estaVazia(Lista *list){
    return (list->tamanho == 0);
}

int tamanhoLista(Lista *list){
    return list->tamanho;
}

void inserir(Lista *list, Objeto x){
    PtrNoLista Obj = (PtrNoLista) malloc (sizeof(PtrNoLista));
    Obj->elemento = x;

    if((estaVazia(list)) || (x.chave < list->primeiro->elemento.chave)){
        Obj->proximo = list->primeiro;
        list->primeiro = Obj;
    }
    else{
        PtrNoLista aux = list->primeiro;

        while((aux->proximo != NULL) && (x.chave > aux->proximo->elemento.chave)){
            aux = aux->proximo;
        }
        Obj->proximo = aux->proximo;
        aux->proximo = Obj;
    }
    list->tamanho++;

}

void imprimirLista(Lista *list){
    if(!estaVazia(list)){
    PtrNoLista aux;
    printf("Lista: { ");

    for(aux = list->primeiro; aux != NULL; 
    aux = aux->proximo){
        printf("%i ", aux->elemento.chave);
    }

    printf("}\n");
    }
    else
        printf("ESTÁ VAZIA!\n");
}

void destruirLista(Lista *list){
    PtrNoLista aux;
    while(list->primeiro != NULL){ 
        aux = list->primeiro;
        list->primeiro = list->primeiro->proximo;
        free(aux);
    }

}

bool pesquisar(Lista *list, int key){
    PtrNoLista aux;
    for(aux = list->primeiro; aux != NULL; 
    aux = aux->proximo){
        if(key == aux->elemento.chave)
            return 1;
    }
    return 0;
}
/*O primeiro elemento da lista será direcionado para o próximo
enquanto a auxiliar desaloca a "antiga" primeira posição
*/
void removePrimeiro(Lista *list){
    if(!estaVazia(list)){
    PtrNoLista aux = list->primeiro;
    list->primeiro = list->primeiro->proximo;
    free(aux);
    list->tamanho--;
    }
    else
    printf("ESTÁ VAZIA!\n");
}
/*
Caso o elemento esteja na lista, serão criadas 2 auxiliares. A primeira 
vai percorer a lista comparando a chave com os elementos até encontrar.
Após encontrar, a segunda aulixiar vai se igual com o elemento para em 
seguida desalocar. O próximo da auxiliar um será pulado para o sucessor
do elemento.
*/
void removeElemento(Lista *list, int chave){
    if(!estaVazia(list)){
        if(pesquisar(list, chave)){
    PtrNoLista aux;
    PtrNoLista aux2;
    aux = list->primeiro;
    if(list->primeiro->elemento.chave == chave)
        removePrimeiro(list);
        else{
    while(aux != NULL && aux->elemento.chave < chave){
        if(aux->proximo->elemento.chave == chave){
            aux2 = aux->proximo;
            aux->proximo = aux->proximo->proximo;
            free(aux2);
            list->tamanho--;
            printf("Removido: %i\n", chave);
        }
        aux = aux->proximo;
    }
    }
    }
    else
        printf("Elemento não está na lista!\n");
    }  
    else
        printf("PILHA VAZIA!");
}
/*
Serão criadas 2 auxiliares na função "removeUltimo": a primeira para percorrer a 
lista, e a segunda para auxiliar no momento que for desalocar.
Quando a primeira auxiliar estiver na penultima posição, a segunda auxiliar
vai para a ultima posição, logo em seguida desalocando com "free()".
A penultima vira a ultima com "proximo" apontando para NULL.
*/
void removeUltimo(Lista *list){
    if(!estaVazia(list)){
        if(tamanhoLista(list) == 1)
            removePrimeiro(list);
            else{
    PtrNoLista aux = list->primeiro;
    PtrNoLista aux2;
    while(aux->proximo->proximo != NULL){
        aux = aux->proximo;
    }
    aux2 = aux->proximo;
    aux->proximo = NULL;
    free(aux2); //confirmar
    list->tamanho--;
    }
    }
    else
    printf("ESTÁ VAZIA!\n");
}

Objeto primeiro(Lista *list){
    return list->primeiro->elemento;
}

Objeto ultimo(Lista *list){
    PtrNoLista aux = list->primeiro;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    return aux->elemento;
}

int main(){
    Lista list;
    Objeto obj;

    iniciaLista(&list);
    imprimirLista(&list);
    printf("Tamanho: %i\n\n",tamanhoLista(&list));
    
    obj.chave = 5;
    inserir(&list, obj);
    obj.chave = 7;
    inserir(&list, obj);
    obj.chave = 2;
    inserir(&list, obj);
    obj.chave = 9;
    inserir(&list, obj);
    obj.chave = 1;
    inserir(&list, obj);

    imprimirLista(&list);
    printf("Tamanho: %i\n\n",tamanhoLista(&list));

    removePrimeiro(&list);
    removeUltimo(&list);
    imprimirLista(&list);
    printf("Tamanho: %i\n\n",tamanhoLista(&list));

    obj = primeiro(&list);
    printf("Primeira: %i\n", obj.chave);

    obj = ultimo(&list);
    printf("Ultimo: %i\n", obj.chave);

    removeElemento(&list, 7);
    removeElemento(&list, 5);
    imprimirLista(&list);

obj.chave = 2;
    if(pesquisar(&list, obj.chave))
        printf("\nPesquisou: Elemento %i está na lista\n\n", obj.chave);
        else
            printf("\nPesquisou: Elemento %i não está na lista\n\n", obj.chave);
            //removeUltimo(&list);
            imprimirLista(&list);
            destruirLista(&list);
            printf("Lista destruida!\n");
            imprimirLista(&list);   

    return 0;
}