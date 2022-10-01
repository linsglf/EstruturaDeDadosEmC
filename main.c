#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void menu(void);

int main(){

    int opcao;
    int qtd_alunos = 0;

    AlocarMemoria();

    for (;;){

        printf("\n");
        menu();

        scanf("%d", &opcao);
        fflush(stdin);

        if(qtd_alunos >= 5){
            alunos = realloc (alunos, sizeof(aluno) * (qtd_alunos + 1));
        }

        if (opcao == 1){

            alunos[qtd_alunos] = Cadastrar();

            while (VerificacaoNotas(qtd_alunos) == 0){

                alunos[qtd_alunos] = Cadastrar();
            }

            qtd_alunos++;
        }

        if (opcao == 2){

            int erro = ExcluirAluno(qtd_alunos);

            if (erro == 0){
                printf("Aluno excluido com sucesso!\n");
                qtd_alunos--;
            }else{
                printf("Aluno nao encontrado!\n");
            }
        }

        if (opcao == 3){

            int erro = BuscarAluno(qtd_alunos);

            if (erro == 1){
                printf("Aluno nao encontrado!\n");
            }
        }
        
        if (opcao == 4){
            ImprimirRelatorio(qtd_alunos);
        }
        
        if (opcao == 5){
            liberarMemoria();
            printf("Voce saiu! ");
            break;
        }

        if (opcao < 1 || opcao > 5){
            printf("Opcao invalida! ");
        }
        
    }
    
    return 0;
}

void menu(){
    printf("1 - Incluir aluno\n2 - Excluir Aluno\n3 - Buscar Aluno\n4 - Relatorio de Notas\n5 - Sair\n");
    printf("\nDigite a opcao desejada: ");

    return;
}
