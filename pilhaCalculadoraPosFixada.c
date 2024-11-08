/*  1 - Implemente uma calculadora pós-fixada, contendo as operações básicas (+, -, *, /).
Dica 1: notação pós-fixada é aquela que se digita primeiro os numero depois os operandos
Exemplo: 1 2 - 4 5 + * = -9
Dica 2: considere apenas as operações básicas (+, -, *, /)!
Dica 3: considere numeroes apenas inteiros de 0 até 9!
Dica 4: considere que a sequência de operações sempre estarão corretas para uma calculadora pós-fixada,
ou seja, você não precisará tratar casos de dado de entrada errados!  */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct no{
  int numero;
  char operacao;
  struct no * prox;
}NO;

NO * topo = NULL; 
int tam = 0;

void empilhar_numeros(int numero){
  NO * novo = malloc(sizeof(NO));
  novo->numero = numero;
  novo->prox = NULL;

  if(topo == NULL){ //pilha vazia!
    topo = novo;
  }else{ // no topo da pilha
    novo->prox = topo;
    topo = novo;
  };

  tam++;
};

int desempilhar(){
  if (topo == NULL){
    printf("Pilha vazia!\n");
  };
  
  int numero;
  NO *lixo;
  //topo
  lixo = topo;
  topo = topo->prox;
  numero = lixo->numero;
  free(lixo);
  tam--;      
  return numero;
};

void empilhar_operacao(char operacao){
  NO * aux = topo;

  switch (operacao){
    case '+':
      aux->prox-> numero = aux->prox->numero + aux->numero;
      //printf(" fazendo operacao de adicao: %i", aux->prox->numero);
      desempilhar();
      break;
    
    case '-':
      aux->prox-> numero = aux->prox->numero - aux->numero;
      //printf(" fazendo operacao de subtracao: %i", aux->prox->numero);
      desempilhar();
      break;

    case '*':
      aux->prox-> numero = aux->prox->numero * aux->numero;
      //printf(" fazendo operacao de multiplicacao: %i", aux->prox->numero);
      desempilhar();
      break;

    case '/':
      aux->prox-> numero = aux->prox->numero / aux->numero;
      //printf(" fazendo operacao de divisao: %i", aux->prox->numero);
      desempilhar();
      break;

    default:
      break;
  };
};

void imprimir(){
  NO * aux = topo;
  
  for(int i = 0; i< tam; i++){
    printf("%d\n", aux->numero);
    aux = aux->prox;
  }

}

void converter(char *expressao){
  for(int i = 0; expressao[i] != '\0' ;i++){
      if(isdigit(expressao[i])){
        int valor = expressao[i] - '0';
        empilhar_numeros(valor);
      }
      else if (expressao[i] ==  ' '){
        continue;
      }
      else{
        empilhar_operacao(expressao[i]);
      };
    };
}

int main(){
    char expressao[100];
    printf("Digite sua operacao:\n ");
    scanf("%[^\n]%*c", expressao);
    
    converter(expressao);

    if(topo !=NULL){
      printf("\nValor da expressao eh: %i\n", topo->numero);
    };

    return 0;
};


