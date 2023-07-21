#include <iostream>
#include "Queuen.h"
using namespace std;

int main(){
    Queue<string> fila;

    fila.push("adriana");
    fila.push("maria");
    fila.push("juca");
    fila.push("julia");

    Queue<string> fila2 (fila);
    fila2.pop();
    if(fila == fila2){
        cout<<"as duas filas são idênticas"<<endl;
    }else{
        cout<<"fila dinstintas"<<endl;
    }

    while(!fila.empty()){
        cout<<fila.front()<<endl;
        fila.pop();
    }
}