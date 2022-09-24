#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    int nota1;
    int nota2;
} aluno;

aluno *alunos;

aluno Cadastrar(){
    aluno cadastro_aluno;

    printf("Digite o nome do aluno: ");
    gets(cadastro_aluno.nome);
    fflush(stdin);
    printf("Digite a nota 1: ");
    scanf("%d", &cadastro_aluno.nota1);
    fflush(stdin);
    printf("Digite a nota 2: ");
    scanf("%d", &cadastro_aluno.nota2);
    fflush(stdin);
    
    return cadastro_aluno;
}

void ImprimirRelatorio(int qtd_alunos){
    for (int i = 0; i < qtd_alunos; i++){
        printf("| %s | %d | %d |\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
    } 
    
    return;
}

