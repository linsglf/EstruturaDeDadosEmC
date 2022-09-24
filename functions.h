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

int VerificacaoNotas(int qtd_alunos){

    if(alunos[qtd_alunos].nota1 >= 0 && alunos[qtd_alunos].nota1 <= 10 && alunos[qtd_alunos].nota2 >= 0 && alunos[qtd_alunos].nota2 <= 10){
        printf("Aluno cadastrado com sucesso!\n");
        printf("| %s | %d | %d |\n", alunos[qtd_alunos].nome, alunos[qtd_alunos].nota1, alunos[qtd_alunos].nota2);

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
        printf("| %s | %d | %d |\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
    } 
    
    return;
}

