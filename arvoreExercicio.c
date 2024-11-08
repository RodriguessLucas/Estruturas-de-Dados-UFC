// Lucas Rodrigues Pereira(557738) && Pedro Arthur Maia Gama(561538)

// Voce deve criar na main, uma arvore com pelo menos 15 vertices
// e com a chamada de pelo menos 5 remocoes, onde existam casos de remoção
// de folhas, nohs com 1 filho e nohs com 2 filhos.
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    //...
    struct no *esq;
    struct no *dir;
}NO;

NO* raiz = NULL;

NO* buscar(NO *aux, int chave){
    if(aux == NULL){
        return NULL;
    }else if(aux->chave == chave){
            return aux;     
    }else if(chave < aux->chave){
        if(aux->esq != NULL){
            return buscar(aux->esq, chave);
        }else{
            return aux;
        }
    }else{   
        if(aux->dir != NULL){
            return buscar(aux->dir, chave);
        }else{
            return aux;
        }
    }
}


void adicionar(int chave){

    NO *novo = malloc(sizeof(NO));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    NO *aux = buscar(raiz, chave);
    if(aux == NULL){
        raiz = novo;
    }else if(aux->chave == chave){
        printf("Adicao invalida! Chave duplicada!\n");
        free(novo);
    }else{ //retorna o pai do no novo!
        if(chave < aux->chave){
            aux->esq = novo;
        }else{
            aux->dir = novo;
        }
    }
}

void pre_ordem(NO* aux){
    //processamento
    printf("%d ", aux->chave);

    if(aux->esq != NULL){
        pre_ordem(aux->esq);
    }

    if(aux->dir != NULL){
        pre_ordem(aux->dir);
    }
}

void in_ordem(NO* aux){
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    //processamento
    printf("%d ", aux->chave);

    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

void pos_ordem(NO* aux){
    if(aux->esq != NULL){
        pos_ordem(aux->esq);
    }

    if(aux->dir != NULL){
        pos_ordem(aux->dir);
    }
    //processamento
    printf("%d ", aux->chave);
}

NO* remover(NO* aux, int chave) {
   //1 caso - vazia
    if (aux == NULL) {
        return NULL;
    } else if (chave < aux->chave) {
        aux->esq = remover(aux->esq, chave);
    } else if (chave > aux->chave) {
        aux->dir = remover(aux->dir, chave);
    } else { // encontrei!!! :D
        if (aux->esq == NULL && aux->dir == NULL) {
            //FOLHA
            free(aux);
            return NULL;
        } else if (aux->esq != NULL && aux->dir == NULL) {
            //1 filho: é o esq!
            NO* filho = aux->esq;
            free(aux);
            return filho;
        } else if (aux->esq == NULL && aux->dir != NULL) {
            //1 filho: é o dir!
            NO* filho = aux->dir;
            free(aux);
            return filho;
        } else if(aux->esq != NULL && aux->dir != NULL) {
            //2 filhos!
            NO* maiorDosMenores = aux->esq;
            while (maiorDosMenores->dir != NULL) {
                maiorDosMenores = maiorDosMenores->dir;
            }
            aux->chave = maiorDosMenores->chave;
            aux->esq = remover(aux->esq, maiorDosMenores->chave);
        }
    }
    return aux;
}

int main(){

    adicionar(12);
    adicionar(20);
    adicionar(24);
    adicionar(30);
    adicionar(10);
    adicionar(8);
    adicionar(5);
    adicionar(3);
    adicionar(2);
    adicionar(11);
    adicionar(6);
    adicionar(4);
    adicionar(16);
    adicionar(23);
    adicionar(22);
    adicionar(17);

    printf("Imprimindo em pre-ordem:\n");
    pre_ordem(raiz);
    remover(raiz,12);
    remover(raiz,6);
    remover(raiz,16);
    remover(raiz,22);
    remover(raiz,10);
    printf("Imprimindo em pre-ordem:\n");
    pre_ordem(raiz);
    
    return 0;

}