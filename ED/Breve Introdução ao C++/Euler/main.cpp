#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// Função Fatorial
double fatorial(int n){
    double fatorial = 1;
    if (n == 0)
    {
        cout << fatorial;
    }
    else if (n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            fatorial *= i;
        }
    }
    return fatorial;
}
// Número de Euler
double euler(int n){
    double euler = 1;
    for (int i = n; i > 0; i--)
    {
        euler += 1 / fatorial(i);
    }
    return euler;
}

int main(){
    cout << fixed << setprecision(6);
    int n;
    // Número inteiro
    cin >> n;
    cout << euler(n);
}