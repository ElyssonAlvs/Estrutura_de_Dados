#include <iostream>

using namespace std;
// Retorna a soma dos elementos
int fibonacci(int n){
    int primeiro {0}, segundo{1}, proximo, soma {0};
    // termos da sequência
    for (int i = 1; i <= n; ++i){
        // primeiro elemento
        if(i == 1){
            soma += primeiro;
        }else if(i == 2){
            // segundo elemento
            soma += segundo;
        }else{
            // Caso contrário, o proximo termo recebe a soma dos dois anteriores
            proximo = primeiro + segundo;
            // os valores são atualizados para termos anteriores
            primeiro = segundo;
            segundo = proximo;
            soma += proximo;
        }
    }
    return soma;
}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci(n)<<endl;
}