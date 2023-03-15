#include <iostream>

using namespace std;

int main(){
    int valor_produto, chute_primeiro, chute_segundo;
    int verificador1, verificador2;
    // Pegar os valores
    cin >> valor_produto;
    cin >> chute_primeiro;
    cin >> chute_segundo;
    // Comparar as distâncias
    verificador1 = valor_produto - chute_primeiro;
    verificador2 = valor_produto - chute_segundo;
    // Transformar em positivo
    if(verificador1 < 0){
        verificador1 *= -1;
    }
    if(verificador2 < 0){
        verificador2 *= -1;
    }

    // Comparar resultados
    if(verificador1 == verificador2){
        cout << "empate";
    }else if(verificador1 < verificador2){
        cout << "primeiro";
    }else{
        cout << "segundo";
    }
}