/*  2 - Simule o atendimento de pizzaria! Suponha que você irá criar um sistema que gerencia os pedidos de
uma pizzaria simples. O atendente irá receber o pedido do cliente: Recheio da pizza (Marguerita, Calabresa,
Frango ou 4 Queijos), tamanho (P, M, G), nome do cliente e valor. Você deve armazenar esses dados que
devem ser removidos pelo cozinheiro para preparação das pizzas. Para testar, faça uma chamada na
função main da funções add e remover, simulando o pedido de pelo menos 5 pizzas!  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pizza{
    char* sabor;
    char* tamanho;
}PIZZA;

typedef struct ordem{
    char * nomepessoa;
    float valor;
    PIZZA pizzaInfo;
}ORDEM;

typedef struct no{
    ORDEM pedido;
    struct no * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void fazerPedido(char *nomepessoa, char *sabor, char *tamanho, float valor){
    NO * novo = malloc(sizeof(NO));

    novo->pedido.nomepessoa = malloc(strlen(nomepessoa) + 1);
    strcpy(novo->pedido.nomepessoa, nomepessoa);

    novo->pedido.pizzaInfo.sabor = malloc(strlen(sabor) + 1);
    strcpy(novo->pedido.pizzaInfo.sabor, sabor);

    novo->pedido.pizzaInfo.tamanho = malloc(strlen(tamanho) + 1);
    strcpy(novo->pedido.pizzaInfo.tamanho, tamanho);

    novo->pedido.valor = valor;
    novo->prox = NULL;

    if(inicio == NULL){ 
        inicio = novo;
        fim = novo;
    }else {
        fim->prox = novo;
        fim = novo;
    }

    tam++;
}

ORDEM pedidoPronto(){
    ORDEM pedidoSaida;

    if(inicio != NULL){
        NO* lixo = inicio;
        pedidoSaida = lixo->pedido;
        inicio = inicio->prox;
        free(lixo->pedido.nomepessoa);
        free(lixo->pedido.pizzaInfo.sabor);
        free(lixo->pedido.pizzaInfo.tamanho);
        free(lixo);
        tam--;
    }else{
        printf("Fila vazia :'( ...\n");
    }
    return pedidoSaida;
}

void imprimir(){
    NO * aux = inicio;
    int i = 1;
    while (aux != NULL){
        printf("Pedido numero %i *\n - ", i++);
        printf("%s - ", aux->pedido.nomepessoa);
        printf("%s - ", aux->pedido.pizzaInfo.sabor);
        printf("%s - ", aux->pedido.pizzaInfo.tamanho);
        printf("%.2f\n", aux->pedido.valor);
        
        aux = aux->prox;
    }
}

int main(){
    fazerPedido("Sapo", "Margherita", "P", 15.00);
    imprimir();

    return 0;
}
