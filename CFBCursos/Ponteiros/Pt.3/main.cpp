#include <iostream>

using namespace std;

// Ponteiro é um acesso direto ao valor de uma variavel

// "adiciona" a variavel o valor passa como parametro
void somar(float *var, float valor){
    *var += valor;
}

void iniVetor(float *v){
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
}

int main(){
    
    float num = 0;
    float vetor[5];
    
    // (endereco da variavel, valor que substitui o valor)
    somar(&num, 15);
    // nao precisa de & por ser um vetor
    iniVetor(vetor);
    
    
    cout<<num<<endl;

    for(int i = 0; i < 5; i++){
        cout<<vetor[i]<<endl;
    }
    
    return 0;
}
