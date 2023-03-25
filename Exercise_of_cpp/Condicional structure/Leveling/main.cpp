/*
Em um país imaginário denominado Lisarb, todos os habitantes ficam felizes em pagar seus impostos, pois sabem
que nele não existem políticos corruptos e os recursos arrecadados são utilizados em benefício da população, sem
qualquer desvio. A moeda deste país é o Rombus, cujo símbolo é o R$.
Leia um valor com duas casas decimais, equivalente ao salário de uma pessoa de Lisarb. Em seguida, calcule e
mostre o valor que esta pessoa deve pagar de Imposto de Renda, segundo a tabela abaixo
* de 0.00 a 2000.00 -> isento
* de 2000.01 até 3000.00 -> 8%
* de 3000.01 até 4500.00 -> 18%
* acima de 4500.00 -> 28%
Lembre que, se o salário for R$ 3002.00, a taxa que incide é de 8% apenas sobre R$ 1000.00, pois a faixa de
salário que fica de R$ 0.00 até R$ 2000.00 é isenta de Imposto de Renda. No exemplo fornecido (abaixo), a taxa é
de 8% sobre R$ 1000.00 + 18% sobre R$ 2.00, o que resulta em R$ 80.36 no total. O valor deve ser impresso com
duas casas decimais.

In an imaginary country called Lisarb, all inhabitants are happy to pay their taxes, as they know
that there are no corrupt politicians in it and the resources collected are used for the benefit of the population, without
any deviation. The currency of this country is the Rombus, whose symbol is R$.
Read a value with two decimal places,
equivalent to the salary of a person from Lisarb. Then calculate and
show the amount that this person must pay in Income Tax, according to the table below
* from 0.00 to 2000.00 -> exempt
* from 2000.01 to 3000.00 -> 8%
* from 3000.01 to 4500.00 -> 18%
* above 4500.00 -> 28%
Remember that if the salary is R$ 3002.00,
the rate applied is 8% only on R$ 1000.00, as the range of
salary that ranges from R$ 0.00 to R$ 2000.00 is exempt from Income Tax. In the example provided (below), the rate is
of 8% on BRL 1000.00 + 18% on BRL 2.00, which results in BRL 80.36 in total. The value must be printed with
two decimal places.
*/
#include <iostream>

using namespace std;

int main(){

    float salary,impost;
    cout << "Write your salary: ";
    cin >> salary;
    if (salary <= 2000.0){
        impost = 0.0;
    }else if (salary <= 3000.0){
        impost = (salary - 2000.0) * 0.08;
    }else if (salary <= 4500.0){
        impost = (salary - 3000.0) * 0.18 + 1000.0 * 0.08;
    }else{
        impost = (salary - 4500.0) * 0.28 + 1500.0 * 0.18 + 1000.0 * 0.08;
    }
    if (impost == 0.0){
        cout << "Free";
    }
    else{
        cout << "R$ " << impost;
    }
}