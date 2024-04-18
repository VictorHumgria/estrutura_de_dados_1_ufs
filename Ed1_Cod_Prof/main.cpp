#include <iostream>

using namespace std;
/*
-------------------Bolha por sele��o---------------------
-> Algoritmo n�o recursivo baseado em sele��o de elementos;
-> N�o � t�o eficiente, mas � considerado o mais f�cil de todos;
-> Consiste em fixar uma posi��o e percorrer o restante do conjunto,
cada vez que for encontrado uma elemento menor que o fixado este � trocado pelo elemento fixado.
-> Fixa o pr�ximo elemento do conjunto.
-> Desta forma ao fixarmos o pen�ltimo elemento do conjunto o mesmo estar� ordenado.
*/

void bolhaSelecao(int *vetor,int tamanho){
    int x,y,aux;
    for(x=0; x<tamanho-1; x++){
        for(y=x+1; y<tamanho; y++){
            if(vetor[x] > vetor[y]){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
                cout << "Troca realizada: "     << endl;
                cout <<  "aux = vetor[x]"       << vetor[x] <<
                         "vetor[x] = vetor[y];" << vetor[y] <<
                         "vetor[y] = aux;"      << aux      << endl;
            }
        }
    }
}

/*
----------------Bubble Sort ---------------------------------
-> Algoritmo n�o recursivo, baseado em trocas e elementos, que consiste do seguinte:
-> -Para l variando de 1 at� N-1, compara-se Al com Al+1, trocando-se os dois valores se Al>Al+1.
Ap�s esse passo o maior valor ficar� na �ltima posi��o.
-> Percorre-se novamente o array para l variando de 1 at� N-2, comparando-se os elementos adjacentes,
efetuando a troa se houver necessidade. Ap�s esse passo o segundo maior valor ficar� na pn�ltima posi��o.
-> Continua-se at� que n�o haja nenhuma troca ou se chegar a situa��o de se comparar A1 com A2.
*/

void bubbleSor(int *vetor, int tamanho){
    int fim, aux, troquei;
    fim = tamanho;
    do{
        troquei = 0;
        for(int i=0; i<fim-1; i++)
        if(vetor[i] > vetor[i+1]){
            aux = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = aux;
            troquei = 1;
            cout << "if(vetor[i] > vetor[i+1]): verdadeiro" << endl;
            cout << "aux = veotr[i];"                       << endl;
            cout << "vetor[i] = vetor[i+1];"                << endl;
            cout << "vetor[i+1] = aux;"                     << endl;
            cout << "troquei = 1;"                          << endl;
        }
        fim--;
        cout << "fim-- : " << endl;
    }while(troquei && fim > 1);
}

/*
-------------Sele��o Direta-----------------------------------
Esse m�todo consiste do seguinte:
-> Procura-se o menor valor entre os elementos A1, A2, ... AN e coloca-se em A1;
-> Procura-se o menor valor entre os elementos A2, A3, ... AN e coloca-se em A2;
-> COntinua-se com o processo at� chegar a condi��o de procurarmos o menor valor entre o AN-1.
Neste caso colocamos o menor em AN-1 e o maior em AN e terminamos o processo.
*/

void selecaoDireta(int *vetor, int tamanho){
    int iMenor, aux;
    for(int i=0; i<tamanho-1; i++){
        iMenor = i;
        cout << "iMenor = i " << endl;
        for(int k = i+1; k<tamanho; k++)
            if(vetor[k] < vetor[iMenor]){
                iMenor = k;
                cout <<"if(vetor[k] < vetor[iMenor]): verdadeiro" << endl;

            }

            if(iMenor != i){
                aux = vetor[iMenor];
                vetor[iMenor] = vetor[i];
                vetor[i] = aux;
                cout << "if(iMenor != i): verdadeiro" << endl;
                cout << "aux = vetor[iMenor];"        << endl;
                cout << "vetor[iMenor] = veotr[i];"   << endl;
                cout << "vetor[i] = aux;"             << endl;
            }
    }
}
/*
------------Inser��o Direta------------------------------------
->Para implementar esse algoritmo, a primeira id�ia que nos vem � mente
� usar dois arrays. Mas, se for o observado atentametne, notamos que a lista
da esquerda cresce exatamente na mesma velocidade com que a da direita diminui.
Assim n�s s� precisamos de um array, ficando uma lista a esquerda do array e a outra �
direita. A figura abaixo mostra a mesma figura anterior por�m usando somente um array.
*/

void insercaoDireta(int *vetor, int tamanho){
    int i, k, temp;
    for(i=1; i<tamanho; i++){
        k=i;
        temp=vetor[i];
        while((k>0) && (temp < vetor[k-1])){
            vetor[k] = vetor[k-1];
            k--;
            cout << "while((k>0) && (temp < vetor[k-1])): verdadeiro " << endl;
            cout << "vetor[k] = vetor[k-1]; "  << endl;
            cout << "k--; " << endl;
        }
        vetor[k] = temp;
        cout << "vetor[k] = temp "<< endl;
    }
}

