// vai ser copiado dentro da main
#ifndef PESSOA H
#define PESSOA_H
#include <string>

class Pessoa{
private:
    int idade {0};
    std::string nome;
    float altura {1.2};

public:
    Pessoa(int i = 15, std::string n = "atilio", float a = 1.0){
        idade = i;
        nome = n;
        altura = a;
    }

    int get_idade(){
        return idade;
    }
    std::string get_nome(){
        return nome;
    }
    float get_altura(){
        return altura;
    }
    // função que altera a idade da pessoa
    void set_idade(int idade){
        this->idade = idade;
    }
    // função que altera o nome da pessoa
    void set_nome(std::string nome){
        this->nome = nome;
    }
      // função que altera a altura da pessoa
    void set_altura(float altura){
        this->altura = altura;
    }

    // Destrutor
    ~Pessoa(){
        std::cout<<"foi liberado: "<<nome<<", "
                 <<idade<<", "<<altura<<"\n";
                 
    }
};

#endif
