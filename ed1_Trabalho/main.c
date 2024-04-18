#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Trabalho de estrutura de dados 1, Arvore genealogica usando Arvore binaria de busca.
*/

int flag;

typedef struct
{
    char name[50], sexo, locNas[50], pai[50];
    int anoNasc, anoOb;
} Pessoa;

typedef struct no
{
    Pessoa pessoa;
    struct no *fillhoEsq, *filhoDir;
} NoArv;

Pessoa criarPessoa()
{
    Pessoa p;
    fflush(stdin);
    printf("\nDigite o nome da pessoa: ");
    fgets(p.name, 49, stdin);
    p.name[strcspn(p.name, "\n")] = '\0';
    printf("\nDigite o local de nascimento: ");
    fgets(p.locNas, 49, stdin);
    p.locNas[strcspn(p.locNas, "\n")] = '\0';
    printf("\nDigite o sexo (f/m): ");
    scanf(" %c",&p.sexo);
    printf("\nDigite o ano do nascimento: ");
    scanf("%d",&p.anoNasc);
    fflush(stdin);
    printf("\nDigite o ano de obito: ");
    scanf("%d",&p.anoOb);
    fflush(stdin);
    printf("\nDigite o nome do pai: ");
    fgets(p.pai, 49, stdin);
    p.pai[strspn(p.pai, "\n")] = '\0';
    return p;
}

void imprimirPessoa(Pessoa p)
{
    printf("\n------------Dados------------\n");
    printf("\nNome: %s;",p.name);
    printf("\nSexo: %c",p.sexo);
    printf("\nAno de nascimento: %i",p.anoNasc);
    printf("\nAno de obito: %i",p.anoOb);
    printf("\nLocal de nascimento: %s",p.locNas);
    printf("\n-----------------------------\n");
}


NoArv* buscaPessoa(NoArv* raiz, Pessoa pBusca)
{
    int res = strcmp(raiz->pessoa.name, pBusca.name);
    int resP = strcmp(raiz->pessoa.pai, pBusca.pai);
    if(raiz)
    {
        if(res == 0 && raiz->pessoa.anoNasc == pBusca.anoNasc && resP == 0)
            return raiz;
        else if(pBusca.anoNasc < raiz->pessoa.anoNasc)
            return buscaPessoa(raiz->fillhoEsq,pBusca);
        else
            return buscaPessoa(raiz->filhoDir,pBusca);
    }
    return NULL;
}


NoArv* inserirPessoa(NoArv *raiz, Pessoa p)
{
    if(raiz == NULL)
    {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->pessoa = p;
        aux->filhoDir = NULL;
        aux->fillhoEsq = NULL;
        return aux;
    }
    else
    {
        if(p.anoNasc < raiz->pessoa.anoNasc)
            raiz->fillhoEsq = inserirPessoa(raiz->fillhoEsq, p);
        else
            raiz->filhoDir = inserirPessoa(raiz->filhoDir, p);
        return raiz;
    }
}

int altura(NoArv *raiz)
{
    if(raiz == NULL)
    {
        printf("\nArvore Nula!!");
        return 0;
    }
    else
    {
        int fEsq = altura(raiz->fillhoEsq);
        int fDir = altura(raiz->filhoDir);
        if(fEsq > fDir)
            return fEsq+1;
        else
            return fDir+1;
    }
}
int quantNos(NoArv *raiz)
{
    if(raiz == NULL)
        return 0;
    else
        return 1 + quantNos(raiz->fillhoEsq) + quantNos(raiz->filhoDir);
}
int quantFolha(NoArv *raiz)
{
    if(raiz ==NULL)
        return 0;
    else if(raiz->fillhoEsq == NULL && raiz->filhoDir == NULL)
        return 1;
    else
        return quantFolha(raiz->fillhoEsq) + quantFolha(raiz->filhoDir);
}