/*
--------------QuickSort------------------------------------------
-> M�todo recursiivo usa a t�cnica de dividir e conquistar, ou seja ele resolve um
problema dividindo-o em dois ou mais subproblemas e depois combinando a solu��o
dos problemas menores para obter a solu��o do problema original.
-> Em sua execu��o o QuickSort realiza os seguintes passos:
-->Escolhe um elemento do conjunto para piv�. Pode-se ser escolhido qualquer elemento.
-->Particione os elementos restantes em duas sequ�ncias L e G, tais que todo elemento
 em L seja menor ou igal ao piv� e todo elemento em G seja maior que o piv�. No caso
 geral tanto L quanto G n�o est�o ordenados.
 --> Realize o QuickSorte recursivamento para as sequ�ncias L e G n�o ordenadas.
 --> Um conjunto de um �nico elemento � considerado ordenado.
*/

void qSort(int *vetor, int inicio, int fim){
    int i,j,x,aux,contador;
    i = inicio;
    j = fim;
    x = vetor[i];
    contador = 0;
    do{
        if(i==inicio && j==fim){
            cout << "Entrada doWhile" << endl;
            cout << "Inicio: " << inicio << endl;
            cout << "Fim: " << fim << endl;
            cout << "i: " << i << endl;
            cout << "j: " << j << endl;
            cout << "x: " << x << endl;
            cout << "\n-----------------------------------------------------\n" << endl;
        }

        while(vetor[i] < x && i < fim){
          i++;
          cout << "while(vetor[i] < x && i < fim): verdadeiro. i++" << endl;

        }
        while(vetor[j] > x && j > inicio){
          j--;
         cout << "while(vetor[j] > x && j > inicio): verdadeiro. j--" << endl;
        }
        if(i<=j){
            cout << "if(i<=j): verdadeiro." << endl;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }while(i<=j);
    if(inicio < j ){
        cout << "if(inicio < j: verdadeiro -- Chamada recursiva." << endl;
        qSort(vetor, inicio, j);
    }
    if(i < fim){
        cout << "if(i < fim): verdadeiro -- chamada recursiva." << endl;
        qSort(vetor, i, fim);
    }
}
void imprimirVetor(int *vetor, int tamanho){
    char key;
    cout << "Deseja imprimir o vetor? s/n: " << endl;
    cin >> key;
    if(key == 's' || key == 'S'){
        for(int i=0; i<tamanho; i++){
        cout <<"Vetor["<< i << "]: " << vetor[i] << endl;
        }
    }

}

void menu(int *vetor,int *vetorBackUp, int tamanho){
    int op;
    do{
        cout << "\n-----------------------------------------------------\n" << endl;
        cout << "*********************************************************" << endl;
        cout << "Digite o tipo de ordenacao que deseja: " << endl;
        cout << "1 -> QuickSort;" << endl;
        cout << "2 -> Insercao direta;" << endl;
        cout << "3 -> Selecao direta;" << endl;
        cout << "4 -> Bubble Sort" << endl;
        cout << "5 -> Bolha de selecao;" << endl;
        cout << "6 -> Imprimir vetor organizado;" << endl;
        cout << "7 -> Imprimir vetor Original;" << endl;
        cout << "8 -> Imprimir ambos os vetores;" << endl;

        cout << "0 -> Para sair ;" << endl;
        cin >> op;

        switch(op){
        case 1:
            qSort(vetor, 0, tamanho);
            break;
        case 2:
            insercaoDireta(vetor,tamanho);
            break;
        case 3:
            selecaoDireta(vetor,tamanho);
            break;
        case 4:
            bubbleSor(vetor, tamanho);
            break;
        case 5:
            bolhaSelecao(vetor, tamanho);
            break;
        case 6:
            imprimirVetor(vetor, tamanho);
            break;
        case 7:
            imprimirVetor(vetorBackUp, tamanho);
            break;
        case 8:
            cout << "------------------Vetor Original------------------"<< endl;
            imprimirVetor(vetorBackUp, tamanho);
            cout << "------------------Vetor Modificado------------------"<< endl;
            imprimirVetor(vetor, tamanho);
            break;
        default:
            cout << "Digite um numero valido ou precione 0 para sair.." << endl;

        }

    }while(op != 0);
}
void preencherVetor(int *vetor, int *vetorBackUp, int tamanho){
    for(int i=0; i<tamanho; i++){
        cout << "Digite o vetor[" << i << "]: ";
        cin >> vetor[i];
        vetorBackUp[i] = vetor[i];
    }
    char key;
    cout << "Deseja acessar o menu: s/n: ";
    cin >> key;
    if(key == 's' || key == 'S'){
        menu(vetor,vetorBackUp, tamanho);
    }

}


int main()
{
    int tamanho;
    cout << "Qual o tamanho desejado do vetor: ";
    cin >> tamanho;
    int vetor[tamanho];
    int vetorBackUp[tamanho];
    preencherVetor(vetor,vetorBackUp, tamanho);

    return 0;
}
