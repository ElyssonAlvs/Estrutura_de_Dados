#include <iostream>

using namespace std;

/*
Fazer um programa para ler um número inteiro e dizer se este número é par ou ímpar
Write a program to read an integer and say if this number is even or odd
*/
int main(){

    int number;
    cout<<"Type of number: ";
    cin>>number;

    if(number % 2 == 0){
        cout<<"This number is pair";
    }else{
        cout<<"This number is odd";
    }
}