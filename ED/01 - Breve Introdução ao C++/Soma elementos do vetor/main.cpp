/*
O exemplo abaixo lê o tamanho n do vetor e declara um vetor com n
inteiros. Em seguida, pede para o usuário digitar o valor de cada
elemento do vetor, calcula e imprime a soma dos elementos.
*/
#include <iostream>

using namespace std;

int main(){
    int n, i, soma = 0;

    cin >> n;

    int vetor[n];

    for (i = 0; i < n; i++)
        cin >> vetor[i];

    for (i = 0; i < n; i++)
        soma = soma + vetor[i];
    cout << soma << endl;
}