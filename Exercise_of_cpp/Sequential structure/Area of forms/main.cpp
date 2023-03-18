/*
 Fazer um programa que leia três valores com ponto flutuante de dupla precisão: A, B e C. Em seguida, calcule e
    mostre:
        a) a área do triângulo retângulo que tem A por base e C por altura.
        b) a área do círculo de raio C. (pi = 3.14159)
        c) a área do trapézio que tem A e B por bases e C por altura.
        d) a área do quadrado que tem lado B.
        e) a área do retângulo que tem lados A e B.

Write a program that reads in three double-precision floating-point values: A, B, and C. Then calculate and
    show:
        a) Find the area of ​​the right triangle that has A as its base and C as its height.
        b) the area of ​​the circle of radius C. (pi = 3.14159)
        c) the area of ​​the trapezoid that has A and B for bases and C for height.
        d) the area of ​​the square that has side B.
        e) the area of ​​the rectangle that has sides A and B.
*/


#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

int main(){
    cout << fixed << setprecision(2);

    float A,B,C, triangule = 0, circle = 0, trapeze = 0, square = 0, rectangule = 0;
    cout << "Choice value for A : " << endl;
    cin >> A;
    cout << "Choice value for B : " << endl;
    cin >> B;
    cout << "Choice value for C : " << endl;
    cin >> C;

    triangule = (A * C)/2;
    circle = 3.14*pow(C, 2);
    trapeze = ((A+B))*C/2;
    square = B * B;
    rectangule = A * B;

    cout << "Area of triangle : " << triangule << endl;
    cout << "Area of circle : " << circle << endl;
    cout << "Area of trapeze : " << trapeze << endl;
    cout << "Area of square : " << square << endl;
    cout << "Area of rectangulo : " << rectangule << endl;
}