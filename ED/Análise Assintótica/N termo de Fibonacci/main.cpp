#include <iostream>

using namespace std;
// Retorna a soma dos elementos
int fibonacci(int n) {
    // Caso o o termo requerido seja 0
    if (n == 0){
        return 0;
    }
    // Caso o termo requerido seja 1
    if (n == 1){
        return 1;
    }
    // Variáveis para controle da iteração
    int anterior = 0, atual = 1, proximo;
    // Calcular cada termo da sequência dentor do loop
    for (int i = 2; i <= n; i++){
        // Soma os dois elementos anteriores para ter o proximi
        proximo = anterior + atual;
        // Atualizar os valores do termos anteriores
        anterior = atual;
        atual = proximo;
    }
    // Retorno da função
    return atual;
}


int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
    /*
    Ele é linear pois a iterações ocorrem dentro do mesmo tempo de execução, 
    no caso, aqueles fora do escopo do loop, são descontados, sendo assim linear
    ou proporcional a n, O(n).
    */
}