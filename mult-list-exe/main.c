#include <stdio.h>
#include <stdlib.h>

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

typedef struct disciplina
{
    int codigo;
    char nome[50];
    tipoLista turmas;
} tipoDisciplina;

typedef struct listaDisciplina
{
    tipoDisciplina *disciplina;
    struct listaDisciplina *proxDisc;
} tipoListDisciplina;

void inicializa(tipoLista *listaEnc)
{
    listaEnc->fim = NULL;
    listaEnc->inicio = NULL;
    listaEnc->quant = 0;
}

void inicializaDisciplina(tipoDisciplina *disciplina)
{
    inicializa(&disciplina->turmas);
}

tipoDisciplina* cadastraDisciplina()
{
    tipoDisciplina* novaDisciplina = (tipoDisciplina*) malloc(sizeof(tipoDisciplina));
    printf("Digite o codigo da disciplina: ");
    scanf("%d", &novaDisciplina->codigo);
    printf("Digite o nome da disciplina: ");
    scanf(" %49[^\n]", novaDisciplina->nome);
    inicializaDisciplina(novaDisciplina);
    return novaDisciplina;
}

void insereDisciplinaNoInicio(tipoListDisciplina** listaDisciplinas, tipoDisciplina* novaDisciplina)
{
    tipoListDisciplina* novoNo = (tipoListDisciplina*) malloc(sizeof(tipoListDisciplina));
    novoNo->disciplina = novaDisciplina;
    novoNo->proxDisc = *listaDisciplinas;
    *listaDisciplinas = novoNo;
}

void imprimeDisciplinas(tipoListDisciplina *listaDisciplinas)
{
    tipoListDisciplina *atual = listaDisciplinas;
    while (atual != NULL)
    {
        printf("\nCodigo: %d, Nome: %s", atual->disciplina->codigo, atual->disciplina->nome);
        if (atual->proxDisc == NULL)
        {
            break;
        }
        atual = atual->proxDisc;
    }
}

int main()
{
    tipoListDisciplina *listaDisciplinas = NULL;
    tipoDisciplina* novaDisciplina = NULL;
    int op;
    do
    {
        printf("\nMenu");
        printf("\n1 - Insere na lista vazia");
        printf("\n2 - Insere na frente da lista");
        printf("\n3 - Exibe lista");
        printf("\n0 - Encerrar programa");
        printf("\nDigite sua opcao:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            break;
        case 2:
            novaDisciplina = cadastraDisciplina();
            insereDisciplinaNoInicio(&listaDisciplinas, novaDisciplina);
            break;
        case 3:
            imprimeDisciplinas(listaDisciplinas);
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

    return 0;
}
