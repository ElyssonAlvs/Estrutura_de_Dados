#ifndef CLIST_H
#define CLIST_H
#include <iostream>
#include <string>
#include "Node.h"

/**
 * Implemanta uma lista circular simplismente encadeada
 * com no sentinela
*/

class CircularList {
private:
    Node *m_head {nullptr};  // ponteiro para o no sentinela
    int m_size {0};          // numero de elementos na lista
    Node *m_tail {nullptr}; 

public:
    // Construtor default;
    CircularList(); 

    // retorna se a lista esta vazia
    bool empty() const;

    // retorna o numero de elementos na lista
    int size() const { return m_size; }

    // adiciona um elemento ao final da lista
    void push_back(const int& val);

    // remove um elemento do final da lista, se ele existir
    // caso contrario, nao faz nada
    void pop_back();

    // sobrecarga do operador[] 
    // possibilita acessar diretamente o elemento no indice 'index'
    int& operator[](int index);

    // versao const da sobrecarga do operador[] 
    // possibilita acessar diretamente o elemento no indice 'index' 
    const int& operator[](int index) const;

    // deixa a lista vazia, liberando todos os nos
    void clear();

    // destrutor
    ~CircularList();

    // retorna os elementos no formato de string
    std::string toString() const;

    // sobrecarga do operador<<
    friend std::ostream& operator<<(std::ostream& out, CircularList& lst);

    // adiciona um elemento no inicio da lista
    void push_front(const int& val); 

    // remove um elemento do inicio da lista, se ele existir
    // caso contrario, nao faz nada
    void pop_front();

    class iterator{
    private:
        Node *ptr {nullptr};
    public:
        iterator(Node *pointer){
            ptr = pointer;
        }
        iterator(const iterator& it){
            ptr = it.ptr;
        }

        bool operator!=(const iterator& iterator){
            return this->ptr != iterator.ptr;
        }

        bool operator==(const iterator& iterator){
            return this->ptr == iterator.ptr;
        }

        int& operator*(){
            return ptr->value;
        }

        iterator operator++(){
            ptr = ptr->next;
            return *this;
        }

        iterator operator++(int){
           iterator copia(ptr);
           ptr = ptr->next;
           return copia;
        }
    };
    // apontar para o primeiro
    iterator begin(){
        return iterator(m_head->next);
    }
    // apontar para o final
    iterator end(){
        return iterator(m_head);
    }
};

#endif