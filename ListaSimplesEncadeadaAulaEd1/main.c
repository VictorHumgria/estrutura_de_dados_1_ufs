#include <stdio.h>
#include <stdlib.h>

/*Implementação de Lista Simplesmente Encadeada - Estrutura de Dados I - 2021.2*/

/*Tipo de dado que representa um nó da lista encadeada*/
typedef struct no
{
    int dado;
    struct no *proxNo;
} tipoNo;

/*Tipo de dado que representa uma lista encadeada*/
typedef struct listaGerenciada
{
    tipoNo *inicio;
    tipoNo *fim;
    int quant;
} tipoLista;

/*Função de inicialização da lista encadeada - Deve ser chamada antes de usar a lista*/
void inicializa(tipoLista *lista)
{
    lista->fim = NULL;
    lista->inicio = NULL;
    lista->quant = 0;
}

/*Função para inserção de nó em lista vazia*/
int insereListaVazia(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = NULL;
    listaEnc->inicio = novoNo;
    listaEnc->fim = novoNo;
    listaEnc->quant++;
    return 1;
}

int insereNaFrente(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo;
    if(listaEnc->inicio == NULL)
        insereListaVazia(listaEnc,valor);
    else
    {
        novoNo = (tipoNo*)malloc(sizeof(tipoNo));
        if(novoNo==NULL)
            return 0;
        novoNo->dado = valor;
        novoNo->proxNo = listaEnc->inicio;
        listaEnc->inicio = novoNo;
        listaEnc->quant++;
        return 1;
    }
}

int removeNaFrente(tipoLista *listaEnc)
{
    tipoNo *novoNo;
    novoNo = listaEnc->inicio;
    if(listaEnc->inicio == NULL)
        return 0;
    else
    {
        while(novoNo != NULL)
        {
            listaEnc->inicio = novoNo->proxNo;
            free(novoNo);
            printf("\nRemovido\n");
            return 1;
        }
    }
    return 0;
}

void destruirLista(tipoLista *lista)
{
    while(lista->inicio != NULL)
    {
        removeNaFrente(&lista);
    }
    printf("Lista LImpa");
}

int pesquisaLista(tipoLista *lista, int key)

{

    int contador = 1, *aux;

    tipoNo *atual;

    atual = lista->inicio;

    if(lista->inicio == NULL)

        return 0;

    while(atual != NULL)

    {

        aux = atual->dado;

        if(aux == key)

        {

            printf("\nEncontrei o valor %d na posicao %d\n", key, contador);

            return contador;

        }


        printf("\nValor atual: %d\n", aux);

        contador++;

        atual = atual->proxNo;

    }

    return -1; // return -1 or any other value to indicate that the key was not found

}





/*Função de exibição da lista simplesmente encadeada*/
int exibeLista(tipoLista *listaEnc)
{
    tipoNo *atual;  //Variável que será usada para percorrer a lista*/
    if(listaEnc->inicio == NULL)
        return 0;
    atual = listaEnc->inicio;
    printf("\nLista encadeada: ");
    while(atual !=NULL)
    {
        printf("%8d",atual->dado);
        atual = atual->proxNo;
    }
    return 1;
}

int insereNoFim(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo;
    if(listaEnc->inicio == NULL)
        insereListaVazia(listaEnc,valor);
    novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = NULL;
    listaEnc->fim->proxNo = novoNo;
    listaEnc->fim = novoNo;
    listaEnc->quant++;
    return 1;
}

void main()
{
    tipoLista lista;
    int aux;
    inicializa(&lista);
    printf("\nDigite o elemento que deseja inserir:");
    scanf("%d",&aux);
    insereListaVazia(&lista,aux);
    if(!exibeLista(&lista))
        printf("\nLista vazia!");
    printf("\nDigite o elemento que deseja inserir:");
    scanf("%d",&aux);
    insereNaFrente(&lista,aux);
    exibeLista(&lista);
    printf("\nDigite o elemento que deseja inserir:");
    scanf("%d",&aux);
    insereNoFim(&lista,aux);
    exibeLista(&lista);
    printf("\nDigite o elemento que deseja inserir:");
    scanf("%d",&aux);
    insereNoFim(&lista,aux);
    exibeLista(&lista);
    printf("\nDigite o elemento que deseja inserir:");
    scanf("%d",&aux);
    insereNoFim(&lista,aux);
    exibeLista(&lista);
    printf("\nDigite o elemento que deseja inserir:");
    scanf("%d",&aux);
    insereNoFim(&lista,aux);
    exibeLista(&lista);
    int *num = pesquisaLista(&lista, 2);
    printf("\n%d",num);

}
