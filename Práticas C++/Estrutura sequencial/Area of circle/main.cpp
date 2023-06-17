/*
Faça um programa para ler o valor do raio de um círculo, e depois mostrar o valor da área deste círculo com quatro
casas decimais conforme exemplos.
Fórmula da área: area = π . raio2
Considere o valor de π = 3.14159

Make a program to read the value of the radius of a circle, and then show the value of the area of ​​this circle with four
decimal places as examples.
Area formula: area = π . radius2
Consider the value of π = 3.14159

*/
#include <iostream>
#include <math.h>
#include <iomanip>
#define PI 3.14159
using namespace std;

int main(){
    cout << fixed << setprecision(4);
    float radius, area;
    cout << "Write this radius of the circle : ";
    cin >> radius;
    area = PI * pow(radius,2);
    cout << "The area of the circle is " << area;

}