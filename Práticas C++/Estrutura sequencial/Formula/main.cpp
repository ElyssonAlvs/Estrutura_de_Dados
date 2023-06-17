/*
Fazer um programa para ler quatro valores inteiros A, B, C e D. A seguir, calcule e mostre a diferença do produto
de A e B pelo produto de C e D segundo a fórmula: DIFERENCA = (A * B - C * D).

Make a program to read four integer values ​​A, B, C and D. Then calculate and show the difference of the product
of A and B by the product of C and D according to the formula: DIFFERENCE = (A * B - C * D).

*/
#include <iostream>

using namespace std;

int main(){
    int A, B, C, D, difference;
    cout << "Write numbers A,B,C and D : ";
    cin >> A >> B >> C >> D;
    difference = (A * B - C * D);

    cout << "The result of calcule is " << difference;
}