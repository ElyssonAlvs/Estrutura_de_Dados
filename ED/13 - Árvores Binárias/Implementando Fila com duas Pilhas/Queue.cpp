#include "Queue.h"
#include <iostream>

void Queue::enqueue(int x){
    pilha1.push(x);
}

void Queue::dequeue(){
    if (isEmpty()){
        return;
    }

    if (pilha2.empty()){
        while (!pilha1.empty()) {
            pilha2.push(pilha1.top());
            pilha1.pop();
        }
    }
    pilha2.pop();
}

int Queue::front() {
    if (isEmpty()) {
        return -1;  // Returna -1 indicando que a pilha está vazia
    }

    if (pilha2.empty()){
        while (!pilha1.empty()) {
            pilha2.push(pilha1.top());
            pilha1.pop();
        }
    }

    return pilha2.top();
}

bool Queue::isEmpty(){
    return pilha1.empty() && pilha2.empty();
}
