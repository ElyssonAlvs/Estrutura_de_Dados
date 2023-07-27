#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include "Node.h"

template <typename T>
class Stack{
    private:
        Node<T> *m_top; // ponteiro para o topo da pilha
        int m_size;

    public:
        // Construtor : cria pilha vazia
        Stack(){
            m_top = nullptr;
            m_size = 0;
        
        }
        // verificar se a pilha está vazia
        bool empty(){
            return m_top == nullptr;
        }
        // Retorna o tamanho atual
        int size(){
            return m_size;
        }
        /**
         * Retorna o valor do elemento no topo se existir
         * se pilha for vazia, lança uma exceção
        */
       T& top(){
            if(empty()){
                throw std::out_of_range("Stack underflow");
            }
            return m_top->value;
       }
       // Inserir na pilha
       void push(const T& val){
            // ponteiro aux aponta para m_top
            Node<T> *aux = new Node(val, m_top);
            // m_top aponta para aux
            m_top = aux;
            m_size++;
       }
       // Remover o próximo da pilha
       void pop(){
            if(m_size != 0){
                Node<T> *aux = m_top;
                m_top = m_top->next;
                aux->next = nullptr;
                delete aux;
                m_size--;
            }
       }
       // Denstrutor
       ~Stack(){
            delete m_top;
       }
};

#endif 
