#include <stdio.h>
#include <stdlib.h>


/*
    função para localizar e remover valores de uma lista siplesmente encadeada:

    int removePos(TipoLista *listaEnc, int valor){
    tipoNo *atual, *aux;

    atual = listaEnc->inicio;

    if(atual->inicio == valor ){
        removeDoInicio(&listaEnc);
    }else if(atual->fim == valor){
        removeDoFim(&listaEnc);
    }else{
    while(atual->dado valor && atual->proxNo != NULL){
    if(atual->dado == valor){
    aux = atual->dado->antNo;
    aux->proxNo = atual->dado->proxNo;
    free(atual);
    listaEnc->quant--;
    return 1;
    }
    atual = atual->proxNo;

        }
            }
    return 0;
}
int removePos(TipoLista *listaEnc, int valor){
    tipoNo *atual, *aux;

    atual = listaEnc->inicio;

    if(atual->inicio == valor ){
        removeDoInicio(&listaEnc);
    }else if(atual->fim == valor){
        removeDoFim(&listaEnc);
    }else{



    if(atual->inicio == NULL) return 0;
    while(atual->dado valor && atual->proxNo != NULL)
    atual -> proxNo;
    if(atual->dado == valor){
        if(atual->antNo == NULL){
            listaEnc->inicio = atual->proxNo;
            listaEnc->inicio->antNo = NULL;
        }else{
        atual->anteNo->proxNo = atual->proxNo;
        if(atual->proxNo != NULL)
            atual->proxNo->antNo = atual->antNo;
        else
            listaEnc->fim = atual->antNo;
        }
    }
    free(atual);
    }
    return 0;
}
*/
int main()
{
    printf("Hello world!\n");
    return 0;
}
