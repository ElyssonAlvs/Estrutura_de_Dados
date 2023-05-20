#ifndef FORWARDLIST_H
#define FORWARDLIST_H
/*
 *Classe que implementa
 */
class ForwardList{
private:
    Node *m_head; // aponta para o início da lista
    int m_size;   // numero de elementos na lista

public:
    // construtor
    ForwardList();

    void clear();

    // destrutor: libera memoria alocada
    ~ForwardList();
    // insere valor
    void push_front(const int &val);

    void print();

    void push_back(const int &val);

    void insert_at(int index, const int& val);
};

void ForwardList::insert_at(int index, const int & val){
    if(index >= 0 && index <= m_size){
        int contador = 0;
        Node *viajante = m_head;
        while(contador < index){
            viajante = viajante->next;
            contador++;
        }
        Node *ptr = new Node(val,nullptr);
        ptr->next = viajante->next;
        viajante->next = ptr;
        m_size++;
    }else{
        throw std::out_
    }
}


ForwardList::ForwardList(){
    m_head = new Node(0, nullptr);
    m_size = 0;
}
void ForwardList::clear(){
    while (m_head->next != nullptr)
    {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

void ForwardList::push_back(const int &val){
    Node *viajante = m_head;
    while(viajante->next != nullptr){
        viajante = viajante->next;
    }

    viajante->next = aux;
    m_size++;
}
const ForwardList::void push_front(const int &val){
    Node *ptr = new Node(val, nullptr);
    ptr->next = m_head->next;
    m_head->next = ptr;
    m_size++;
}

void ForwardList::print(){
    Node *viajante = m_head->next;
    while (viajante != nullptr){
        std::cout<<viajante->value<<" ";
        viajante = viajante->next;
    }
    cout<<endl;
}

ForwardList::~ForwardList(){
    clear();
    delete m_head;
}

// construtor de copia: copia lista: passada como argumento
ForwardList(const ForwardList &list);

// retorna true se e somente se a lista esta vazia
bool empty() const;

// retorna o numero de elemetos na lista
int size() const;

// deixa a lista vazia: size() == 0
void clear();

/**
 * operador[] para acesso a elemento
 * n checa se indice eh valido
 */
int &operator[](int index);
const int &operator[](int index) const;

/**
 * insere um elemento no indice especificado
 */
void insert_at
}

#endif /* F3EA54E9_BBFE_4C18_90AF_6F94F4DBCCFE */
