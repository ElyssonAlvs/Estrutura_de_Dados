/**
 * Arquivo de implementacao das funcoes-membro da classe Pessoa
*/
#include <iostream>
#include <string>
#include "Pessoa.h"

Pessoa::Pessoa(int i, std::string n, float a) {
    idade = i;
    nome = n;
    altura = a;
}

int Pessoa::get_idade() {
    return idade;
}

std::string Pessoa::get_nome() {
    return nome;
}

float Pessoa::get_altura() {
    return altura;
}

// funcao que altera a idade da pessoa
void Pessoa::set_idade(int idade) {
    this->idade = idade;
}

// funcao que altera o nome da pessoa
void Pessoa::set_nome(std::string nome) {
    this->nome = nome;
}

// funcao que altera a altura da pessoa
void Pessoa::set_altura(float altura) {
    this->altura = altura;
}

Pessoa::~Pessoa() {
    std::cout << "foi liberado: " << nome << "," << idade 
                << "," << altura << "\n";
}
