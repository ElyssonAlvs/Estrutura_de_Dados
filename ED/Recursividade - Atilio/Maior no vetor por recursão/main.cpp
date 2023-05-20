#include <iostream>

using namespace std;
// encontra o maior valor, usando recursão
int maior(int vetor[], int n, int i){
    // se primeiro elemento, retorna o vetor no índice 0
    if(n==0){
        return vetor[i];
    }else{
        // vetor[0 - 1] > vetor [1]
        if(vetor[n - 1] > vetor[i]){
            return maior(vetor,n - 1, n -1);
        }else{
            return maior(vetor,n - 1, i);
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    
    int vetor[n];
    
    for(int i = 0; i < n; i++){
        cin>>vetor[i];
    }
    
    cout<<maior(vetor,n,0)<<endl;
}

// outra forma

/*
// Ao receber v e n >= 1, a função devolve 
// o valor de um elemento máximo do
// vetor v[0..n-1].


int maximo (int n, int v[]){ 
   if (n == 1)
      return v[0];
   else{
      int x;
      x = maximo (n-1, v);
      // x é o máximo de v[0..n-2] 
      if(x > v[n-1]){
        return x;
      }else{
        return v[n-1];
      }
   }
}
*/


