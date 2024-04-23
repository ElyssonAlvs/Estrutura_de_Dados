#pragma once

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int conteudo;
	struct Node* anterior;
	struct Node* seguinte;
};

typedef struct Node node;

struct List {
	node* inicio;
	node* fim;
};

typedef struct List list;

node* criar_node(int value) {
	node* novo_node = (node*)malloc(sizeof(node));
	novo_node->anterior = NULL;
	novo_node->conteudo = value;
	novo_node->seguinte = NULL;
	return novo_node;
}

list* criar_lista() {
	list* nova_list = (list*)malloc(sizeof(list));
	if (nova_list == NULL) {
		printf("Fatal error: Erro ao criar lista\n\n");
		return NULL;
	}
	nova_list->inicio = (node*)malloc(sizeof(node));
	if (nova_list->inicio == NULL) {
		printf("Fatal error: Erro ao inicializar lista\n\n");
		return NULL;
	}
	nova_list->fim = (node*)malloc(sizeof(node));
	if (nova_list->fim == NULL) {
		printf("Fatal error: Erro ao inicializa lista\n\n");
		return NULL;
	}
	nova_list->inicio->anterior = NULL;
	nova_list->inicio->seguinte = NULL;
	nova_list->fim->anterior = NULL;
	nova_list->fim->seguinte = NULL;
	return nova_list;
}

void atualizar_ponteiros(node* a, node* b, node* novo_node) {
	a->seguinte = novo_node;
	b->anterior = novo_node;
	novo_node->anterior = a;
	novo_node->seguinte = b;
}

int inserir_inicio(int value, list* lista) {
	if (lista == NULL) {
		printf("Error: Lista Nula!\n");
		return 0;
	}
	node* novo_node = criar_node(value);
	if (novo_node == NULL) {
		printf("Error: Node Nulo!\n");
		return 0;
	}
	if (lista->inicio->seguinte == NULL 
		&& lista->fim->anterior == NULL) {
		lista->inicio->seguinte = novo_node;
		lista->fim->anterior = novo_node;
		atualizar_ponteiros(novo_node, novo_node, novo_node);
		return 1;
	}
	else if ((lista->inicio->seguinte && lista->fim->anterior) && 
		lista->inicio->seguinte == lista->fim->anterior) {
		atualizar_ponteiros(lista->inicio->seguinte, lista->fim->anterior, novo_node);
		lista->inicio->seguinte = novo_node;
		return 1;
	}
	else {
		atualizar_ponteiros(lista->fim->anterior, lista->inicio->seguinte, novo_node);
		lista->inicio->seguinte = novo_node;
		return 1;
	}
}

int inserir_fim(int value, list* lista) {
	if (lista == NULL) {
		printf("Error: Lista Nula!\n");
		return 0;
	}
	node* novo_node = criar_node(value);
	if (novo_node == NULL) {
		printf("Error: Node Nulo!\n");
		return 0;
	}
	if (lista->inicio->seguinte == NULL
		&& lista->fim->anterior == NULL) {
		lista->inicio->seguinte = novo_node;
		lista->fim->anterior = novo_node;
		atualizar_ponteiros(novo_node, novo_node, novo_node);
		return 1;
	}
	else if ((lista->inicio->seguinte && lista->fim->anterior) &&
		lista->inicio->seguinte == lista->fim->anterior) {
		atualizar_ponteiros(lista->fim->anterior, lista->inicio->seguinte, novo_node);
		lista->fim->anterior = novo_node;
		return 1;
	}
	else {
		atualizar_ponteiros(lista->fim->anterior, lista->inicio->seguinte, novo_node);
		lista->fim->anterior = novo_node;
		return 1;
	}
}

int remover_inicio(list* lista) {
	if (lista == NULL) {
		printf("Error: Lista Nula!\n");
		return 0;
	}
	if (lista->inicio->seguinte == NULL && lista->fim->anterior == NULL) {
		printf("Lista Vazia!\n\n");
		return 0;
	}
	node* lixo = lista->inicio->seguinte;
	if (lista->inicio->seguinte && lista->fim->anterior &&
		(lista->inicio->seguinte == lista->fim->anterior)) {
		lista->inicio->seguinte = NULL;
		lista->fim->anterior = NULL;
		free(lixo);
		return 1;
	}
	else {
		lixo->seguinte->anterior = lista->fim->anterior;
		lista->fim->anterior->seguinte = lixo->seguinte;
		lista->inicio->seguinte = lixo->seguinte;
		free(lixo);
		return 1;
	}
}

int remover_fim(list* lista) {
	if (lista == NULL) {
		printf("Error: Lista Nula!\n");
		return 0;
	}
	if (lista->inicio->seguinte == NULL && lista->fim->anterior == NULL) {
		printf("Lista Vazia!\n\n");
		return 0;
	}
	node* lixo = lista->fim->anterior;
	if (lista->inicio->seguinte && lista->fim->anterior &&
		(lista->inicio->seguinte == lista->fim->anterior)) {
		lista->inicio->seguinte = NULL;
		lista->fim->anterior = NULL;
		free(lixo);
		return 1;
	}
	else {
		lixo->seguinte->anterior = lista->inicio->seguinte;
		lista->inicio->seguinte->anterior = lixo->anterior;
		lista->fim->anterior = lixo->anterior;
		free(lixo);
		return 1;
	}
}

void imprimir_inicio(list* lista) {
	if (lista == NULL) {
		printf("Error: Lista Nula!\n");
		return;
	}
	if (lista->inicio->seguinte && lista->fim->anterior) {
		node* atual = lista->inicio->seguinte;
		do {
			printf("%d ", atual->conteudo);
			atual = atual->seguinte;
		}
		while (atual != lista->fim->anterior->seguinte);
		printf("\n\n");
	}
	else {
		printf("Lista vazia!\n\n");
	}
}

void imprimir_fim(list* lista) {
	if (lista == NULL) {
		printf("Error: Lista Nula!\n");
		return;
	}
	if (lista->inicio->seguinte && lista->fim->anterior) {
		node* atual = lista->fim->anterior;
		do {
			printf("%d ", atual->conteudo);
			atual = atual->anterior;
		}
		while (atual != lista->inicio->seguinte->anterior);
		printf("\n\n");
	}
	else {
		printf("Lista vazia!\n\n");
	}
}

void limpar_lista(list* lista) {
	while (remover_inicio(lista));
}

