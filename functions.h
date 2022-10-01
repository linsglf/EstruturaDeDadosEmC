#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    float nota1;
    float nota2;
    float media;
    char situacao[12];
} aluno;

aluno *alunos;

void AlocarMemoria(){

    alunos = malloc (sizeof(aluno) * 5);
}

aluno Cadastrar(){
    aluno cadastro_aluno;

    printf("Digite o nome do aluno: ");
    gets(cadastro_aluno.nome);
    fflush(stdin);
    printf("Digite a nota 1: ");
    scanf("%f", &cadastro_aluno.nota1);
    fflush(stdin);
    printf("Digite a nota 2: ");
    scanf("%f", &cadastro_aluno.nota2);
    fflush(stdin);

    cadastro_aluno.media = (cadastro_aluno.nota1 + cadastro_aluno.nota2) / 2;

    if (cadastro_aluno.media >= 6){
         strcpy(cadastro_aluno.situacao, "Aprovado");
    }else if (cadastro_aluno.media < 6 && cadastro_aluno.media >= 4){
         strcpy(cadastro_aluno.situacao, "Recuperacao");
    }else{
         strcpy(cadastro_aluno.situacao, "Reprovado");
    }
    
    return cadastro_aluno;
}

int ExcluirAluno(int qtd_alunos){
    int i, j;
    char nome[30];

    printf("Digite o nome do aluno que deseja excluir: ");
    gets(nome);
    fflush(stdin);

    for (i = 0; i < qtd_alunos; i++){
        if (strncmp(nome, alunos[i].nome, strlen(nome)) == 0){

            for (j = i; j < qtd_alunos; j++){
                alunos[j] = alunos[j + 1];
            }

            return 0;
        }
    }

    return 1;
}

int BuscarAluno(int qtd_alunos){
    char nome[30];

    printf("Digite o nome do aluno que deseja buscar: ");
    gets(nome);
    fflush(stdin);

    for (int i = 0; i < qtd_alunos; i++){
        if (strncmp(nome, alunos[i].nome, strlen(nome)) == 0){
            printf("Aluno encontrado!\n");
            printf("| %s | %.2f | %.2f | %.2f | %s |\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].media, alunos[i].situacao);
        
            return 0;
        }
    }

    return 1;
}

int VerificacaoNotas(int qtd_alunos){

    if(alunos[qtd_alunos].nota1 >= 0 && alunos[qtd_alunos].nota1 <= 10 && alunos[qtd_alunos].nota2 >= 0 && alunos[qtd_alunos].nota2 <= 10){
        printf("Aluno cadastrado com sucesso!\n");
        printf("| %s | %.2f | %.2f |\n", alunos[qtd_alunos].nome, alunos[qtd_alunos].nota1, alunos[qtd_alunos].nota2);

        return 1;
    }else if (alunos[qtd_alunos].nota1 > 10 || alunos[qtd_alunos].nota1 < 0){
        printf("Nota 1 invalida!\n");
        printf("Tente Novamente!\n");

        return 0;
    }else if (alunos[qtd_alunos].nota2 > 10 || alunos[qtd_alunos].nota2 < 0){
        printf("Nota 2 invalida!\n");
        printf("Tente Novamente!\n");

        return 0;
    }
}

void ImprimirRelatorio(int qtd_alunos){
    for (int i = 0; i < qtd_alunos; i++){
        printf("| %s | %.2f | %.2f | %.2f | %s |\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].media, alunos[i].situacao);
    } 
    
    return;
}

void liberarMemoria(void){
    free(alunos);
}
