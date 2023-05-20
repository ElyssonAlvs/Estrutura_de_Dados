#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c){
    int contador = 0;
    
    if(n > 0){
        if(str[n-1] == c){
            contador++;
        }
    contador += contaCaracteres(str, n - 1, c);
        }
    return contador;
}


int main() {
   
   string frase;
   getline(cin,frase);
   
   char letra;
   cin>>letra;
   
   int n = frase.size();
   
   cout<<contaCaracteres(frase, n, letra);
   
}