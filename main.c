#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void menu(void);

int main(){

    int opcao;
    int qtd_alunos = 0;

    alunos = malloc (sizeof(aluno) * 5);

    for (;;){

        printf("\n");
        menu();

        scanf("%d", &opcao);
        fflush(stdin);

        if(qtd_alunos >= 5){
            alunos = realloc (alunos, sizeof(aluno) * (qtd_alunos + 1));
        }

        if (opcao == 1){

            for (int i = 0; i < 1; i++){
                alunos[qtd_alunos] = Cadastrar();
            }

            printf("Aluno cadastrado com sucesso!\n");
            printf("| %s | %d | %d |\n", alunos[qtd_alunos].nome, alunos[qtd_alunos].nota1, alunos[qtd_alunos].nota2);

            qtd_alunos++;
            printf("Quantidade de alunos: %d\n", qtd_alunos);
        }

        if (opcao == 4){
            for (int i = 0; i < qtd_alunos; i++){
                printf("| %s | %d | %d |\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
            } 
        }
        
        if (opcao == 5){
            printf("Voce saiu! ");
            break;
        }
    }
    
    return 0;
}

void menu(){
    printf("1 - Incluir aluno\n2 - --EM BREVE--\n3 - --EM BREVE--\n4 - Relatorio de Notas\n5 - Sair\n");
    printf("\nDigite a opcao desejada:");

    return;
}


