#include "LinkedList.h" // Substitua pela lista de teste

int main() {
    // Cria uma nova lista
    celula* minha_lista = nova_lista();

    // Insere valores no início da lista
    inserir_inicio(10, minha_lista);
    inserir_inicio(20, minha_lista);

    // Insere valores no fim da lista
    inserir_fim(30, minha_lista);
    inserir_fim(40, minha_lista);

    // Imprime a lista
    imprimir_lista(minha_lista);

    // Remove o primeiro elemento da lista
    remover_inicio(minha_lista);

    // Imprime a lista após a remoção
    imprimir_lista(minha_lista);

    // Remove o último elemento da lista
    remover_fim(minha_lista);

    // Imprime a lista após a remoção
    imprimir_lista(minha_lista);

    // Limpa a lista
    limpar_lista(minha_lista);

    return 0;
}