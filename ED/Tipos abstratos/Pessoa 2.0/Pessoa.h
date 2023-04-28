#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>
#include <string>

class Pessoa {
private:
    int idade {0};
    std::string nome;
    float altura {1.2};

public:
    // Construtor
    Pessoa(int i = 15, std::string n = "atilio", float a = 1.0);

    int get_idade();

    std::string get_nome();

    float get_altura();

    // funcao que altera a idade da pessoa
    void set_idade(int idade);

    // funcao que altera o nome da pessoa
    void set_nome(std::string nome);

    // funcao que altera a altura da pessoa
    void set_altura(float altura);

    // Destrutor
    ~Pessoa();
};

#endif
