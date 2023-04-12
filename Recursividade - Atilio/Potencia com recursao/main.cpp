#include <iostream>

using namespace std;
// funcao retorna a potenciacao de base^expo
double potenciacao(double base, double expo){
    // caso base
    if(expo == 0){
        return 1;
    }else{
        // formula da potencia por recursao
        return base * potenciacao(base, expo - 1);
    }
}

int main(){
    
    int base,expo;
    cin>>base>>expo;
    
    cout<<potenciacao(base, expo);

    return 0;
}

