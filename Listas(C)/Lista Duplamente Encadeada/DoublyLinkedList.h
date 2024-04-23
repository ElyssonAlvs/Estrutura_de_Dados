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

int inserir_inicio(int value, list* lista) {
	if (lista == NULL) {
		printf("Fatal error: Lista inválida\n\n");
		return 0;
	}
	node* novo_node = criar_node(value);
	if (novo_node == NULL) {
		printf("Fatal error: Erro ao criar novo node\n\n");
		return 0;
	}
	if (lista->inicio->seguinte == NULL 
		&& lista->fim->anterior == NULL) {
		lista->inicio->seguinte = novo_node;
		lista->fim->anterior = novo_node;
		return 1;
	}
	else {
		novo_node->seguinte = lista->inicio->seguinte;
		lista->inicio->seguinte->anterior = novo_node;
		lista->inicio->seguinte = novo_node;
		return 1;
	}
}

int inserir_fim(int value, list* lista) {
	if (lista == NULL) {
		printf("Fatal error: Lista inválida\n\n");
		return 0;
	}
	node* novo_node = criar_node(value);
	if (novo_node == NULL) {
		printf("Fatal error: Erro ao criar novo node\n\n");
		return 0;
	}
	if (lista->inicio->seguinte == NULL && lista->fim->anterior == NULL) {
		lista->fim->anterior = novo_node;
		lista->inicio->seguinte = novo_node;
		return 1;
	}
	else {
		novo_node->anterior = lista->fim->anterior;
		lista->fim->anterior->seguinte = novo_node;
		lista->fim->anterior = novo_node;
		return 1;
	}
}

int remover_inicio(list* lista) {
	if (lista == NULL) {
		printf("Fatal error: Lista inválida\n\n");
		return 0;
	}
	if (lista->inicio->seguinte == NULL 
		&& lista->fim->anterior == NULL) {
		printf("Warning: Lista vazia!\n\n");
		return 0;
	}
	if ((lista->inicio->seguinte && lista->fim->anterior)
		&& lista->inicio->seguinte == lista->fim->anterior) {
		node* node_lixo = lista->inicio->seguinte;
		lista->inicio->seguinte = NULL;
		lista->fim->anterior = NULL;
		free(node_lixo);
		return 1;
	}
	else {
		node* node_lixo = lista->inicio->seguinte;
		lista->inicio->seguinte = node_lixo->seguinte;
		lista->inicio->seguinte->anterior = NULL;
		free(node_lixo);
		return 1;
	}
}

int remover_fim(list* lista) {
	if (lista == NULL) {
		printf("Fatal error: Lista inválida\n\n");
		return 0;
	}
	if (lista->inicio->seguinte == NULL
		&& lista->fim->anterior == NULL) {
		printf("Warning: Lista vazia!\n\n");
		return 0;
	}
	if ((lista->inicio->seguinte && lista->fim->anterior)
		&& lista->inicio->seguinte == lista->fim->anterior) {
		node* node_lixo = lista->fim->anterior;
		lista->inicio->seguinte = NULL;
		lista->fim->anterior = NULL;
		free(node_lixo);
		return 1;
	}
	else {
		node* node_lixo = lista->fim->anterior;
		lista->fim->anterior = node_lixo->anterior;
		lista->fim->anterior->seguinte = NULL;
		free(node_lixo);
		return 1;
	}
}

void limpar_lista(list* lista) {
	while (remover_inicio(lista));
}

void imprimir_lista_inicio(list* lista) {
	if (lista == NULL) {
		printf("Fatal error: Lista inválida\n\n");
		return;
	}
	node* node_atual = lista->inicio->seguinte;
	printf("Lista: ");
	while (node_atual != NULL) {
		printf("%d ", node_atual->conteudo);
		node_atual = node_atual->seguinte;
	}
	printf("\n\n");
}

void imprimir_lista_fim(list* lista) {
	if (lista == NULL) {
		printf("Fatal error: Lista inválida\n\n");
		return;
	}
	node* node_atual = lista->fim->anterior;
	printf("Lista: ");
	while (node_atual != NULL) {
		printf("%d ", node_atual->conteudo);
		node_atual = node_atual->anterior;
	}
	printf("\n\n");
}