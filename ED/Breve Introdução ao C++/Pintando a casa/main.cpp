#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    cout << fixed << setprecision(2);
    // Lados do Triângulo
    float a=0,b=0,c=0;
    cin >> a;
    cin >> b;
    cin >> c;
    // Semi-Perímetro
    float p;
    p = (a+b+c)/2;
    // Formula de Heron
    float area;
    area = sqrt(p*(p-a)*(p-b)*(p-c));
    // Área do triângulo
    cout << area;
}