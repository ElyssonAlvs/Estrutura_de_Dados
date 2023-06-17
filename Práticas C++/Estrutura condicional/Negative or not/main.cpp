#include <iostream>

using namespace std;

/*
Fazer um programa para ler um npumero inteiro e depois dizer se este 
número é negativo ou não
*/

int main(){

    int number;
    cout<<"Digite um numero: ";
    cin>>number;

    if(number < 0){
        cout<<"O numero eh negativo";
    }else{
        cout<<"O numero eh positivo";
    }
}