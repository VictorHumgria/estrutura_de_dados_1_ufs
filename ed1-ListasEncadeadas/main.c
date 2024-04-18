
typedef struct no{
int dado;
struct no *proxNo;
struct no *antNo;
}tipoNo;

typedef struct listaGerenciada{
tipoNo *fim;
int quant;
}tipoLista;

void inicializa(tipoLista *listaEnc){
    listaEnc->fim = NULL;
    listaEnc->quant = 0;
    }

/*Função que retorna 1 caso a lista esteja vazia e 0 caso esteja povoada*/
int estaVazia(tipoLista *listaEnc){
    if (listaEnc->fim == NULL)
        return 1;
    elsew
        return 0;
}

void insereListaVazia(tipoLista *listaEnc, int valor){
tipoNo *novoNo; /*Declaração do ponteiro para o nó a ser criado*/
novoNo = (tipoNo*) malloc(sizeof (novoNo));
if(novoNo == NULL) /*Caso a memória não tenha sido alocada*/
    return 0;
novoNo->dado = valor; /*Coloca o dado dentro do nó criado*/
novoNo->proxNo = novoNo; /*Faz o próximo do nó criado ser ele próprio*/
listaEnc->fim = novoNo;
listaEnc->quant++;
}

void exibeLista(tipoLista *listaEnc){
   tipoNo *atual;
   atual = listaEnc->fim->proxNo;
   printf("\n\nLista armazenada:");
   printf("%8d",atual->dado);
   while(atual != listaEnc->fim){
      atual = atual->proxNo;
      printf("%8d",atual->dado);
   }
}

int insereNaFrente(tipoLista *listaEnc, int valor){
tipoNo *novoNo;
if(listaEnc->fim == NULL)
    insereListaVazia(listaEnc, valor);
else{
    novoNo = (tipoNo*) malloc(sizeof (novoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = listaEnc->fim->proxNo;
    listaEnc->fim->proxNo = novoNo;
    listaEnc->quant++;
    }
return 1;
}

int insereNoFim(tipoLista *listaEnc, int valor){
tipoNo *novoNo;
if(listaEnc->fim == NULL)
    insereListaVazia(listaEnc, valor);
else{
    novoNo = (tipoNo*) malloc(sizeof (novoNo));
    if(novoNo == NULL)
        return 0;
    novoNo->dado = valor;
    novoNo->proxNo = listaEnc->fim->proxNo;
    listaEnc->fim->proxNo = novoNo;
    listaEnc->fim = novoNo;
    listaEnc->quant++;
    }
}

void removeDoInicio(tipoLista *listaEnc){
    tipoNo *atual;
    if(listaEnc->quant > 1){
    atual = listaEnc->fim->proxNo;
    listaEnc->fim->proxNo = atual->proxNo;
    }
    else
        listaEnc->fim = NULL;
    listaEnc->quant--;
    free(atual);
}


void main(){
tipoLista lista;
int op, aux, aux2;
inicializa(&lista);
do{
    printf("\nMenu\n\n1 - Insere elemento em lista vazia:");
    printf("\n2 - Insere elemento na frente da lista");
    printf("\n3 - Remove do inicio");
    printf("\n4 - Insere elemento no fim da lista");
    printf("\n9 - Exibe lista");
    printf("\n0 - Encerra programa");
    printf("\nEscolha sua opcao: ");
    scanf("%d",&op);
    switch(op){
    case 1: printf("\nDigite o elemento que deseja inserir: ");
        scanf("%d",&aux);
        insereListaVazia(&lista, aux);
        break;
    case 2: printf("\nDigite o elemento que deseja inserir: ");
        scanf("%d",&aux);
        insereNaFrente(&lista, aux);
        break;
    case 3: removeDoInicio(&lista);
        break;
    case 4: printf("\nDigite o elemento que deseja inserir: ");
        scanf("%d",&aux);
        insereNoFim(&lista, aux);
        break;
    case 9: exibeLista(&lista);
        break;
    case 0: printf("\nEncerrando programa.");
        break;
    }
}while(op != 0);
}
