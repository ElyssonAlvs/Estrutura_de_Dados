#include <iostream>
#include <queue>
using namespace std;

int main(){
    // preencher a fila
    char bloco = 'A';
    queue<char> fila;
    while(bloco != 'Q'){
        fila.push(bloco);
        bloco++;
    }
    for (int i = 0; i < 15; i++){
        int bloco1, bloco2;
        cin >> bloco1 >> bloco2;
        
        if(bloco1 > bloco2){
            fila.push(fila.front());
            fila.pop();
            fila.pop();
        }
        else if(bloco1 < bloco2){
            fila.pop();
            fila.push(fila.front());
            fila.pop();
        }
    }
    cout << fila.front() << endl;
}