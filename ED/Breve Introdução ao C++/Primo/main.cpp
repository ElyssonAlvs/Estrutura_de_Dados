#include <iostream>

using namespace std;
// Verificar se o número é primo
bool primo(int n){
    for(int i = 2; i <= n-1; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int numeroA, numeroB;
    cin >> numeroA >> numeroB;
    // Percorrer o vetor e identificar os primos dentro do intervalo
    for (int i = numeroA; i <= numeroB; i++)
        if(primo(i)){
            cout << i << endl;
    }
}