/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/
// Concatena a lista atual com a lista lst.
// A lista lst eh modificada apos essa operacao.
// Por exemplo, seja l1 = [ 1 2 3 4 ] e l2 = [ 7 9 8 ]
// Após fazer l1.concat(l2) você deve obter
// l1 = [ 1 2 3 4 7 9 8] e l2 = [ ]
// Restricao: estar proibido usar funcoes auxiliares para resolver esta questao,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::concat(ForwardList& lst) {
    Node* atual = this->m_head;
    while(atual->next != nullptr){
        atual = atual->next;
    }
    while(lst.m_head->next != nullptr){
        atual->next = new Node(lst.m_head->next->value, nullptr);
        atual = atual->next;
        Node* temp = lst.m_head->next;
        lst.m_head->next = temp->next;
        delete temp;
    }
}

// Remove da lista todas as ocorrencias do Item val.
// Se a lista estiver vazia, esta funcao nao faz nada.
// Restricao: Esta funcao deve ter complexidade O(n) no pior caso.
// Restricao: estar proibido usar funcoes auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados 
void ForwardList::remove(const Item& val) {
    if(this->m_head->next != nullptr){
        Node* aux = this->m_head;
        while(aux->next != nullptr){
            if(aux->next->value == val){
                Node* temp = aux->next->next;
                delete aux->next;
                aux->next = temp;
            }else{
                aux = aux->next;
            }
        }
    }
}

// Devolve um ponteiro para uma copia desta lista.
// Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
// Esta funcao deve ter complexidade O(n) no pior caso
// Restricao: estar proibido usar funcoes auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
ForwardList* ForwardList::clone() {
    ForwardList* cop = new ForwardList();
    Node* atual = this->m_head;
    Node* aux = cop->m_head;

    while(atual->next != nullptr){
        aux->next = new Node(atual->next->value,nullptr);
        aux = aux->next;
        atual = atual->next;
    }
    cop->m_size = this->m_size;
    return cop;
}

// Copia os elementos do vector vec para o final da lista.
// Esta funcao deve ter complexidade O(n) no pior caso
// Restricao: estar proibido usar funcoes auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::appendVector(const std::vector<Item>& vec) {
    Node* aux = this->m_head;
    while(aux->next != nullptr)
        aux = aux->next;
    for (int i = 0; i < vec.size(); i++) {
        aux->next = new Node(vec[i], nullptr);
        aux = aux->next;
    }
    this->m_size += vec.size();
}
// Troca o conteudo dessa lista pelo conteudo de lst. 
// Os tamanhos das listas podem diferir.
// Apos a chamada para esta funcao, os elementos nesta lista
// sao aqueles que estavam em lst antes da chamada, 
// e os elementos de lst sao aqueles que estavam nesta lista.
void ForwardList::swap(ForwardList& lst) {
    ForwardList temp {lst};
    
    int tempSize = this->m_size;
    this->m_size = temp.m_size;
    lst.m_size = tempSize;
    
    lst.m_head = this->m_head;
    this->m_head = temp.m_head;
}

// Determina se a lista lst, passada por parametro, eh igual
// a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho
// e o valor do k-esimo elemento da primeira lista eh igual ao
// k-esimo valor da segunda lista.
// Restricao: estar proibido usar funcoes auxiliares nesta questao,
// inclusive qualquer dos operadores sobrecarregados
bool ForwardList::equals(const ForwardList& lst) const {
    if(this->m_size != lst.m_size){
        return false;
    }
    Node* atual = this->m_head;
    Node* aux = lst.m_head;
    while(atual->next != nullptr){
        if(atual->next->value != aux->next->value){
            return false;
        }
        
        atual = atual->next;
        aux = aux->next;
    }
    
    return true;
}
// Inverte a ordem dos nos (o primeiro node passa a ser o ultimo, 
// o segundo passa a ser o penultimo, etc.)
// Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
// Voce pode criar ponteiros auxiliares (um numero constante deles),
// mas nao pode alocar novos nos.
// Repetindo: estar proibido chamar o operador new nesta questao.
// Restricao: Tambem nao eh permitido usar funções auxiliares nesta questao
void ForwardList::reverse() {
    Node* p = nullptr;
    Node* aux = this->m_head->next;
    Node* n = nullptr;
    while(aux!=nullptr){
        n = aux->next;
        aux->next = p;
        p = aux;
        aux = n;
    }
    this->m_head->next = p;
}

// retorna o elemento na posicao 'index'
// Se index < 0 ou index >= m_size então lance uma excecao std::range_error com a
// mensagem de erro "index out of range". Caso contrario retorne o elemento.
// Sera preciso incluir o cabecalho <stdexcept> para a excecao ser reconhecida
Item& ForwardList::get(int index) {
    if(index < 0 || index > this->m_size){
        throw std::range_error("index out of range");
    }
    Node *aux = this->m_head->next;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}
const Item& ForwardList::get(int index) const {
    if(index < 0 || index > this->m_size){
        throw std::range_error("index out of range");
    }
    Node *aux = this->m_head->next;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}
