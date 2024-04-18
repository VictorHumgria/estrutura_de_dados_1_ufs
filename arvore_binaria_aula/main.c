#include <stdio.h>
#include <stdlib.h>

// código para iniciar o estudo da implementação de árvore binária dinamicamente estruturada;

typedef struct node{
    int dado;
    struct node *pai;
    struct node *filhoEsq;
    struct node *filhoDir;
}tipoNode;

typedef struct{
    int encontrou; // se encontrou recebe 1, caso contrario recebe 0;
    tipoNode *noOuPai;
    char tipoFilho;
}tipoVolta;

tipoNode *achou; // serve para salvar algum no método de busca;

tipoVolta* criaVolta(tipoNode* no, char tf, int seAchou){
    tipoVolta* aux = (tipoVolta*) malloc(sizeof(tipoVolta));
    aux->encontrou = seAchou;
    aux->noOuPai = no;
    aux->tipoFilho = tf;
    return aux;
}

/* Função para criar um nó*/

tipoNode* criaNo(int n, tipoNode *noPai){
    tipoNode *novo;
    novo = (tipoNode*) malloc(sizeof(tipoNode));
    novo->dado = n;
    novo->pai = noPai;
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;
    return novo;
}

void exibePosOrdem(tipoNode *atual){
    if(atual!=NULL){
        exibePosOrdem(atual->filhoEsq);
        exibePosOrdem(atual->filhoDir);
        printf("\n%d",atual->dado);
    }
}

void exibePreOrdem(tipoNode *atual){
    if(atual!=NULL){
        printf("\n%d",atual->dado);
        exibePosOrdem(atual->filhoEsq);
        exibePosOrdem(atual->filhoDir);
    }
}
void exibeInOrdem(tipoNode *atual){
    if(atual!=NULL){
        exibePosOrdem(atual->filhoEsq);
        printf("\n%d",atual->dado);
        exibePosOrdem(atual->filhoDir);
    }
}
void buscaNo(tipoNode *atual, int valor){
    if(atual!=NULL){
        if(atual->dado == valor){}
        achou = atual;
        return;
    }
    buscaNo(atual->filhoEsq, valor);
    buscaNo(atual->filhoDir, valor);
}

tipoNode* insereNo(tipoNode *pai, int valor, char tipoFilho){
    if(pai == NULL){
        return criaNo(valor,pai);
    }
    if(tipoFilho == 'e'){
        if(pai->filhoEsq != NULL){
            printf("\nImpossivel inserir. Ja tem filho esquerdo.");
            return NULL;
        }
        pai->filhoEsq = criaNo(valor, pai);
        return pai->filhoEsq;
    } else {
    if(pai->filhoDir != NULL){
        printf("\nImpossivel inserir. Ja tem fiho direito.");
        return NULL;
    }
    pai->filhoDir = criaNo(valor, pai);
    return pai->filhoDir;
    }
}

void excluirArvore(tipoNode *atual){
    if(atual != NULL){
        excluirArvore(atual->filhoEsq);
        excluirArvore(atual->filhoDir);
        free(atual);
    }
}

char getPosNo(tipoNode *atual){
    if(atual->pai->filhoEsq == atual)
        return 'e';
    else
        return 'd';
}

tipoNode* removeNo(tipoNode *no){
    if(no !=NULL){
        if(no->filhoEsq != NULL){
            if(no->filhoDir !=NULL){
                printf("\nNo tem 2 filhos. Remocao nao efetuada.");
                return NULL;
            }
            else{ //no tem filho da esqueda, mas nao temo da direita
                    if(no->pai==NULL){ // sei que o no é raiz
                        tipoNode *antigo = no;
                        no = no->filhoEsq;
                        no->pai = NULL;
                        free(antigo);
                        return (no);
                    }
                    char posicao = getPosNo(no);
                    if(posicao == 'e')
                        no->pai->filhoEsq = no->filhoEsq;
                    else
                        no->pai->filhoDir = no->filhoEsq;
                    no->filhoEsq->pai = no->pai;
                    tipoNode *aux = no;
                    no = no->filhoEsq;
                    free(aux);
                    return no;
            }
        }else{//nao tenho filho da esquerda
        if(no->pai == NULL){
            tipoNode *antigo = no;
            no = no->filhoDir;
            if(no!= NULL)
                no->pai = NULL;
            free(antigo);
            return no;
        }
        else{
            char posicao = getPosNo(no);
            if(posicao == 'e')
                no->pai->filhoEsq = no->filhoDir;
            else
                no->pai->filhoDir = no->filhoDir;
            if(no->filhoDir != NULL)
                no->filhoDir->pai = no->pai;
            tipoNode *aux = no;
            no = no->filhoDir;
            free(aux);
            return no;
            }

        }
    }
}

