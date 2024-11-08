/* 1- Crie uma TAD para representar uma pessoa que ira ser cadastrado em um sistema de academia.
Dados necessarios: nome, matricula, idade, peso, altura*/

typedef struct Pessoa{
    char *nome;
    int matricula;
    int idade;
    float peso;
    float altura;
}aluno;

/* 2- Crie uma funcao que recebe os dados de um aluno da academia pelo terminal, salva esses dados 
em uma tad e apresenta no terminal seu nome e IMC */

void cria_tad_aluno(){
    
    aluno p1; 
    char nome[100];
    printf("Digite o nome do aluno: \n"); 
    scanf("%s", nome);
    p1.nome = nome;
    printf("Digite a matricula do aluno: \n");  
    scanf("%d", &p1.matricula);
    printf("Digite a idade do aluno: \n");  
    scanf("%d", &p1.idade);
    printf("Digite a peso do aluno: \n"); 
    scanf("%f", &p1.peso);
    printf("Digite a altura do aluno: \n");
    scanf("%f", &p1.altura);
    
    float imc = p1.peso/(p1.altura*p1.altura);
    printf("O aluno %s tem o imc = %.2f.\n", p1.nome, imc);
}

/* 3 - Crie uma TAD para representar um produto que ira ser cadastrado em um sistema de supermecado.
Dados necessarios: nome do produto, codigo de barra, preco, dia, mes e ano de validade*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Produto {
    char *nome;
    int codigo_barra;
    float preco;
    int dia;
    int mes;
    int ano;
}produto;

int main(){

    produto p1;

    printf("Digite o nome do produto:\n");
    scanf(" %s",&*p1.nome);

    printf("Digite o codigo de barras:\n");
    scanf("%d",&p1.codigo_barra);

    printf("Digite o preco do produto:\n");
    scanf("%f",&p1.preco);

    printf("Digite o dia em que vence o produto no formado dd/mm/aaaa:\n");
    scanf("%d/ %d/%d", &p1.dia, &p1.mes, &p1.ano);

    printf("O pruduto %s, tem o codigo de barras %d, com o valor de R$ %.2f, e data de validade %d/%d/%d",p1.nome, p1.codigo_barra, p1.preco, p1.dia, p1.mes, p1.ano);

    free(p1.nome);

    return 0;
}


/* 4 - Crie uma funcao que recebe os dados de um produto pelo terminal, salva esses dados 
em uma tad, verifica se ele esta dentro da validade, se sim apresenta no terminal seu nome 
e seu preco com desconto de 20%.
Se o produto esta fora da validade apenas apresenta seu nome e a informacao: fora da validade!*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Produto {
    char nome[100];
    int codigo_barra;
    float preco;
    int dia;
    int mes;
    int ano;
}produto;

int main(){
    int dia_atual, mes_atual, ano_atual;
    dia_atual = 7;
    mes_atual = 3;
    ano_atual = 2024;
    float desconto, valor_ja_descontado;
    desconto = 0.2;
    int boleano;
    produto p1;

    printf("Digite o nome do produto:\n");
    scanf(" %s", &p1.nome);

    printf("Digite o codigo de barras:\n");
    scanf("%16i", &p1.codigo_barra);

    printf("Digite o preco do produto:\n");
    scanf("%f", &p1.preco);

    printf("Digite o dia em que vence o produto no formado dd/mm/aaaa:\n");
    scanf("%d/ %d/%d", &p1.dia, &p1.mes, &p1.ano);


    if (p1.ano >= 0 && p1.ano <= 9999){
            
        if (p1.mes >= 0 && p1.mes <= 12){

            if ((p1.dia >= 1 && p1.dia <= 30) && (p1.mes == 4 || p1.mes == 6 || p1.mes == 9 || p1.mes == 11)){
                boleano = 1;
            }

            else if ((p1.dia >=1 && p1.dia <= 31) && (p1.mes == 1 || p1.mes == 3 || p1.mes == 5 || p1.mes == 7 || p1.mes == 10 || p1.mes == 12 )){
                boleano = 1;
            }
            else if ((p1.dia >= 1 && p1.dia <= 28) && (p1.mes == 2)){
                boleano =1;
            }

            else if (p1.dia == 29 && p1.mes ==2 && (p1.ano % 400 == 0 || (p1.ano % 4 == 0 && p1.ano % 100 != 0))){
                boleano =1;
            }
            else{
                printf("Data em fomato invalido.\n");
                boleano = 0;
            }
        }
        else{
            printf("Data em fomato invalido.\n");
            boleano = 0;
        }
    }
    else{
        printf("Data em formato invalido\n");
    }

    if (boleano == 1 && (ano_atual <= p1.ano || (ano_atual == p1.ano && mes_atual <= p1.mes) || (ano_atual == p1.ano && mes_atual == p1.mes && dia_atual <= p1.dia))) {
            
        valor_ja_descontado = p1.preco - (p1.preco* desconto);
        printf("O produto %s com desconto ficou no total R$ %.2f\n", p1.nome, valor_ja_descontado);
        printf("%i",p1.codigo_barra);
    }
    else if (boleano == 1 && (ano_atual <= p1.ano || (ano_atual == p1.ano && mes_atual <= p1.mes) || (ano_atual == p1.ano && mes_atual == p1.mes && dia_atual <= p1.dia))){
        printf("O %s esta fora de validade\n",p1.nome);
    }

    return 0;
}


/*5 - Crie um TAD para representar um aluno da disciplina de ED que ira ser cadastrado em um sistema no sigaa
Dados necessarios: nome, matricula, nota da avaliacao teorica, nota do trabalho de ordenacao, nota dos exercicios praticos*/

