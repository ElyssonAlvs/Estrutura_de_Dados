#include <iostream>

using namespace std;

int main(){
/*
    // Alocação Estática


    // int vet[4];
    // int vet[0] = 5;
    // int vet[1] = 10;

    int vet[4] = {5, 10};

    // cout << vet[4] << endl;
    cout << "[ ";
    for (int i = 0; i < 4; i++){
        cout << vet[i] << " ";
    }
    cout << "] " << endl;


    int x = sizeof(vet)/sizeof(int);
    int y = sizeof(int);
    cout << "Tamanho de inteiro: " << y << endl;
    cout << "Quantidad de elementos do vetor: " << x << endl; 

*/
    // Alocação Dinâmica
    int tam;
    cout << "Digite o tamanho do vetor!" << endl;
    cin >> tam;
    int* vetor = new int[tam];
    for(int i = 0; i < tam; i++){
        cout << "Digite o elemento " << i << "do vetor: " << endl;
        cin >> vetor[i];
    }

    for(int i = 0; i < tam; i++){
            cout << vetor[i] << " ";
    }
    cout << endl;

    delete [] vetor;

    return 0;
}