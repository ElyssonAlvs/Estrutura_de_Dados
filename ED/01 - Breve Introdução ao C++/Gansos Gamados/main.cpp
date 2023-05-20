#include <iostream>
#include <sstream>

using namespace std;

int main(){
    // pegar a frase, até um espaço
    string frase;
    getline(cin,frase);
    
    // coloca a frase, cada caractere separadamente, inclusive os espaços em buffer
    stringstream ss;
    ss<<frase;
    
    // pega apenas a primeira palavra da frase
    string palavra;
    ss>>palavra;
    
    // variável lógica
    bool emordem = true;
    
    for(int i = 0; i < (int)frase.length(); i++){
        // percorrer a frase "separada"
        if((i>0) && (frase.at(i) == ' ')){
            string temporaria;
            // armazena o elemento do índice correspondente ao loop em uma variável do próprio loop
            ss>>temporaria;
            
            /* verificar se a palavra, armazenada fora do loop, é menor que a armazenada dentro do loop;
            assim, se for menor, o valor de palavra vai para temporaria, se iniciando outro loop, a cada loop,
            o valor lógico de emordem é verificado;
            */
            if(palavra < temporaria){
                palavra = temporaria;
            }else{
                emordem = false;
                // no caso vai encerra a estrutura condicional mais próxima -> if(palavra < temporaria)
                break;
            }
        }
    }
    
    if(emordem){
        cout<<"sim";
    }else{
        cout<<"nao";
    }
    
}