#include<stdio.h>
#include<stdlib.h>

typedef struct aluno{
    char *nome[100];
    int matricula;
    float nota_AT;
    float notar_TO;
    float nota_EP;
}cadastro;

int main(){

    cadastro aluno1;

    printf("Iremos iniciar o seu cadastro em ED \nInsira seus dados abaixo\n \n");
    printf("Digite seu nome completo:\n");
    scanf (" %s", &aluno1.nome);
    
    printf("Digite o numero de sua matricula:\n");
    scanf("%d",&aluno1.matricula);

    printf("Digite sua nota de avaiacao teorica:\n");
    scanf("%f",&aluno1.nota_AT);

    printf("Digite sua nota de trabalho de ordenacao:\n");
    scanf("%f",&aluno1.notar_TO);

    printf("Digite sua nota de exercicios praticos:\n");
    scanf("%f", &aluno1.nota_EP);

    printf("Aluno cadastrado!\n");
    printf("Suas informacoes: \nNome - %s \nMatricula - %i \nNota de AT - %.2f \nNota de TO - %.2f \nNota de EP - %.2f",
    aluno1.nome, aluno1.matricula, aluno1.nota_AT, aluno1.notar_TO, aluno1.nota_EP);

    return 0;
}

/*6 - Crie uma funcao que recebe os dados do aluno por terminal, salva esses dados 
em uma tad e aresenta no terminal o nome do aluno e se ele esta aprovado, 
reprovado ou de final na disciplina*/

#include<stdio.h>
#include<stdlib.h>
typedef struct dados_aluno{
    char nome[100];
    int matricula;
    float nota_atividade;
    float nota_prova;
    float nota_trabalho;
    float media;

}aluno;

void requerir_dados(aluno *aluno_req){

    printf("Digite seu nome:\n");
    scanf("%s", &aluno_req ->nome);
    
    printf("Digite sua matricula:\n");
    scanf("%d",&aluno_req ->matricula);

    printf("Digite sua nota de atividade:\n");
    scanf("%f",&aluno_req -> nota_atividade);

    printf("Digite sua nota da prova:\n");
    scanf("%f", &aluno_req -> nota_prova);

    printf("Digite sua nota de trabalho:\n");
    scanf("%f", &aluno_req ->nota_trabalho);
}

int main(){

    aluno aluno1;
    requerir_dados(&aluno1);

    aluno1.media = (aluno1.nota_atividade + aluno1.nota_prova + aluno1.nota_trabalho)/3;

    if (aluno1.media >= 7){
        printf("Parabens %s! voce esta aprovado \nSua media %.2f\n",aluno1.nome, aluno1.media);
    } 
    else if (aluno1.media >=4 && aluno1.media < 7){
        printf("Foi de AF amigo! Tatiane achou paia \nSua media %.2f", aluno1.media);
    }
    else if (aluno1.media < 4){
        printf("Se reprovar 3 vezes ja pode pedir musica no fantastico! \nSua media %.2f", aluno1.media);
    }

    return 0;
}






