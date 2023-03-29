#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string verifica(string frase){
    bool ehstring = false;
    bool ehfloat = false;
    for(int i = 0; i < frase.length(); i++){
        if(frase[i] >= 97 && frase[i] <= 122){
            ehstring = true;
        }if(frase[i] == '.'){
            ehfloat = true;
        }
    }if(ehstring){return "str";}
    else if(ehfloat){return "float";}
    else{return "int";}
}


int main(){
    string frase;
    getline(cin, frase);

    // guarda dentro de palavra a frase
    stringstream palavra;
    palavra << frase;
    
    
    for(int i = 0; i < frase.length(); i++){
        // a cada loop a temp vai receber uma palavra de frase
        string temp;
        if(i == 0){
            palavra >> temp;
            cout << verifica(temp);
        }else if(frase[i] == ' '){
            palavra >> temp;
            cout << " " << verifica(temp);
        }
    }
}