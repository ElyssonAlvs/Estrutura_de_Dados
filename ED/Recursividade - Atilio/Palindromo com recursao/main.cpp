#include <iostream>

using namespace std;

bool palindromo(string palavra, int ini, int fim){
    // caso base
    if(ini >= fim){
        return true;
    }
    // poderia usar um else, por ser um caso geral
    return (palavra[ini] == palavra[fim] && palindromo(palavra, ini + 1, fim - 1));
}

int main(){
    
    string str = "ana";
    
    cout<<boolalpha<<palindromo(str, 0,str.length() - 1);

    return 0;
}

