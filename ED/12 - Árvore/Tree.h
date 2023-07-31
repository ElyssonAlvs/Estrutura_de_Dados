#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Node.h"

class Tree
{
private:
    Node *root{nullptr}; // ponteiro para a raiz da árvore

    /**
     * Funcao recrusiva que recebe um ponteito para uma raiz
     * de arvore e libera todos os nos que estiverem nessa arvore,
     *  deixando ela vazia novemente
     */
    Node *clear(Node *node)
    {
        // caso de parada seria o root ser nullptr
        if (node != nullptr)
        {                                     // caso geral
            node->left = clear(node->left);   // resultado da limpeza sera nullptr
            node->right = clear(node->right); // resultado da limpeza sera nullptr
            delete node;
            return nullptr;
        }
    }

    // Funcao privada: imprime as chaves em preordem
    void preordem(Node *node)
    {
        if (node != nullptr)
        {
            std::cout << node->key << " ";
            preordem(node->left);
            preordem(node->right);
        }
    }
    // funcao privada que retorna true se e somente se a arvore contem essa chave passada como parametro
    bool contains(Node *node, const int &key)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->key == key)
        {
            return true;
        }
        else
        {
            return contains(node->left, key) ||
                   contains(node->rigt, key);
        }
    }

public:
    // Construtor default : cria uma árvore vazia
    Tree() = default;
    /**
     * Construtor 2 : cria uma árvore a partir de outras duas e transfere as raizes
     * das subarvores passadas como paramtreo para si mesma
     * */

    Tree(const int &key, Tree &tleft, Tree &tright)
    {
        root = new Node(key, tleft.root, tright.root);
        tleft.root = nullptr;
        tright.root = nullptr;
    }
    ~Tree()
    {
        root = clear(root);
    }
    // retorna true se e somente se a arvore for vazia
    bool empty()
    {
        return root == nullptr;
    }
    // funcao publica que imprime as chaves
    void preordem()
    {
        preordem(root);
        std::cout << std::endl;
    }
    // retorna true se e somente se a arvore contem a chave passada como parametro
    bool contains(const int &key)
    {
        return contains(root, key);
    }
}

#endif
