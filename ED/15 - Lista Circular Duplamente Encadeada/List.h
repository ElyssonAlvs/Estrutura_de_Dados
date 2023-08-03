#ifndef E5E37CCE_AA5B_4B44_AA4E_48938CD49EC9
#define E5E37CCE_AA5B_4B44_AA4E_48938CD49EC9
#include "Node.h"
#include <iostream>

/**
 * Classe implementa uma lista duplamente encadeada circular
 * com no sentinela
*/

class List{
private:
    Node *m_head; // ponteiro para o no sentinela
    size_t m_size; // numero de elementos na lista

public:
    class iterator{
    private:
        Node *pointer;
    public:
        iterator(){
            pointer = nullptr;
        }
        iterator(Node *ptr){
            pointer = ptr;
        }

        bool operator != (iterator& it){
            return this->pointer != it.pointer;
        }
        bool operator == (iterator& it){
            return this->pointer == it.pointer;
        }
        int& operator*(){
            return pointer->value;
        }
        iterator operator++(int){
            pointer = pointer->next;
            return *this;
        }
        iterator operator++(){
            iterator it_old(pointer);
            pointer = pointer->next;
            return it_old;
        }
    };


    iterator begin(){
        return iterator(m_head->next);
    }
    iterator end(){
        return iterator(m_head);
    }

    //construtor : cria uma lista vazia
    List(){
        m_head = new Node(0,nullptr,nullptr);
        m_head->next = m_head;
        m_head->prev = m_head;
        m_size = 0;

    }


    // construtor de copia: cria uma copia da lista dada
    List(const List& lst){
        m_head = new Node(0,nullptr,nullptr);
        m_head->next = m_head;
        m_head->prev = m_head;
        m_size = 0;
        Node *aux = lst.m_head->next;
        Node *auxMain = m_head;
        while(aux != lst.m_head){
            Node *newNode = new Node(aux->value,auxMain,m_head);
            auxMain->next = newNode;
            auxMain = auxMain->next;
            aux = aux->next;
        }
        m_head->prev = auxMain;
        m_size = lst.m_size;
    }
    // insere uma valor no final da lista --> O(1)
    void push_back(const int& v){
        Node *aux = new Node(v,m_head->prev,m_head);
        aux->prev->next = aux;
        m_head->prev = aux;
        m_size++;
    } 

    // insere uma valor no inicio da lista --> O(1)
    void push_back(const int& v){
        Node *aux = new Node(v, m_head, m_head->next);
        m_head->next->prev = aux;
        m_head->next = aux;
        m_size++;

    }

    // remover uma valor no final da lista --> O(1)
    void pop_back(){
        if(m_size != 0){
            Node *aux = m_head->prev;
            aux->prev->next = m_head;
            m_head->prev = aux->prev;
            delete aux;
            m_size--;
        }


    } 
};

#endif /* E5E37CCE_AA5B_4B44_AA4E_48938CD49EC9 */
