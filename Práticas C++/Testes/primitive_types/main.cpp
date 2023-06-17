#include <iostream>

/*
Eu tenho 8 moedas de 1 centavo, 4 de 10 centavos e 3 de
25 centavos em minha carteira. Qual é o valor total das moedas?

I have 8 pennies, 4 pennies, and 3 pennies.
25 cents in my wallet. What is the total value of the coins?
*/

using namespace std;

int main()
{
    int pennies = 8;
    int dimes = 4;
    int quarters = 3;

    double total = pennies * 0.01 + dimes * 0.10 +
                   quarters * 0.25; /*value of coins*/

    cout << "Total Value = " << total << "\n";
}