NoArv* remover(NoArv *raiz, char chave[],int anoNas)
{
    if(raiz == NULL)
    {
        printf("\nValor nao encontrado!\n");
        return NULL;
    }
    else     // procura o valor a ser removido.
    {
        int res = strcmp(raiz->pessoa.name,chave);
        if(res == 0)
        {
            //remove nos folhas.
            if(raiz->fillhoEsq == NULL && raiz->filhoDir == NULL)
            {
                free(raiz);
                printf("\nElemento folha removido: %s !\n", chave);
                return NULL;
            }
            else
            {
                //remove nós que possuem dois filhos
                if(raiz->fillhoEsq != NULL && raiz->filhoDir != NULL)
                {
                    Pessoa  p;
                    NoArv *aux = raiz->fillhoEsq;
                    while(aux->filhoDir != NULL) // vou percorrer o valor mais a direita do filho da esquerda
                        aux = aux->filhoDir;
                    p = raiz->pessoa;
                    raiz->pessoa = aux->pessoa;
                    aux->pessoa = p;
                    printf("\nElemento trocado: %s\n", chave);
                    raiz->fillhoEsq = remover(raiz->fillhoEsq, chave, anoNas);
                    return raiz;
                }
                else
                {
                    NoArv *aux;
                    if(raiz->fillhoEsq != NULL)
                        aux = raiz->fillhoEsq;
                    else
                        aux = raiz->filhoDir;
                    free(raiz);
                    printf("\nElemento com 1 filho removido: %s\n",chave);
                    return aux;
                }
            }
        }
        else
        {
            if(anoNas < raiz->pessoa.anoNasc)
                raiz->fillhoEsq = remover(raiz->fillhoEsq, chave, anoNas);
            else
                raiz->filhoDir = remover(raiz->filhoDir, chave, anoNas);
            return raiz;
        }
    }
}

void imprimirArvore(NoArv *raiz)
{
    if(raiz)
    {
        imprimirPessoa(raiz->pessoa);
        imprimirArvore(raiz->fillhoEsq);
        imprimirArvore(raiz->filhoDir);
    }
}
void fazerBackUp(Pessoa p)
{
    FILE *arq;
    arq = fopen("backup_arv", "a+b");
    if(arq == NULL)
    {
        printf("\nEROOR AO ABRIR O ARQUIVO!!!");
    }
    else
    {
        fwrite(&p, sizeof(Pessoa), 1, arq); //salva a struct em arquivo binario;
        if(ferror(arq))
        {
            printf("\nErro na gravação\n");
        }
        else
        {
            printf("\n*****Pessoa salva com sucesso.*****\n");
        }
        fclose(arq);
    }
}
void lerBackUp()
{
    FILE *arq;
    Pessoa p;
    arq = fopen("backup_arv", "a+b");
    if(arq == NULL)
    {
        printf("\n*****Nao foi possivel abrir o arquivo.*****");
    }
    else
    {
        printf("\n\t-----backUp-----\n");
        while(!feof(arq))
        {
            int ctrl = fread(&p, sizeof(Pessoa), 1, arq);
            if(ferror(arq))
            {
                printf("\n*****Nao foi possivel ler o arquivo*****");
            }
            else
            {
                if(ctrl != 0)
                    imprimirPessoa(p); // retorna a struct pessoa
            }
        }
        printf("\n-----Fim do arquivo-----\n");
    }
    if(fclose(arq))
    {

        printf("\n*****Error ao fechar o arquivo*****\n");
    }
}




int main()
{
    NoArv *arvore = NULL;
    int opcao;

    while (1)
    {
        printf("\n*** ARVORE DE PESQUISA ***\n");
        printf("1. Inicicializa arvore.\n");
        printf("2. Inserir pessoa.\n");
        printf("3. Buscar pessoa.\n");
        printf("4. Remover pessoa.\n");
        printf("5. Imprimir arvore.\n");
        printf("6. Para exibir pessoas salvas.\n");
        printf("0. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            system("cls");
            Pessoa p = criarPessoa();
            arvore = inserirPessoa(arvore, p);
            fazerBackUp(p);
            break;
        }case 2:
        {
            system("cls");
            Pessoa p = criarPessoa();
            NoArv *resultado = buscaPessoa(arvore,p);
            if (resultado != NULL)
            {
                printf("\nPessoa ja registrada.");
            }
            else
            {
                inserirPessoa(arvore,p);
                fazerBackUp(p);
            }
            break;
        }

        case 3:
        {
            system("cls");
            Pessoa pBusca = criarPessoa();
            NoArv *resultado = buscaPessoa(arvore,pBusca);
            if (resultado != NULL)
            {
                imprimirPessoa(resultado->pessoa);
            }
            else
            {
                printf("\nPessoa nao encontrada!\n");
            }
            break;
        }
        case 4:
        {
            system("cls");
            char chave[30]; // Agora a declaração da variável chave está dentro do escopo do bloco
            int anosNas;
            printf("Digite o nome da pessoa a remover: ");
            fflush(stdin);
            fgets(chave, 29, stdin);
            chave[strcspn(chave, "\n")] = '\0';
            printf("\nDigite o ano de nascimento: ");
            scanf(" %d",&anosNas);
            arvore = remover(arvore, chave, anosNas);
            break;
        }
        case 5:
        {
            system("cls");
            imprimirArvore(arvore);
            break;
        }
        case 6:
        {
            system("cls");
            lerBackUp();
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }

        default:
            printf("Opcao invalida!\n");
            break;
        }
    }


    return 0;
}
