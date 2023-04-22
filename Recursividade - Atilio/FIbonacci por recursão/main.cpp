#include <iostream>

using namespace std;
// funcao retorna o numero no indice da sequencia de Fibonacci
long fib(int n){
    // caso base
    if(n == 0 || n == 1){
        return n;
    }else{
        // caso geral
        return fib(n - 1) + fib(n - 2);
    }
}

int main(){
    
    int n;
    cin>>n;
    
    cout<<fib(n);

    return 0;
}
