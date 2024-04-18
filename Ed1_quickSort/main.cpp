#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>& arr, int esquerda, int direita) {
    if (esquerda < direita) {
        int pivot = arr[esquerda];
        int i = esquerda + 1;
        int j = direita;

        cout << "Pivot: " << pivot << ", i: " << i << ", j: " << j << endl;

        while (true) {
            while (i <= j && arr[i] <= pivot){
              i++;
            cout << "Incrementei 'i': " << i << endl;
            }
            while (i <= j && arr[j] > pivot){
              j--;
              cout << "Decrementei 'j': " << j << endl;
            }
            if (i <= j) {
                swap(arr[i], arr[j]);
                cout << "Troca vetor["<< i <<"]: " << arr[i] << " e " <<"vetor["<< j << "]: " << arr[j] << endl;
            } else {
                break;
            }
        }

        swap(arr[esquerda], arr[j]);
        cout << "Troca final: " << arr[esquerda] << " e " << arr[j] << endl;

        cout << "Elementos a esquerda do pivot: ";
        for (int k = esquerda; k < j; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        cout << "Elementos a direita do pivot: ";
        for (int k = j + 1; k <= direita; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        quicksort(arr, esquerda, j - 1);
        quicksort(arr, j + 1, direita);
    }
}

int main() {
    vector<int> arr = {5, 9, 4, 6, 7, 3};
    quicksort(arr, 0, arr.size() - 1);
    cout << "Array ordenado: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
