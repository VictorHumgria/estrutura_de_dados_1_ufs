#include <stdio.h>
#include <stdlib.h>

int quantElem = 0;
int maximo = 30;

/* Função que cria uma lista vazia com 30 elementos e retorna um ponteiro para a lista criada*/
int* criaLista(){
int *vetor;
vetor = malloc(maximo*sizeof(int));
if(!vetor){
    printf("\nOcorreu um erro! A memoria não foi alocada.");
    exit(1);
}
return vetor;
}

/*Função que exibe os elementos do vetor*/
void mostraVetor(int *vetor){
printf("\nConteudo do vetor:");
for(int x = 0; x<quantElem; x++)
    printf("%5d",vetor[x]);
}

/* Função que faz inserção não ordenada no vetor*/
int insereNaoOrd(int *vetor){
if(quantElem < maximo){
   printf("\nDigite um numero inteiro:");
   scanf("%d",&vetor[quantElem++]);
   return 1;
}
else
   return 0;
}

/*Função que faz pesquisa sequencial*/
int pesqSeq(int *vetor, int elemento){
for(int x = 0; x < quantElem; x++)
    if(elemento == vetor[x])
       return x;
return -1;
}

/*Função que faz a remoção de vetor não ordenado*/
int remocaoNaoOrd(int *vetor,int elemento){
int resp = pesqSeq(vetor, elemento);
if(resp != -1){
    vetor[resp] = vetor[quantElem - 1];
    quantElem--;
    return 1;
    }
return 0;
}

/*Função que faz a remoção ordenada de um elemento do vetor*/
int removeOrd(int *vetor, int elemento){
int resp = pesqSeq(vetor, elemento);
if(resp != -1){
    for(int x = resp; x < quantElem-1; x++)
        vetor[x] = vetor[x+1];
    quantElem--;
    return 1;
    }
    else
    return 0;
}

/*Função que faz a inserção ordenada no vetor*/
int insereOrd(int *vetor, int elemento){
int x = quantElem-1;
if(quantElem < maximo){
    while(elemento < vetor[x] && x>=0){
       vetor[x+1] = vetor[x];
       x--;
    };
    vetor[x+1] = elemento;
    quantElem++;
    return 1;
}
else
    return 0;
}



void main(){

int *lista, op, aux, resp;
lista = criaLista();

do{
        printf("\n\n\nEscolha uma opcao\n1 - Insercao nao ordenada ");
        printf("\n2 - Busca sequencial \n3 - Remocao nao ordenada \n4 - Insercao ordenada");
        printf("\n5 - Remove de forma ordenada");
        printf("\n9 - Exibir lista \n0 - Sair do programa");
        printf("\nDigite sua opcao: ");
        scanf("%d",&op);
        switch(op){
        case 1: if(!insereNaoOrd(lista))
                    printf("\nLista cheia. Insercao nao realizada.");
                else
                    printf("\Elemento inserido com sucesso");
                break;
        case 2: printf("\nDigite o elemento a ser buscado:");
            scanf("%d",&aux);
            resp = pesqSeq(lista,aux);
            if(resp == -1)
                printf("Dado nao encontrado na lista!");
            else
                printf("Dado encontrado no indice %d do vetor",resp);
                break;
        case 3: printf("\nDigite o elemento a ser removido:");
            scanf("%d",&aux);
                if(remocaoNaoOrd(lista,aux))
                    printf("\Elemento removido com sucesso");
                else
                    printf("\nElemento nao encontrado.");
                break;
        case 4: printf("\nDigite o elemento a ser inserido de forma ordenada:");
            scanf("%d",&aux);
            if(insereOrd(lista,aux))
               printf("\nElemento inserido com sucesso!");
            else
               printf("\nInsercao nao realizada!");
            break;
        case 5: printf("\nDigite o elemento a ser removido:");
            scanf("%d",&aux);
                if(removeOrd(lista,aux))
                    printf("\Elemento removido com sucesso");
                else
                    printf("\nElemento nao encontrado.");
                break;
        case 9: mostraVetor(lista);
                break;
        case 0: printf("\nEncerrando programa.");
        default: printf("\n\nOpcao indisponivel. Selecione uma nova opcao.");
        }
}while(op !=0);
free(lista); /*Libera memória alocada dinamicamente para a lista*/
}
