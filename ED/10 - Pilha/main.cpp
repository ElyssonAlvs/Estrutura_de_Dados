#include <iostream>
#include <sstream>
//#include "Stack.h"
#include <stack>

using namespace std;

void inverte_palavras(string& sentenca){
    stringstream ss {sentenca};
    string palavra;
    while(ss >> palavra){
        stack<char> pilha;
        pilha.push(' ');
        for(int i : palavra){
            pilha.push(i);
        }
        while(!pilha.empty()){
            cout<<pilha.top();
            pilha.pop();
        }
        //cout<<" ";
    }
}   

int main(){
    string str{"AMU MEGASNEM ATERCES"};
    inverte_palavras(str);
    return 0;
}


/*
int main(){
    Stack<string> pilha;
    string input, palavra;
    cout<<"Digite uma lista de nomes: ";
    getline(cin, input);
    stringstream ss {input};

    while(ss >> palavra){
        pilha.push(palavra);
    }

    while(!pilha.empty()){
        cout<<pilha.top()<<endl;
        pilha.pop();
    }

    cout<<"Fila vazia";
}
*/