#include <iostream>
#include <string>
#include "Node.h"
#include "CircularList.h"
#include <sstream>

/**
 * Construtor : cria uma lista circular
 * vazia com no sentinela
*/
CircularList::CircularList(){
    /*
    Node *aux = new Node(-1, nullptr);
    // vai apontar pra ele mesmo
    aux->next = aux;
    // aponta para a cabeca do no
    m_head = aux;
    */

   /**
    * variavel m_head recebe o endereco, apenas para 
    * apontar para ele mesmo, em forma circular
   */
   m_head = new Node(-1, nullptr);
   m_head->next = m_head;
}

// retorna se a lista esta vazia
bool CircularList::empty() const{
    /*
    if(m_head->next == m_head){
        return true;
    }else{
        return false;
    }
    */
   return m_head->next == m_head;
}

// adiciona um elemento ao final da lista
void CircularList::push_back(const int& val){
    Node *aux = m_head;
    while(aux->next != m_head){
        // aponta para o proximo da lista
        aux = aux->next;
    }
    // aponta para o proximo e incrementa no tamanho da lista
    aux->next = new Node(val,m_head);
    m_size++;
}

// remove um elemento do final da lista, se ele existir
// caso contrario, nao faz nada
void CircularList::pop_back(){
    if(m_head->next != m_head){
        Node *aux = m_head;
        while(aux->next->next != m_head){
            aux = aux->next;
        }
        delete aux->next;
        aux->next = m_head;
        m_size--;
    }
}

// sobrecarga do operador[] 
// possibilita acessar diretamente o elemento no indice 'index'
int& CircularList::operator[](int index){
    if(index >= 0 && index <= m_size - 1){
        int contador{0};
        Node *aux = m_head->next;
        while(contador < index){
            aux = aux->next;
            contador++;
        }
        return aux->value;
    }else{
        throw std::out_of_range("fora do intervalo");
    }
}

// versao const da sobrecarga do operador[] 
// possibilita acessar diretamente o elemento no indice 'index' 
const int& CircularList::operator[](int index) const{
    if(index >= 0 && index <= m_size - 1){
        int contador{0};
        Node *aux = m_head->next;
        while(contador < index){
            aux = aux->next;
            contador++;
        }
        return aux->value;
    }else{
        throw std::out_of_range("fora do intervalo");
    }
}

// deixa a lista vazia, liberando todos os nos
void CircularList::clear(){
    if(m_head->next != m_head){
        Node *aux = m_head->next;
        while(aux != m_head){
            Node *del = aux;
            aux = aux->next;
            delete del;
        }
        m_head->next = m_head;
        m_size = 0;
    }
}

// destrutor
CircularList::~CircularList(){
    clear();
    delete m_head;
}

// retorna os elementos no formato de string
std::string CircularList::toString() const{
    std::stringstream ss;
    Node *aux = m_head->next;
    while(aux != m_head){
        ss<<aux->value<<" ";
        aux = aux->next;
    }
    std::string str = ss.str();
    str.pop_back();
    return str;
    /*
    // str() retorna o conteúdo da stringstream como uma string
    return ss.str();
    */
}
std::ostream& operator<<(std::ostream& out, CircularList& lst){
    Node *aux = lst.m_head->next;
    while(aux != lst.m_head){
        out<<aux->value<<" ";
        aux = aux->next;
    }
    return out;
}

// adiciona um elemento no inicio da lista
void CircularList::push_front(const int& val){
    
}