#include <iostream>

using namespace std;
// ordenação do tipo Insertion sort
void insert_sort(int vetor[], int tamanho){
    int auxiliar, j;
    for(int i = 1; i < tamanho; i++){
        auxiliar = vetor[i];
        j = i - 1;
        while(j >= 0 && vetor[j] > auxiliar){
            vetor[j+1] = vetor[j];
            j -= 1;
        }
        vetor[j+1] = auxiliar;
    }
}

int main(){
    int tamanho;
    // Inserir o tamanho do vetor
    cin>>tamanho;
    int vetor[tamanho];
    // Pegar os valores do vetor 
    for(int i = 0; i < tamanho; i++){
        cin>>vetor[i];
    }
    // Antes de ordenar
    for(int i = 0; i < tamanho; i++){
        cout<<vetor[i]<<" ";
    }

    cout<<endl;
    // Chamada da função
    insert_sort(vetor, tamanho);
    
    // Depois de ordenar
    for(int i = 0; i < tamanho; i++){
        cout<<vetor[i]<<" ";
    }

    /*
    A complexidade de pior caso do algoritmo é O(n^2), quando o vetor está ordenado em ordem decrescente
    e o algoritmo precisa inserir cada elemento no começo do vetor. A complexidade de melhor caso é O(n),
    quando o vetor já está ordenado e o algoritmo precisa apenas percorrer o vetor uma vez para confirmar
    que está ordenado.
    */
}