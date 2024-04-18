#include <iostream>

using namespace std;
struct Atleta
{
    string name;
    int idade;
    double altura;
    double peso;
};
void imprimirVetor(Atleta *vetor)
{
    int tamanho = sizeof(vetor);
    cout << "Tabela com os valores dos vetores abaixo: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << "Vetor[" << i + 1 << "]" << endl;
        cout << vetor[i].name << endl;
        cout << vetor[i].idade << endl;
        cout << vetor[i].altura << endl;
        cout << vetor[i].peso << "\n"
             << endl;
    }
}
void imprimirVetorNormal(int *vetor, int tamanho)
{
    cout << "Tabela com os valores dos vetores abaixo: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << vetor[i] << endl;
    }
}
void selecaoDireta(int *vetor,int tamanho)
{
    cout << "------------------------SelecaoDireta------------------------" << endl;
    int iMenor, aux;
    for(int i=0; i<tamanho-1; i++)
    {
        iMenor = i;
        for(int k=i+1; k< tamanho;  k++)
        {
            if(vetor[k] < vetor[iMenor])
            {
                cout << "if(vetor[k] < vetor[iMenor) veradeiro." << endl;
                iMenor = k;
                cout << "iMenor = k " << iMenor << endl;
            }
            if(iMenor != i)
            {
            cout << "if(iMenor != I) verdadeiro." << endl;
                aux = vetor[iMenor];
                vetor[iMenor] = vetor[i];
                vetor[i] = aux;
            cout << "Troca dos elementos vetor[iMenor] <=> vetor[i]" << endl;
            }
        }
    }
    imprimirVetorNormal(vetor, tamanho);
}
void insercaoDireta(int *vetor, int tamanho )
{
    cout << "------------------------InsercaoDireta------------------------" << endl;
    int i,k,temp;
    for(i=1; i<tamanho; i++)
    {
        k=i;
        temp = vetor[i];
        while(k>0 && (temp < vetor[k-1]))
        {
            vetor[k] = vetor[k-1];
            cout << "Vetor[k]: " << vetor[k] << "Vetor[k-1]" << vetor[k-1] << endl;
            k--;
        }
        cout << "Fora do While " << endl;
        cout << "Vetor[k]" << vetor[k] << " Temp: " << temp << endl;
        vetor[k] = temp;
    }
    imprimirVetorNormal(vetor, tamanho);
}
/* Método de particionamento que é o núcleo do algoritmo QuickSort.
*  É a implementação utilizando o paradigma dividir para conquistar
*/


void boobleSort(Atleta *vetor)
{
    int tamanho = sizeof(vetor);
    int x, y, trocas = 0;
    Atleta aux;
    for (x = 0; x < tamanho; x++)
    {
        for (y = x + 1; y < tamanho; y++)
        {
            if (vetor[x].idade > vetor[y].idade)
            {
                cout << "Trocando Posicao[ " << x << "] para [" << y << "]" << endl;
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
                trocas++;
                cout << "Trocas efetuadas: " << trocas << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
        }
    }
    imprimirVetor(vetor);
}
void boobleSort(int *vetor, int tamanho)
{
    cout << "------------------------BooleSort------------------------" << endl;
    int x, y, trocas = 0;
    int aux;
    for (x = 0; x < tamanho; x++)
    {
        for (y = x + 1; y < tamanho; y++)
        {
            if (vetor[x] > vetor[y])
            {
                cout << "Trocando Posicao[ " << x << "] para [" << y << "]" << endl;
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
                trocas++;
                cout << "Trocas efetuadas: " << trocas << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
        }
    }
        imprimirVetorNormal(vetor, tamanho);

}
void boobleSortTroca(Atleta *vetor)
{
    cout << "------------------------BoobleSortTroca------------------------" << endl;
    int fim, troquei, trocas = 0;
    Atleta aux;
    fim = sizeof(vetor);
    do
    {
        troquei = 0;
        for (int i = 0; i < fim - 1; i++)
        {
            if (vetor[i].idade > vetor[i + 1].idade)
            {
                cout << "Trocando posicao [" << i << "]"
                     << "para [" << i + 1 << "]" << endl;
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troquei = 1;
                trocas++;
                cout << "Trocas Efetuadas: " << trocas << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
        }
        fim--;

    }
    while (troquei && fim > 1);
    imprimirVetor(vetor);
}
void boobleSortTroca(int *vetor, int tamanho)
{
    cout << "------------------------BoobleSortTrocar------------------------" << endl;
    int fim, troquei, trocas = 0;
    int aux;
    fim = tamanho;
    do
    {
        troquei = 0;
        for (int i = 0; i < fim - 1; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                cout << "Trocando posicao [" << i << "]"
                     << "para [" << i + 1 << "]" << endl;
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troquei = 1;
                trocas++;
                cout << "Trocas Efetuadas: " << trocas << endl;
                cout << "----------------------------------------------------------------" << endl;
            }
        }
        fim--;

    }
    while (troquei && fim > 1);
    imprimirVetorNormal(vetor, tamanho);
}
void preencherVetorAtleta()
{
    int total = 0;
    do
    {
        cout << "Digite o numero desejado de atletas que deseja cadastrar: ";
        cin >> total;
    }
    while (total < 3 && total > 50);
    Atleta vetAtleta[total];

    for (int i = 0; i < total; i++)
    {
        cout << "Posicao [" << i << "]" << endl;
        cout << "Digite o nome: " << endl;
        cin >> vetAtleta[i].name;
        fflush(stdin);
        cout << "Digite a altura: " << endl;
        cin >> vetAtleta[i].altura;
        cout << "Digite o peso: " << endl;
        cin >> vetAtleta[i].peso;
        cout << "Digite a idade: " << endl;
        cin >> vetAtleta[i].idade;
    }
}
void preencherVetor(int *vetor, int tamanho){
    for(int i=0; i< tamanho; i++){
        cout << "Digite o valor do vetor[" << i << "]" << endl;
        cin >> vetor[i];
    }
    cout << "Vetor preenchido." << endl;
}

int main()
{
    int tamanho=0;
    cout << "Digite o tamanho que desaja criar o vetor: ";
    cin >> tamanho;
    int vetorNum[tamanho];
    preencherVetor(vetorNum, tamanho);
    cout << endl;
    boobleSortTroca(vetorNum, tamanho);
    cout << endl;
    boobleSort(vetorNum, tamanho);
    cout << endl;
    selecaoDireta(vetorNum, tamanho);
    cout << endl;
    insercaoDireta(vetorNum, tamanho);


    return 0;
}
