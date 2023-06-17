/*
Leia 2 valores inteiros (A e B). Após, o programa deve mostrar uma mensagem "Sao Multiplos" ou "Nao sao
Multiplos", indicando se os valores lidos são múltiplos entre si. Atenção: os números devem poder ser digitados em
ordem crescente ou decrescente.

Read 2 integer values ​​(A and B). Afterwards, the program should show a message "Sao Multiplos" or "No são
Multiples", indicating whether the values ​ read are multiples of each other. Attention: the numbers must be able to be typed in
ascending or descending order.
*/
#include <iostream>

using namespace std;

int main(){
    int numberA, numberB;
    cout << "Type a number A: ";
    cin >> numberA;
    cout << "Type a number B: ";
    cin >> numberB;
    if ((numberA % numberB == 0) || (numberB % numberA == 0)){
        cout << "Are multiple";
    }else{
        cout << "Are not multiple";
    }
}