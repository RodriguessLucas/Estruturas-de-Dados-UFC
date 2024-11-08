#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL;
int tam = 0;


void add(int valor, int pos){

    //criar o no e seto os valores dele
    NO * novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if(inicio == NULL){ //lista vazia!
        inicio = novo;
        tam++;
    }else if(pos == 0){ // no inicio da lista
        novo->prox = inicio;
        inicio = novo;
        tam++;
    }else if(pos == tam){ //no fim da lista
        //1 - crio uma variavel auxiliar (aux) para caminhar na lista
        NO * aux = inicio;
        for(int i = 0; i< tam-1; i++){
            aux = aux->prox;
        }
        aux->prox = novo;
        tam++;

    }else{

        NO *atual = inicio;
        NO *anterior = NULL;

        for(int i = 0; i < pos; i++){
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = novo;
        novo->prox = atual;
        tam++;
    }
}

void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i< tam; i++){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

int main(){

    add(20, 0);
    add(30, 0);
    add(5, 0);
    add(3, 3);
    add(12, 2);
    printf("tam: %d\n", tam);
    imprimir();
    return 0;
}

