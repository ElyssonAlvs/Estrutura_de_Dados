#ifndef NODE_H
#define NODE_H

template<typename T>

struct Node{
    T value; // valor a ser guardado, do tipo T
    Node* next; // ponteiro para o próximo da fila

    // Construtor
    Node(const T& val, Node* nextPtr){
        value = val;
        next = nextPtr;
    }
    ~Node(){
        delete next; // quando um no é deletado, ele deleta o próximo, delete no seu next
    }
};

#endif 
