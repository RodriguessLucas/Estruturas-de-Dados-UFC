#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void add_ordenado (int valor_add){

    // Tatiane, deu um trabalho kkk. Pois estavamos tentando usar for, 3 meses de greve dá nisso 😔😔😔😔
    // Cria o nó
    NO * novo = malloc(sizeof(NO));
    novo ->valor = valor_add;
    novo ->prox = NULL;

    //Se a lista estiver vazia
    if(inicio == NULL){
        inicio = novo;
        fim = novo;
    }
    // no inico da lista com elementos
    else if(inicio -> valor >= valor_add){
        novo ->prox = inicio;
        inicio = novo;
    }
    //No meio e final da lista
    else{
        NO * aux = inicio;
        while (aux-> prox != NULL && aux -> prox-> valor < valor_add)
        {
            aux = aux ->prox;
        };
        // operação de encaixe
        novo ->prox = aux ->prox;
        aux -> prox = novo;
    };
    tam++;
    
};

void add(int valor, int pos){

    if(pos >= 0 && pos <= tam){
        //criar o no e seto os valores dele
        NO * novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;

        if(inicio == NULL){ //lista vazia!
            inicio = novo;
            fim = novo;
        }else if(pos == 0){ // no inicio da lista
            novo->prox = inicio;
            inicio = novo;
        }else if(pos == tam){ //no fim da lista
            fim->prox = novo;
            fim = novo;
        }else{
            // no "meio" da lista
            NO * aux = inicio;
            for(int i = 0; i< pos-1; i++){
                aux = aux->prox;
            }
            //realizar as operacoes de encaixe!!! :D
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        tam++;
    }else{
        printf("Insercao nao realizada. Posicao %d eh invalida!\n", pos);
    };
};


int remover(int pos){
    if(pos >= 0 && pos < tam){ //pos valida!
        int valor;
        NO *lixo;
        if(pos == 0){
            //inicio
            lixo = inicio;
            inicio = inicio->prox;

            if(tam == 1){
                fim = fim->prox;
            }
        }else if(pos == tam -1){
            NO* aux = inicio;
            for (int i =0; i<pos-1; i++){
                aux = aux->prox;
            }
            lixo = aux->prox;
            aux->prox = NULL;
        }else{
            //"meio"
            NO* aux = inicio;
            for (int i =0; i<pos-1; i++){
                aux = aux->prox;
            }
            lixo = aux->prox;
            aux->prox = lixo->prox;
            fim = aux;
        };
        valor = lixo->valor;
        free(lixo);
        tam--;
        return valor;
    }else{
        printf("Remocao nao realizada. Posicao %d eh invalida!\n", pos);
        return -1;
    }
}

void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i< tam; i++){
        printf("%d\n", aux->valor);
        aux = aux->prox;
    };
};

int main(){

    /*add(20, 0); 
    add(30, 0); 
    add(5, 0); 
    add(3, 3); 
    add(12, 2); 
    printf("tam: %d\n", tam); 
    imprimir();
    printf("Testando a remoção\n"); 
    printf("Valor removido= %d\n", 
    remover(3)); 
    printf("Lista atualizada\n");
    imprimir(); 
    printf("tam: %d\n", tam);*/

    add_ordenado(1);
    add_ordenado(3);
    add_ordenado(3);
    add_ordenado(2);
    imprimir();



    return 0;
};


