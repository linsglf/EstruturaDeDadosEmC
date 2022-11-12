/*contrua um sistema que gera aleatorimente um vetor com 100 numeros inteiros nao repetidos entre 1 e 1000
    ordenar usando bubble sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Arvore{
    int conteudo;
    struct Arvore *esquerda, *direita;
}Arvore;

typedef struct ArvB{
    Arvore *raiz;
}ArvB;


void inserirEsquerda(Arvore *arvore, int valor){
    if(arvore->esquerda == NULL){
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arvore->esquerda = novo;
    }else{
        if (valor < arvore->esquerda->conteudo){
            inserirEsquerda(arvore->esquerda, valor);
        }else{
            inserirDireita(arvore->esquerda, valor);
        }
    }
}

void inserirDireita(Arvore *arvore, int valor){
    if(arvore->direita == NULL){
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arvore->direita = novo;
    }else{
        if (valor > arvore->direita->conteudo){
            inserirEsquerda(arvore->direita, valor);
        }else{
            inserirDireita(arvore->direita, valor);
        }
    }
}

void inserirP(ArvB *arv, int valor){
    if(arv->raiz == NULL){

        

        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }else{

        if (valor < arv->raiz->conteudo){
            
            inserirEsquerda(arv->raiz, valor);
        }else{
            
            inserirDireita(arv->raiz, valor);
        }
    }
}

void imprimirPre(Arvore *raiz){
    if(raiz != NULL){
        
        printf("%d ", raiz->conteudo);
        imprimirPre(raiz->esquerda);
        imprimirPre(raiz->direita);
    }
}

void imprimirPos(Arvore *raiz){
    if(raiz != NULL){
        
        imprimirPos(raiz->esquerda);
        imprimirPos(raiz->direita);
        printf("%d ", raiz->conteudo);
    }
}

void imprimirEmOrdem(Arvore *raiz){
    if(raiz != NULL){
        
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimirEmOrdem(raiz->direita);
    }
}



int main()
{
    int i, j, aux, vetor[100], vetorBubble[100], vetorSelection[100], vetorInsertion[100];

    int contadorBubble = 0, contadorSelection = 0, contadorInsertion = 0;

    srand(time(NULL));

    // gerando vetor aleatorio 
    for(i=0; i<100; i++)
    {
        vetor[i] = rand() % 1000;
        for(j=0; j<i; j++)
        {
            if(vetor[i] == vetor[j])
            {
                i--;
                break;
            }
        }
    }

    // print vetor desordenado

    printf("Vetor desordenado: \n");

    for ( i = 0; i < 100; i++)
    {
        printf("|%d| \n", vetor[i]);
    }
    

    printf("\n");

    // copiando vetor para vetorBubble

    for(i=0; i<100; i++)
    {
        vetorBubble[i] = vetor[i];
    }

    //  bubble sort
    for(i=0; i<100; i++)
    {
        for(j=0; j<99; j++)
        {
            if(vetorBubble[j] > vetorBubble[j + 1])
            {   
                contadorBubble++;
                aux = vetorBubble[j];
                vetorBubble[j] = vetorBubble[j + 1];
                vetorBubble[j + 1] = aux;
            }
        }
    }


    // bubble sort print

    printf("\n");

    printf("bolhas\n");

    for(i=0; i<100; i++)
    {
        printf("%d \n", vetorBubble[i]);
    }

    printf("\n");

    printf("contador bubble: %d \n", contadorBubble);

   // copiando vetor para vetorSelection

    for(i=0; i<100; i++)
    {
        vetorSelection[i] = vetor[i];
    }
    
    // selection sort


    for (i=0; i < 100-1; i++)
    {
        for (j=i+1; j < 100; j++)
        {
            if (vetorSelection[i] > vetorSelection[j])
            {   
                contadorSelection++;
                aux = vetorSelection[i];
                vetorSelection[i] = vetorSelection[j];
                vetorSelection[j] = aux;
            }
        }
    }

    // selection sort print

    printf("\n");

    printf("selecao\n");
    for(i=0; i<100; i++)
    {
        printf("%d \n", vetorSelection[i]);
    }

    printf("\n");
    printf("contador selection: %d \n", contadorSelection);

    // copiando vetor para vetorInsertion

    for(i=0; i<100; i++)
    {
        vetorInsertion[i] = vetor[i];
    }

    // insertion sort

    for (i=0; i < 100 - 1; i++)
    {
        j = i + 1;
        while (j > 0 && vetorInsertion[j - 1] > vetorInsertion[j])
        { 
            contadorInsertion++;
            aux = vetorInsertion[j - 1];
            vetorInsertion[j - 1] = vetorInsertion[j];
            vetorInsertion[j] = aux;
            j--;
        }
    }

    // insertion sort print

    printf("\n");

    printf("insercao\n");

    for(i=0; i<100; i++)
    {
        printf("%d \n", vetorInsertion[i]);
    }

    printf("\n");

    printf("contador insertion: %d \n", contadorInsertion);

    printf("\n");

    // arovre binaria

    printf("ARVORE BINARIA\n");
    printf("\n");

    ArvB arv;

    arv.raiz = NULL;

    // inserindo na arvore
    
    for(i=0; i<100; i++)
    {
        inserirP(&arv, vetor[i]);
    }
    

   // imprimindo em ordem

    printf("imprimindo em ordem\n");

    imprimirEmOrdem(arv.raiz);

    printf("\n");

    // imprimindo pre ordem

    printf("imprimindo pre ordem\n");

    imprimirPre(arv.raiz);

    printf("\n");

    // imprimindo pos ordem

    printf("imprimindo pos ordem\n");

    imprimirPos(arv.raiz);


    return 0;
}






