#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    int q;
    cin >> q;

    Queue fila;

    while (q--) {
        int token;
        cin >> token;

        if(token == 1){
            int x;
            std::cin >> x;
            fila.enqueue(x);
        }else if (token == 2){
            fila.dequeue();
        } else if (token == 3){
            int frente = fila.front();
            cout<<frente<<endl;
        }
    }

    return 0;
}
