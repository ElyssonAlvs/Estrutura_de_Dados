#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>
#include "Node.h"

/**
 * Classe que implementa uma fila (FIFO - first in, first out)
*/

template<typename T>

class Queue{
private:
    // É necessário, no momento da criação, escrever o tipo do "nó"

    Node<T>* m_head; // ponteiro para o primeiro elemento, do tipo T
    Node<T>* m_tail; // ponteiro para o último elemento, do tipo T
    int m_size; // número de elementos na fila

public:
    // Construtor default: cria fila vazia
    Queue();
    // Insere elemento na fila
    void push(const T& v);
    // Remove um elemento na fila
    void pop();
    // Retorna se fila está vazia
    bool empty();
    /*
     * Acessa o primeiro elemento da fila,
     * se a fila estiver vazia, lance uma out_of_range exception
     */ 
    T& front();
    /*
     * Acessa o último elemento da fila,
     * se a fila estiver vazia, lance uma out_of_range exception
     */
    T& back();
    // Retorna o número de elementos na fila
    int size();
    //Construtor de copia
    Queue(const Queue& q);
    // Sobrecarga do operador de atribuição
    Queue& operator=(const Queue& q);
    // Sobrecarga do operator ==
    bool operator==(const Queue& q);
    // Denstrutor
    ~Queue();

};

// Precisa especificar o tipo, sempre
template<typename T>
Queue<T>::Queue(){
    // Fila vazia
    m_head = m_tail = nullptr;
    m_size = 0;
}

template<typename T>
void Queue<T>::push(const T& v){
    Node<T> *aux = new Node<T>(v,nullptr);
    // Lista vazia
    if(m_size == 0){
        m_head = m_tail = aux;
    }else{
        // m_tail = m_tail->next = aux
        m_tail->next = aux;
        m_tail = aux;
    }
    m_size++;
}

template<typename T>
void Queue<T>::pop(){
    // Zero elementos
    if(m_size == 0){
        return;
    }
    // Temos pelo menos um elemento
    /**
     * Como o destrutor deleta do nó para frente
     * é necessário que o próximo do auxiliar aponte para nulo
     * evitando o delete em cascata
    */
    Node<T> *aux = m_head;
    // cabeça aponta para o próximo
    m_head = m_head->next;
    // próximo
    aux->next = nullptr;
    delete aux;
    m_size--;
    if(m_head == nullptr){
        m_tail = nullptr;
    }
}

template<typename T>
int Queue<T>::size(){
    return m_size;
}

template<typename T>
bool Queue<T>::empty(){
    return m_size == 0;
}

template<typename T>
T& Queue<T>::front(){
    if(m_size == 0){
        throw std::out_of_range("fila vazia");
    }else{
        return m_head->value;
    }
}

// Construtor de copia
template<typename T>
Queue<T>::Queue(const Queue& q){
    m_head = m_tail = nullptr;
    m_size = 0;
    Node<T>* aux = q.m_head;
    while(aux != nullptr){
        push(aux->value);
        aux = aux->next;    
    }
}
// Denstrutor
template<typename T>
Queue<T>::~Queue(){
    delete m_head;
}

template<typename T>
bool Queue<T>::operator==(const Queue &q)const{
    if(m_size != q.m_size){
        return false;
    }

    Node<T>* aux1 = q.m_head;
    Node<T>* aux2 = m_head;

    while(aux1 != nullptr){
        if(aux1->value != aux2->value){
            return false;
        }else{
            aux1 =  aux1->next;
            aux2 = aux2->next;
    }
    
}


#endif 
