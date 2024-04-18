#include <stdio.h>


typedef struct no
{
    int dado;
    struct no *proxNo, *antNo;
} tipoNo;

typedef struct listaGerenciada
{
    tipoNo *fim, *inicio;
    int quant;
} tipoLista;

void inicializa(tipoLista *listaEnc)
{
    listaEnc->fim = NULL;
    listaEnc->inicio = NULL;
    listaEnc->quant = 0;
}

int insereListaVazia(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo;
    novoNo = (tipoNo*) malloc(sizeof (novoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = NULL;
    novoNo->antNo = NULL;
    listaEnc->inicio = novoNo;
    listaEnc->fim = novoNo;
    listaEnc->quant++;
    return 1;
}

int insereNaFrente(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo;
    if(listaEnc->inicio==NULL)
        insereListaVazia(listaEnc, valor);
    else
    {
        novoNo = (tipoNo*)malloc(sizeof(tipoNo));
        if(novoNo==NULL)
            return 0;
        novoNo->dado=valor;
        novoNo->antNo = NULL;
        novoNo->proxNo=listaEnc->inicio;
        listaEnc->inicio->antNo = novoNo;
        listaEnc->inicio=novoNo;
        listaEnc->quant++;
        return 1;
    }
}

void exibeLista(tipoLista *listaEnc)
{
    tipoNo *atual;  /*Variável que será usada para percorrer a lista*/
    atual = listaEnc->inicio;
    printf("\nLista encadeada: ");
    while(atual !=NULL)
    {
        printf("%8d",atual->dado);
        atual = atual->proxNo;
    }
}

int insereNoFim(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo;
    if(listaEnc->inicio == NULL)
        insereListaVazia(listaEnc, valor);
    else
    {
        novoNo = (tipoNo*) malloc(sizeof(tipoNo));
        if(novoNo == NULL)
            return 0;
        novoNo->dado=valor;
        novoNo->proxNo=NULL;
        listaEnc->fim->proxNo = novoNo;
        novoNo->antNo = listaEnc->fim;
        listaEnc->fim = novoNo;
        listaEnc->quant++;
        return 1;
    }
}

int buscaDado(tipoLista *listaEnc, int procurado)
{
    tipoNo *atual;
    int cont = 1;
    atual = listaEnc->inicio;
    while(atual != NULL)
    {
        if(atual->dado == procurado)
            return cont;
        atual = atual->proxNo;
        cont++;
    }
    return 0;
}


int insereOrdenado(tipoLista *listaEnc, int valor)
{
    tipoNo *novoNo, *atual; /*Variavel que guarda o endereço do nó anterior a posição de inserção*/
    if(valor < listaEnc->inicio->dado)/*Testa se o dado a ser inserido é menor que o primeiro da lista*/
        return insereNaFrente(listaEnc,valor);
    else
    {
        novoNo = (tipoNo*) malloc(sizeof(tipoNo));
        if(novoNo == NULL)
            return 0;
        novoNo->dado = valor;
        atual = listaEnc->inicio;
        while(atual->dado < valor && atual->proxNo != NULL)
        {
            atual = atual->proxNo;
        }
        if(atual->dado > novoNo->dado)
        {
            novoNo->proxNo = atual;
            novoNo->antNo = atual->antNo;
            novoNo->antNo->proxNo = novoNo;
            atual->antNo=novoNo;
            listaEnc->quant++;
        }
        else
            insereNoFim(listaEnc,valor);
    }
    return 1;
}
void inserePos(tipoLista *listaEnc, int posicao, int valor){
    tipoNo *novoNo, *atual;
    if(posicao <= 0 || posicao > listaEnc->quant){
        printf("Posição inválida\n");
        return;
    }
    novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    novoNo->dado = valor;

    if(posicao == 1){
        novoNo->proxNo = listaEnc->inicio;
        listaEnc->inicio->antNo = novoNo;
        listaEnc->inicio = novoNo;
    }else if(posicao == listaEnc->quant){
        listaEnc->fim = novoNo;
    }else{
        atual = listaEnc->inicio;
        for(int i=1; i<posicao-1; i++)
            atual = atual->proxNo;
        novoNo->proxNo = atual->proxNo;
        atual->proxNo->antNo = novoNo;
        atual->proxNo = novoNo;
        novoNo->antNo = atual;
    }
    listaEnc->quant++;
}


void main()
{
    tipoLista lista;
    int aux, aux2, aux3, op, pos;
    inicializa(&lista);
    do
    {
        printf("\nMenu");
        printf("\n1 - Insere na lista vazia");
        printf("\n2 - Insere na frente da lista");
        printf("\n3 - Exibe lista");
        printf("\n4 - Insere no fim");
        printf("\n5 - Insere ordenado");
        printf("\n6 - Insere na posicao desejada");
        printf("\n0 - Encerrar programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereListaVazia(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 2:
            printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereNaFrente(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 3:
            exibeLista(&lista);
            break;
        case 4:
            printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereNoFim(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 5:
            printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            if(insereOrdenado(&lista,aux))
                printf("\nDado inserido com sucesso");
            else
                printf("\nInsercao nao efetuada");
            break;
        case 6:
            printf("\nDigite um numero inteiro:");
            scanf("%d",&aux);
            printf("\nDigite a posicao de deseja inserir: ");
            scanf("%d",&pos);
            inserePos(&lista,pos,aux);
            break;
        case 0:
            printf("\nEncerrando programa...");
            break;
        default:
            printf("\nOpcao invalida. Escolha outra opcao.");
            break;
        }
    }
    while(op != 0);
}
