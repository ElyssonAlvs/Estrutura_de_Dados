#ifndef NODE_H
#define NODE_H

struct{
    int values; // valor inteiro chave
    Node *next; // Ponteiro para o prximo node

    Node(const int& val, Node *nextPtr){
        value = val;
        next = nextPtr;
    }
}


#endif