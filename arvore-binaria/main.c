#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int dado;
    struct node *filhoEsq;
    struct node *filhoDir;
} tipoNode;

tipoNode *criarNo(int value)
{
    tipoNode *novo = malloc(sizeof(tipoNode));
    if(novo)
    {
        novo->dado = value;
        novo->filhoDir = NULL;
        novo->filhoEsq = NULL;
    }
    else
    {

        return NULL;
    }
    return novo;

}

void imprimeNo(tipoNode *no)
{
    if(no==NULL)
    {
        return;
    }

    imprimeNo(no->filhoEsq);
    printf("%d",no->dado);
    imprimeNo(no->filhoDir);
}

bool findNumber(tipoNode *arvore, int value)
{
    if(arvore == NULL) return false;
    if(arvore->dado == value)
    {
        return true;
    }
    if(value < arvore->dado)
    {
        return findNumber(arvore->filhoEsq, value);
    }else{
        return findNumber(arvore->filhoDir, value);
    }
}
bool inserirNumero(tipoNode **rootptr, int value){
    tipoNode *root = *rootptr;
    if(root == NULL){
        (*rootptr) = criarNo(value);
        return true;
    }
    if(value == root->dado){
        return false;
    }
    if(value < root->dado){
        return inserirNumero(&(root->filhoEsq), value);
    }else{
        return inserirNumero(&(root->filhoDir), value);
    }
}

int main()
{
        tipoNode *root = NULL;

        inserirNumero(&root, 1);
        inserirNumero(&root, 2);
        inserirNumero(&root, 3);
        inserirNumero(&root, 4);
        inserirNumero(&root, 5);
        inserirNumero(&root, 6);
        inserirNumero(&root, 8);
        inserirNumero(&root, 9);

        imprimeNo(root);

        printf("\n%d (%d)", 15, findNumber(root, 15));
        printf("\n%d (%d)", 5, findNumber(root, 5));
        printf("\n%d (%d)", 9, findNumber(root, 9));
        printf("\n%d (%d)", 3, findNumber(root, 3));
        printf("\n%d (%d)", 11, findNumber(root, 11));
        return 0;
}
