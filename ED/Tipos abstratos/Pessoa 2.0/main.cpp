#include <iostream>
#include <string>
#include "Pessoa.h"
using namespace std;

// funcao que recebe uma pessoa e imprime seus dados
void print_pessoa(Pessoa& p) {
    cout << p.get_altura() << " " 
         << p.get_nome() << " "
         << p.get_idade() << endl;
}

int main() {
    Pessoa p1;
    Pessoa p2 (44);
    Pessoa p3 (56, "marilia");
    Pessoa p4 (25, "Pedro da Silva", 2.0);

    Pessoa *ptr = new Pessoa(25, "Luiz", 1.44);

    print_pessoa(p1);
    print_pessoa(p2);
    print_pessoa(p3);
    print_pessoa(p4);
    print_pessoa(*ptr);

    delete ptr;
}