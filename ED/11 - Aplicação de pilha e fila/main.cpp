#include <string>
#include <iostream>
#include <stack>
#include<cctype>
#include <sstream>
using namespace std;

/**
 * Recebe uma string contando paranteses
 * e colchetes e verifica se ela eh bem formada
*/
/*
bool bem_formada(string expressao){
    stack<char> pilha;
    for(unsigned i = 0; i < expressao.size(); i++){
        switch (expressao[i]){
        case '(':
        case '[': 
            pilha.push(expressao[i]);
            break;
        case ')':
            if(!pilha.empty() && pilha.top() == '('){
                pilha.pop();
            }else{
                return false;
            }
            break;
        case ']':
            if(!pilha.empty() && pilha.top() == '['){
                pilha.pop();
            }else{
                return false;
            }
            break;
        }
    }
    return pilha.empty();
}
*/

/*
 * Recebe uma string com uma expressao artitmetica na ordem posfixa
 * e imprime o avlor dela. Os operadores aritméticos
 * sao apenas +,-,*,/ e os numeros sao inteiros positivos
*/
double calcula_posfixa(string& posfix){
    stack<double> pilha;
    for(unsigned int i = 0; i < posfix.size(); i++){
        if(isspace(posfix[i])){
            continue;
        }
        if(isdigit(posfix[i])){
            //char c = posfix[i];
            //pilha.push(c - '0');
            stringstream ss;
            while(posfix[i] != ' '){
                ss<<posfix[i];
                i++;
            }
            double x;
            ss >> x;
            pilha.push(x);
        }else{
            int a = pilha.top(); pilha.pop();
            int b = pilha.top(); pilha.pop();
            switch (posfix[i]){
                case '+': pilha.push( b + a );
                          break;
                case '-': pilha.push( b - a );
                          break;
                case '*': pilha.push( b * a );
                          break;
                case '/': pilha.push( b / a );
                          break;
            }        
        }
    }
    return pilha.top();
}

string parentizada_para_posfix(string& parentizada){
    stack<char> pilha;
    for(int i = 0; i < parentizada.size(); i++){
        if(isspace(parentizada[i] == '(')){
                continue;
        }
        if(isdigit(parentizada[i]) == ')'){
        
        }else{ // vimos um digito

        }
    }

}

int main(){
/*
    string expressao;
    getline(cin,expressao);
    cout<<boolalpha<<bem_formada(expressao)<<endl;
*/
    

    string posfixa {"20 30 + 2 3 * *"};
    cout<<"valor da posfixa: "<<calcula_posfixa(posfixa)<<endl;
}