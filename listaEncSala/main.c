#include <stdio.h>

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

void removeDoInicio(tipoLista *listaEnc)
{
    tipoNo *aux;
    aux = listaEnc->inicio;
    if(aux == NULL)
    {
        printf("\n Remocao nao feita pois a lista estava vazia");
        return;
    }
    listaEnc->inicio = listaEnc->inicio->proxNo;
    if(listaEnc->inicio == NULL)
        listaEnc->fim =NULL;
    free(aux);
    listaEnc->quant--;
}

void destruirListaSimEnc(tipoLista *listaEnc)
{
    if(listaEnc == NULL)
        printf("Lista é nula");
    tipoNo atual = listaEnc->inicio;
    while(atual != NULL){
        tipoNo *next = atual->proxNo;
        free(atual->dado);
        free(atual);
        atual = next;
    }
}

int buscaPosDado(tipoLista *listaEnc, int procurado)
{
    tipoNo *atual;
    atual = listaEnc->inicio;
    int cont = 1, flag = 0;
    while(atual != NULL)
    {
        if(atual->dado == procurado)
            return cont;
        atual = atual->proxNo;
        cont++;
    }
    return 0;
}
int insercOrd(tipoLista *listaEnc, int posicao, int valor)
{
    if(!listaEnc)                                           // verificar se listaEnc nao e nula se for retorna zero;
        return 0;
    if(listaEnc->quant<posicao)                             // verifica se quant nao e menor que a a possica desejada se for retorna zero;
        return 0;
    int contador = 0;

    tipoNo *atual = listaEnc->inicio;                       // inicializa o atual de acordo com o endereco de memoria do inicio
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));      //cria um novoNo e ja aloca a memoria dele;

    if(novoNo == NULL)                                      // verificar se novoNo nao e nullo
        return 0;
    novoNo ->dado = valor;                                  // atribui o valor do novoNo;
    novoNo ->proxNo = NULL;                                 // atribui o endereco null;

    for(int i=1; i<posicao-1; i++)                          // percorrer o endereco ate a posicao desejada;
        atual = atual->proxNo;                              // atualiza a posicao de acordo com aincrementacao do for

    novoNo ->proxNo = atual->proxNo;                        // insere novoNo na posicao desejada fazendo ele apontar para o seguinte
    atual->proxNo = novoNo;                                 // este é o no anterior e faz ele apontar para o novo no;
    listaEnc->quant++;
    return 1;

}
int removeNoPosicaoOrd(tipoLista *listaEnc, int posicao)
{
    if(!listaEnc)                                           // verificar se listaEnc nao e nula se for retorna zero;
        return 0;
    if(posicao < 1 || posicao > listaEnc->quant)            // verifica se a posicao esta fora dos limites
        return 0;

    tipoNo *atual = listaEnc->inicio;
    tipoNo *anterior = NULL;

                                                            // Percorre a lista encadeada até a posição desejada
    for(int i=1; i<posicao; i++)
    {
        anterior = atual;
        atual = atual->proxNo;
    }

    if(anterior == NULL)
    {
        listaEnc->inicio = atual->proxNo;
    }
    else
    {
        anterior->proxNo = atual->proxNo;
    }

    free(atual);
    listaEnc->quant--;
    return 1;
}


void main()
{
    tipoLista lista;
    int aux, op;
    inicializa(&lista);
    do
    {
        printf("\n      Menu Lista Encadeada");
        printf("\n1 - Insere um elemento na lista vazia");
        printf("\n2 - Insere elemento no inicio da lista");
        printf("\n3 - Insere elemento no fim da lista");
        printf("\n4 - Remove do inicio da lista");
        printf("\n5 - Busca um dado na lista");
        printf("\n8 - Destruir lista");
        printf("\n9 - Exibe a lista");
        printf("\n10 - Insere em uma posicao");
        printf("\n11 - Remove em uma posicao");

        printf("\n0 - Encerra o programa");
        printf("\nDigite sua opção:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\nDigite o elemento que deseja inserir:");
            scanf("%d",&aux);
            insereListaVazia(&lista,aux);
            if(!exibeLista(&lista))
                printf("\nLista vazia!");
            break;
        case 2:
            printf("\nInserindo elemento na frente:");
            printf("\nDigite o elemento que deseja inserir:");
            scanf("%d",&aux);
            insereNaFrente(&lista,aux);
            break;
        case 3:
            printf("\nInserindo elemento no fim da lista");
            printf("\nDigite o elemento que deseja inserir:");
            scanf("%d",&aux);
            insereNoFim(&lista,aux);
            break;
        case 4:
            printf("\nRemovendo elemento do inicio:");
            removeDoInicio(&lista);
            break;
        case 5:
            printf("\nDigite o elemento que deseja buscar:");
            scanf("%d",&aux);
            int aux2 = buscaDado(&lista, aux);
            if( aux2 != 0)
                printf("\nDado encontrado na posicao %d",aux2);
            else
                printf("\nDado nao encontrado na lista!");
            break;
        case 8:
            printf("\nDestuindo lista...");
            destruirLista(&lista);
            break;
        case 9:
            if(!exibeLista(&lista))
                printf("\nLista vazia!!");
            break;
        case 10:
            printf("\nDigite o valor de que deseja inserir: ");
            scanf("%d",&aux);
            printf("\nDigite a posicao que deseja inserir: ");
            scanf("%d",&aux2);
            insercOrd(&lista,aux2, aux );
            break;
        case 11:
            printf("\nDigite a posicao que deseja remover: ");
            scanf("%d",&aux2);
            removeNoPosicaoOrd(&lista,aux2);
            break;
        case 0:
            destruirLista(&lista);
            printf("\nEncerrando programa");
        default:
            printf("\nOpcao invalida! Tente novamente!");
        }
    }
    while(op != 0);
}
