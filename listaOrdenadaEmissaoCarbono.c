/*
 Estudando o código, você compreende que se trata de uma TAD onde a adição deve ser feita ordenando as cidades de forma
 decrescente por toneladas de carbono emitidas. Logo, você nota que Altamira (PA), São Félix do Xingu (PA) e Porto Velho (RO)
 lideram o ranking. Na verdade, oito cidades da Amazônia estariam nas primeiras colocações da TAD, caso adicionadas, pelo mesmo
 motivo: desmatamento. Você começa a compreender melhor sobre o problema e pede para seus amigos para fazer parte do projeto.
Para tal, você decide fazer as seguintes contribuições no projeto:
 1- (2.5) Incluir o código ausente na função adicionar. Neste caso, você deve apresentar as linhas de código para
 garantir que as cidades sejam adicionadas de forma decrescente por toneladas de carbono emitidas.
 2- (2.5) Realizar a análise de complexidade simplificada vista em sala de aula (linear ou constante) de cada um dos
 casos das funções de adicionar e remover do código acima, justificando de forma curta cada uma delas

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  char *cidade;
  double toneladas_cab;
  struct no *prox;
} NO;

NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;

void adicionar(char *cidade, int toneladas_cab) {

  NO *novo = malloc(sizeof(NO));
  novo->cidade = cidade;
  novo->toneladas_cab = toneladas_cab;
  novo->prox = NULL;

    if (inicio == NULL) {

        inicio = novo;
        fim = novo;
        tam++;

    } 
    else {

    // adicionar no final da lista sendo novo menor que fim;
        if (novo->toneladas_cab < fim->toneladas_cab) {
            fim->prox = novo;
            fim = novo;
            tam++;
        }

    // adicionar no inicio da lista;
        else if (novo->toneladas_cab > inicio->toneladas_cab) {

            novo->prox = inicio;
            inicio = novo;
            tam++;
        }

    // adicionar no meio da lista;
        else {

            NO *aux = inicio;

            while (novo->toneladas_cab < aux->prox->toneladas_cab) {
                aux = aux->prox;
                };
            novo->prox = aux->prox;
            aux->prox = novo;
            tam++;
        };
    };
};

char *remover() {
  char *cidade = "Sem opcoes!";

  if (inicio != NULL) {

    NO *lixo = inicio;
    cidade = inicio->cidade;
    inicio = inicio->prox;
    free(lixo);
    tam--;
  }

  return cidade;
}

void imprimir() {

  NO *aux = inicio;

  for (int i = 0; i < tam; i++) {
    printf("Cidade: %s\n", aux->cidade);
    printf("Toneladas de Carbono: %.2f\n\n", aux->toneladas_cab);
    aux = aux->prox;
  };
};

int main() {
  adicionar("Rio de Janeiro", 13.8);
  adicionar("Sao Paulo", 16.6);
  adicionar("Porto Velho", 23.3);
  adicionar("Altamira", 35.2);
  adicionar("Sao Felix do Xingu", 28.9);

  printf("\nMunicipios e emissoes de gases do efeito estufa (dados em milhoes de "
        " toneladas de CO2e):\n");
  printf("\n");
  printf("Cidade com maior qtd de GEE: %s.\n", remover());
  printf("\n");
  imprimir();
  return 0;
}