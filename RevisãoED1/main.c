#include <stdio.h>
#include <stdlib.h>

void bolhaSelecao(int *vetor, int tamanho)  // Primeiro método de ordenação o mais 'fácil';
{
    int x,y,aux;                            // Declaração das variaveis que vamos usar ao longo do codigo;
    for(x=0; x<tamanho-1; x++)              // for inicial que ira percorrer o vetor até o penultimo elemento;
    {
        // Abertura do for;
        for(y=x+1; y<tamanho; y++)          // For  interno para verificar o o atual indice do vetor;
        {
            if(vetor[x] > vetor[y])         // if Verifica se o indice atual do primeiro for e maior que o proximo elemento;
            {
                aux = vetor[x];             // se sim guarda o vetor autal na variavel aux;
                vetor[x] = vetor[y];        // ai o vetor[x] recebe o valor do proximo percorrido no for@2
                vetor[y] = aux;             // e o vetor[y] posição a frente recebe o valor do atual guardado em x;
            }
        }
    }
}

void bublleSor(int *vetor, int tamanho)              // Segundo método apresentado no slide
{
    int fim, aux, troquei;                           // Declaração de variaveis que vamos usar na função
    fim = tamanho;                                   // fim recebe o tamanho do array
    do                                              // inicio do 'do'
    {
        troquei=0;                                  // Flag troquei inicia com 0;
        for(int i=0; i<fim-1; i++)                  // for para percorer até o penúltimo item do array;
        {
            if(vetor[i] > vetor[i+1])               //If verifica o atual com o proximo;
            {
                aux =  vetor[i];                    // aux recebe o valor atual
                vetor[i] = vetor[i+1];              // vetor na posicao atual recebe o da proxima posicao;
                vetor[i+1] = aux;                   // vetor proximo recebe o valor do atual guardado no aux
                troquei = 1;                        // flag recebe 1;
            }
            fim--;                                  // decrementando o fim que recebeu o valor do tamanho
        }
    }
    while(troquei && fim >1);                       // verificar o fim e a flag são maiores que 1
    //Bolha por troca;

}

void selecaoDireta(int *vetor, int tamanho)
{
    int iMenor, aux;                                // variaveis que vamos usar na função
    for(int i=0; i<tamanho-1; i++)                  // primeiro for que para percorrer o array
    {
        iMenor = i;                                 // iMenor recebe o valor de i;
        for(int k = i+1; k<tamanho; k++)            // Segundo for que vai começar na posicao i+1 ou seja no proximo
        {
            if(vetor[k] < vetor[iMenor])            // se o proximo for menor que o atual iMenor recebe o valor de K;
            {
                iMenor = k;
            }
            if(iMenor != i)                         // iMenor for diferente do indice do primeiro for realiza a troca
            {
                aux = vetor[iMenor];                // aux recebe o valor de proximo
                vetor[iMenor] = vetor[i];           // vetor proximo recebe o atual;
                vetor[i] = aux;                     // vetor atual recebe o valor do proximo

            }
        }
    }

}

void insercaoDireta(int *vetor, int tamanho)        // a função recebe um endereço do vetor
{
    int i, k,temp;                                  // declaramos 3 variaveis do tipo int que iremos usar ao longo do código
    for(i = 1; i<tamanho; i++)                      // iniciamos o for que ira percorrer o array iniciando na posicao 1
    {
        k=i;                                        // depois atribuimos o valor de i em k
        temp=vetor[i];                              // temp recebe vetor na posicao k;
        while((k<0) && (temp < vetor[k-1]))         // então iniciamos um while que vai enquanto k for mais que 0 e temp for menor que o vetor k-1(uma posição antes do atual do for)
        {
            vetor[k] = vetor[k-1];                  // vetor na posicao atual recebe vetor na posicao anterior
            k--;                                    // decrementa k;
        }
        vetor[k] = temp;                            // vetor no indice k recebe temp;
    }
}

void qSort(int *vetor, int inicio, int fim)         // na declaração passamos o endereço do vetor, o inicio e o fim;
{
    int i, j, x, aux;                               // criarmos as variaveis do tipo int i,j,x,aux;
    i=inicio;                                       // i recebe o valor de inicio;
    j=fim;                                          // j recebe o valor do fim;
    x = vetor[i];                                   // x recebe o vetor na posisão i
    do                                              // inicio do do-while
    {
        while(vetor[i] < x && i < fim) i++;     // chamada que ire incrementar o valor de i(inicio)
        while(vetor[j] > x && j > incio) j--;   // chamada que ira decrementar o valor de j(fim)
        if(i<=j)                               // verificar se i é menor ou igual a j
        {
            aux = vetor[i];                     // aux recebe o valor do vetor na posicao i;
            vetor[i] = vetor[j];                // vetor na posicao i recebe o valor de j;
            vetor[j] = aux;                     // vetor na posicao j recebe aux que esta com o valor da posicao i
            i++;                                // incrementa i
            j--;                                // drecrementa j
        }
    }
    while(i<=j);                                    // verificar se i ainda é menor que j se for refaz todo o percuso;
    if(inicio<j)                                    // verifica se se j é menor que o inicio;
        qSort(vetor,inicio,j);                      // faz a chamada recursiva passando inicio e j;
    if(i<fim)                                       // verifica se i é menor que fim
        qSort(vetor, i, fim);                       // faz a chamada recursiva passando i e fim;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
