#include <iostream>

using namespace std;

int main(){

    int *p;
    int vetor[10];

    //p = vetor;  atribui ao ponteiro "p" o endereço de memória do primeiro elemento do vetor
    
    p = &vetor[0]; // atribui ao ponteiro "p" o endereço de memória do primeiro elemento do vetor
    *p = 10; // atribui 10 na posicao 0 do vetor; vetor[0]=10
    cout<<endl<<vetor[0]<<endl;

    // a direrença dos endereço é de 4 bytes

    *(p += 1); // passa para a próxima posição de endereço
    *p = 20; // atribui o 20 na posicao 1 do vetor; vetor[1]=20
    cout<<endl<<vetor[1]<<endl;

    *(p += 1); // passa para a próxima posição de endereço
    *p = 30; // atribui o 30 na posicao 2 do vetor; vetor[2]=20
    cout<<endl<<vetor[2]<<endl;

    return 0;
}