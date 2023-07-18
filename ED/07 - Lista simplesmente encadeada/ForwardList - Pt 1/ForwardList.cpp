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
     * Funcoes adicionais - Parte 1
     ***********************************************************/

    // retorna uma referencia para o primeiro elemento na lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    Item& ForwardList::front() {
        return this->m_head->next->value;
    }
    const Item& ForwardList::front() const {
        return this->m_head->next->value;
    }

    // insere um elemento no inicio da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void ForwardList::push_front(const Item& val) {
        this->m_head->next = new Node(val, this->m_head->next);
        this->m_size++;
    }

    // deleta o primeiro elemento da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void ForwardList::pop_front() {
        if(this->m_head->next != nullptr){
            Node* aux = this->m_head->next->next;
            delete this->m_head->next;
            this->m_head->next = aux;
        }
    }

    // retorna uma referencia para o ultimo elemento na lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    Item& ForwardList::back() {
        Node* aux = this->m_head->next;
        while(aux->next != nullptr){
            aux = aux->next;
        }
        return aux->value;
    }
    const Item& ForwardList::back() const {
        Node* aux = this->m_head;
        while(aux->next != nullptr){
            aux = aux->next;
        }
        return aux->value;
    }

    // insere um elemento no final da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void ForwardList::push_back(const Item& val) {
    Node *aux = this->m_head;
    while(aux->next != nullptr){
        aux = aux->next;
    }
    aux->next = new Node(val,nullptr);
    m_size++;
    }


    // deleta o ultimo elemento da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void ForwardList::pop_back() {
        Node *aux = m_head;
        while(aux->next->next != nullptr){
            aux = aux->next;
        }
        delete aux->next;
        aux->next = nullptr;
        this->m_size--;
    }