#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct no{
    char *nome;
    float minuto;
    struct no *ant;
    struct no *prox;
}NO;


void adicionar(char *nome_musica, float minuto);
void remover(char *nome_musica, float minuto);
void tocarUmaMusica(char *nome_musica, float minuto);
void tocarPlayList();

NO *inicio = NULL;

int main(){   
    // ADD
    adicionar("Exemplo da musica", 2.5);
    // Remove
    remover("Exemplo da musica", 2.5);
    // Seleciona uma musica da playlist
    tocarUmaMusica("Exemplo da musica", 2.5);
    // Toda a playlist uma vez(poderia ficar em loop infinito mas ai o pc vai de arrasta pra cima).
    tocarPlayList();
};
// Adiciona músicas da lista circular
void adicionar(char *nome_musica, float minuto){
    NO * novo = malloc(sizeof(NO));
    novo->nome = nome_musica;
    novo->minuto = minuto;
    novo-> prox = NULL;
    novo-> ant = NULL;

    if (inicio == NULL){
        inicio = novo;
        novo -> prox = novo;
        novo -> ant = novo;
    }
    else{
        novo -> prox = inicio;
        novo -> ant = inicio ->ant;
        inicio -> ant -> prox = novo;
        inicio -> ant = novo;
    };
};
// Remove músicas da lista circular
void remover( char *nome_musica, float minuto){
    NO * lixo = inicio;
    // Se estiver vazio
    if (lixo == NULL){
        printf("Playlist esta vazia \nadicione uma musica primeiro.\n");
    }
    // Se houver somente uma música
    else if(lixo->nome == lixo->prox->nome && lixo->minuto == lixo->prox->minuto){
        lixo->prox = NULL;
    }
    // Se houver a partir de uma musica na playlist
    else{
        // Se estiver no inicio 
        if (lixo->nome == nome_musica && lixo->minuto == minuto){
            lixo ->ant ->prox = lixo -> prox;
            lixo -> prox -> ant = lixo -> ant;
            inicio = lixo-> prox;
        }
        // No "final" da playlist
        else if(lixo->ant->nome == nome_musica && lixo->ant->minuto == minuto){
            lixo = lixo->prox;
            lixo ->ant-> prox = lixo ->prox;
            lixo->prox->ant = lixo->ant;
        }
        // No meio da playlist
        else{
            // Para iniciar o while depois do inicio
            lixo = lixo->prox;
            // Percorrer a playlist 
            while (lixo -> nome != nome_musica && lixo -> minuto != minuto){
                if (lixo->nome == inicio->ant->nome && lixo->minuto == inicio->ant->minuto){
                    printf("A musica nao esta na playlist\n.");
                    break;
                };
            };
            lixo ->ant-> prox = lixo ->prox;
            lixo->prox->ant = lixo->ant;
        };
    };
    printf("Removendo da playlist... --%s -- %.2f minutos--\n", lixo->nome, lixo->minuto);
    free(lixo);
};

// Busca uma música 
void tocarUmaMusica(char *nome_musica, float minuto){
    NO *aux = inicio;
    // Se estiver vazio
    if(aux == NULL){
        printf("Playlist esta vazia\n adicione uma musica primeiro.\n");
    }
    // Buscar musica na playlist
    else{
        // Se estiver no final
        if(aux->ant->nome == nome_musica && aux->ant->minuto == minuto){
            printf("Tocando... --%s -- %.2f minutos--\n", aux->ant->nome, aux->ant->minuto);
        }
        // Se estiver no inicio ou meio da playlist
        else{
            // Percorrer a playlist
            while(aux->nome != inicio->ant->nome && aux->minuto != inicio->ant->minuto){
                if(aux->nome == nome_musica && aux->minuto == minuto){
                    printf("Tocando... --%s -- %.2f minutos--\n", aux->nome, aux->minuto);
                }
                aux = aux->prox;
            };
            printf("Musica nao encontrada.\n");
        };
    };
};

// Toca toda a playlist uma vez
void tocarPlayList(){
    NO * aux = inicio;
    int fimPlayList = 0;
    if(aux != NULL && aux->prox != NULL){
        while(fimPlayList == 0){
            if(aux->prox->nome == inicio->nome && aux->prox->minuto == inicio->minuto){
                fimPlayList = 1;
                printf("Tocando... --%s -- %.2f minutos--\n", aux->nome, aux->minuto);
                aux = aux-> prox;
            }
            else{
                printf("Tocando... --%s -- %.2f minutos--\n", aux->nome, aux->minuto);
                aux = aux->prox;
            };
        };
    }
    else{
        printf("Playlist vazia!\n");
    };
};
