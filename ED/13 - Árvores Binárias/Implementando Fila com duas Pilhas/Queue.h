#ifndef QUEUE_H
#define QUEUE_H

#include <stack>

class Queue {
public:
    /*
    enqueue: adiciona um elemento no final da fila.
    dequeue: remove o elemento do início da fila.
    front: retorna o elemento do início da fila sem removê-lo.
    isEmpty: verifica se a fila está vazia.
    */
    
    void enqueue(int x);
    void dequeue();
    int front();
    bool isEmpty();

private:
    std::stack<int> pilha1;
    std::stack<int> pilha2;
};

#endif  