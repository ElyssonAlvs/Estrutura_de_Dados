#ifndef LISTA_H
#define LISTA_H

using namespace std;
// Classe No
template<class T>
class No{
    private:
        T valor;
        No* prox;
    public:
        // Construtor
        No(T valor){
            this->valor = valor;
            this->prox = nullptr;
        }
        // Retornar o valor 
        T obterValor(){
            return valor;
        }
        // Obter proximo nó
        No* obterProx(){
            return prox;
        }
        // Nó apontar pra o próximo
        void setProx(No* p){
            prox = p;
        }
};
template<class T>
class Lista{
    private:
        No<T>* cabeca; // primeiro da lista
        No<T>* cauda; // último elemento 
    public:
        // Construtores
        Lista(){
            cabeca = nullptr;
            cauda = nullptr;
        }
        Lista(T valor){
            cabeca = new No<T>(valor);
            cauda = cabeca;
        }
        // Denstrutor
        ~Lista(){
            delete cabeca;
        }
        // Imprimir a Lista
        void monstrar(){
            cout<<"\nImprimindo todos os elementos...\n";
            // primeiro elemento
            No<T>* c = cabeca;

            if(vazia()){
                cout<<"\nA lista NAO possui elementos!\n";
            }else{
                while(c){
                    cout<<c->obterValor()<<endl;
                    // receber a referência para o próximo nó
                    c = c->obterProx();
                }
                cout<<endl;
            }
        }

        bool vazia(){
            return cabeca == nullptr;
        }
        // Inserir elemento no começo da lista
        void inserir_inicio(T valor){
            // cria um novo nó
            No<T>* novo_no = new No<T>(valor);

            novo_no->setProx(cabeca);
            // o novo nó seja a cabeça
            cabeca = novo_no;
        }
        // Inserir elemento no final da lista
        void inserir_final(T valor){
            No<T>* novo_no = new No<T>(valor);
            
            if(vazia()){
                cabeca = novo_no;
                cauda = novo_no;
            }else{
                cauda->setProx(novo_no);
                cauda = novo_no;
            }
        }
        // Verificar tamanho da Lista
        int tamanho(){
            if(vazia()){
                return 0;
            }
            No<T>* c = cabeca;
            int tam = 0;
            do{
                c = c->obterProx();
                tam++;
            }while(c);

            return tam;
        }
        // Percorrer a Lista
        bool existe(int valor){
            No<T>* c = cabeca;
            while(c){
                if(c->obterValor() == valor){
                    return true;
                }
                c = c->obterProx();
            }
            return false;
        }
        // Remover elemento do final
        void remover(){
            if(!vazia()){
                // se houver só 1 elemento
                if(cabeca->obterProx() == nullptr){
                    cabeca = nullptr;
                }else if(cabeca->obterProx()->obterProx() == nullptr){ // tem 2 elementos
                    cabeca->setProx(nullptr);
                }else{ // mais de 2 elementos
                    No<T>* ant_ant = cabeca;
                    No<T>* ant = cabeca->obterProx();
                    No<T>* corrente = cabeca->obterProx()->obterProx();

                    while(corrente){
                        No<T>* aux = ant;
                        ant = corrente;
                        ant_ant = aux;
                        corrente = corrente->obterProx();
                    }
                    delete ant_ant->obterProx();
                    ant_ant->setProx(nullptr);
                    cauda = ant_ant;
                }
            }
        }
};

#endif