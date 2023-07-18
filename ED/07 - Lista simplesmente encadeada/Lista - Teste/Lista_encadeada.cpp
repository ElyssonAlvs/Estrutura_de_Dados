#include <iostream>
#include "Lista.h"

int main(){
    Lista<string> l;

    l.inserir_final("python");
    l.inserir_final("c++");
    l.inserir_final("ruby");
    l.inserir_inicio("haskell");

    l.monstrar();

    if(l.vazia()){
        cout<<"Lista vazia !!\n";
    }else{
        cout<<"Lista NAO vazia!! \n";
    }

    cout<<"\nRemovendo elemento do final...\n";

    l.remover();

    l.monstrar();

    cout<<"Tamanho da lista: "<<l.tamanho()<<endl;

    return 0;
}
