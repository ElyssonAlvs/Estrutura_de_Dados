#include <iostream>

using namespace std;
// Verificar ordenacao
bool ordenado(int n, int vetor[]){
    bool ordenado = true;
    for(int i = 0; i < n - 1; i++){
        if(vetor[i] > vetor[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    // Variáveis
    int tamanho, dominos[50];
    cin >> tamanho;
    // Pegar o vetor(dominos)
    for(int i = 0; i <= tamanho; i++){
        cin >> dominos[i];
    }
    // Verificar
    if(ordenado(tamanho, dominos)){
        cout << "ok";
    }else{
        cout << "precisa de ajuste";
    }
    
}