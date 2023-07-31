#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node{
    int key; // chave
    Node *left; // ponteiro para esquerda
    Node *right; // ponteiro para direita

    Node(const int& key, Node *left, Node *right){
        this->key = key;
        this->left = left;
        this->right = right;
    }

    ~Node(){
        std::cout<<key<<"removed"<<std::endl;
    }
};


#endif
