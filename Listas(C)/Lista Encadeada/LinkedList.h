#pragma once

#include <stdio.h>
#include <malloc.h>

struct cel {
	int conteudo;
	struct cel* seguinte;
};

typedef struct cel celula;

/// <summary>
/// Função que cria um ponteiro para uma lista encadeada.
/// </summary>
/// <returns>Ponteiro para uma lista encadeada</returns>
celula* nova_lista() {
	celula* lista;
	lista = malloc(sizeof(celula));
	lista->seguinte = NULL;
	return lista;
}

/// <summary>
/// Função que cria uma nova celula
/// </summary>
/// <param name="value">Valor a ser armazenado na celula</param>
/// <returns>Ponteiro para uma nova celula</returns>
celula* nova_celula(int value) {
	celula* nova_celula;
	nova_celula = malloc(sizeof(celula));
	nova_celula->conteudo = value;
	nova_celula->seguinte = NULL;
	return nova_celula;
}

/// <summary>
/// Função que insere uma nova celula no início de uma lista.
/// </summary>
/// <param name="value">Valor a ser armazenado na nova celula</param>
/// <param name="lista">Lista em que a operação será executada</param>
void inserir_inicio(int value, celula* lista) {
	celula* novaCel = nova_celula(value);
	novaCel->seguinte = lista->seguinte;
	lista->seguinte = novaCel;
}

/// <summary>
/// Função que insere uma nova celula no fim de uma lista.
/// </summary>
/// <param name="value">Valor a ser armazenado na nova celula</param>
/// <param name="lista">Lista em que a operação será executada</param>
void inserir_fim(int value, celula* lista) {
	celula* novaCel = nova_celula(value);
	celula* atual = lista;
	while (atual->seguinte != NULL) {
		atual = atual->seguinte;
	}
	atual->seguinte = novaCel;
}
/// <summary>
/// Função que remove a celula que está no ínicio de uma lista
/// </summary>
/// <param name="lista">Lista em que a operação será executada</param>
/// <returns>Se a operação ocorreu com éxito, retorna 1. Senão, retorna 0</returns>
int remover_inicio(celula* lista) {
	if (lista->seguinte == NULL) {
		return 0;
	}
	else {
		celula* temporario = lista->seguinte;
		lista->seguinte = temporario->seguinte;
		free(temporario);
		return 1;
	}
}

/// <summary>
/// Função que remove a celula que está no fim da lista
/// </summary>
/// <param name="lista">Lista em que a operação será executada</param>
/// <returns>Se a operação ocorreu com éxito, retorna 1. Senão, retorna 0</returns>
int remover_fim(celula* lista) {
	if (lista->seguinte == NULL) {
		return 0;
	}
	else {
		celula* atual = lista;
		while (atual->seguinte->seguinte != NULL) {
			atual = atual->seguinte;
		}
		celula* temporario = atual->seguinte;
		atual->seguinte = NULL;
		free(temporario);
		return 1;
	}
}

/// <summary>
/// Função que imprime os valores de uma lista
/// </summary>
/// <param name="lista">Lista em que a operação será executada</param>
void imprimir_lista(celula* lista) {
	if (lista->seguinte == NULL) {
		printf("Lista vazia!\n\n");
	}
	else {
		celula* atual = lista->seguinte;
		printf("Lista: ");
		while (atual != NULL) {
			printf("%d ", atual->conteudo);
			atual = atual->seguinte;
		}
		printf("\n\n");
	}
}

/// <summary>
/// Função que limpa todos os elementos da lista
/// </summary>
/// <param name="lista">Lista em que a operação será executada</param>
/// <returns>Se a operação ocorreu com éxito, retorna 1. Senão, retorna 0</returns>
int limpar_lista(celula* lista) {
	if (lista == NULL) {
		return 0;
	}
	else {
		celula* atual = lista;
		while (atual != NULL) {
			celula* temporario = atual;
			atual = atual->seguinte;
			free(temporario);
		}
		return 1;
	}
}