tipoVolta* busque(tipoNode* raiz, int valor){
if(raiz == NULL){
    tipoVolta* retorno = criaVolta(NULL, 'P', 0);
    return retorno;
}else {
    tipoNode* aux = raiz;
    while(valor != aux->dado){
        if(valor < aux->dado){
            if(aux->filhoEsq == NULL){ // vou inserir na esquerda
                tipoVolta* retorno = criaVolta(aux, 'e', 0);
                return retorno;
            }
            else
                aux = aux->filhoEsq;
            }else{ // o valor é maior
                if(aux->filhoDir == NULL){
                    tipoVolta* retorno = criaVolta(aux, 'd', 0);
                    return retorno;
                }
                else
                    aux = aux->filhoDir;
            }
    }
    tipoVolta* retorno = criaVolta(aux, 'p', 1);
    return retorno;
    }
}

tipoNode* insereABB(tipoNode* raiz, int valor){
    if(raiz == NULL){
        return insereNo(NULL, valor, 'p');
    }
    tipoVolta* resposta = busque(raiz, valor);
    if(resposta->encontrou){
        printf("\nInformacao ja existe na arvore.\n");
        return NULL;
    }
    return insereNo(resposta->noOuPai, valor, resposta->tipoFilho);
}

tipoNode* removeEmABB(tipoNode* raiz, int valor){
    tipoVolta* retorno = busque(raiz, valor);
    tipoNode* aux;
    if(retorno->encontrou){
        if(retorno->noOuPai->filhoEsq != NULL && retorno->noOuPai->filhoDir !=NULL){
            aux = retorno->noOuPai->filhoEsq;
            while(aux->filhoDir != NULL)
                aux = aux->filhoDir;
            retorno->noOuPai->dado = aux->dado;
            if(aux->pai  == retorno->noOuPai)
                retorno->noOuPai->filhoEsq = removeNo(aux);
            else
                aux->pai->filhoDir = removeNo(aux);
            return raiz;
        }
    }
    else
        return removeNo(retorno->noOuPai);

    printf("\nNo nao encontrado na arvore.");
    return NULL;
}
void main(){
tipoNode *raiz;
raiz = NULL;
int opcao, valor, valorPai;
char filhoEouD;
do{
printf("\nEscolha sua opcao: ");
printf("\n1 - Inserir no na arvore\n2 - Exibe arvore em pos-ordem");
printf("\n3 - Exibe arvore em in-ordem");
printf("\n4 - Insere em Arvore Binaria de Busca");
printf("\n5 - Remove em Arvore Binaria de Busca");
printf("\n0 - Sair do programa.");
printf("\nDigite sua opcao: ");
scanf("%d",&opcao);
switch(opcao){
case 1:printf("Digite o dado que quer incluir na arvore: ");
  scanf("%d",&valor);
  if(raiz == NULL){
    if(raiz = insereNo(NULL, valor,'r'))
       printf("\nRaiz inserida com sucesso");
    else
        printf("\nRaiz nao inserida");
  }
  else{
    printf("\nDigite o pai do no: ");
    scanf("%d",&valorPai);
    achou = NULL;
    buscaNo(raiz,valorPai);
    if(achou == NULL)
        printf("\nPai nao encontrado. Insercao nao feita");
    else{
        do{
        printf("\nDigite se o filho vai ser da esquerda <e> ou da direita <d>:");
        fflush(stdin);
        scanf("%c",&filhoEouD);
        }while(filhoEouD != 'e' && filhoEouD != 'd');
        if(insereNo(achou, valor, filhoEouD))
            printf("\nNo inserido com sucesso");
        else
            printf("\nNo nao inserido");
        }
  }
  break;
case 2:printf("\n\nDados da arvore em pos-ordem: \n");
      exibePosOrdem(raiz);
  break;
case 3:printf("\n\nDados da arvore em in-ordem:");
      exibeInOrdem(raiz);
      break;
case 4: printf("\nDigite o valor a inserir: ");
     scanf("%d",&valor);
     if(raiz == NULL)
        raiz = insereABB(raiz, valor);
     else{
     if(insereABB(raiz, valor))
        printf("\nNo inserido com sucesso");
     else
        printf("\nNo nao inserido");
     }
     break;
case 5: printf("\nDigite o dado que deseja remover: ");
   scanf("%d",&valor);
   int eraRaiz = 0;
   if(valor == raiz->dado)
      eraRaiz = 1;
   tipoNode* retornado = removeEmABB(raiz, valor);
   if(retornado || (!retornado && eraRaiz))
       printf("\n No removido com sucesso");
   else
      printf("\nNo nao removido");
   break;
case 0: printf("\nEncerrando programa");
     excluirArvore(raiz);
     break;
default: printf("\nOpcao invalida");
}
}while(opcao != 0);

}
