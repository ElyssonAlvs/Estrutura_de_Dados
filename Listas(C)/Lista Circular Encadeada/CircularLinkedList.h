#pragma once

#include <stdio.h>
#include <stdlib.h>

struct cel {
	int conteudo;
	struct cel* seguinte;
};

typedef struct cel celula;

celula* nova_lista() {
	celula* lista;
	lista = (celula*)malloc(sizeof(celula));
	lista->seguinte = lista;
	return lista;
}

celula* criar_celula(int value) {
	celula* nova_celula;
	nova_celula = (celula*)malloc(sizeof(celula));
	nova_celula->conteudo = value;
	nova_celula->seguinte = NULL;
	return nova_celula;
}

void inserir_inicio(int value, celula* lista) {
	celula* nova_celula = criar_celula(value);
	nova_celula->seguinte = lista->seguinte;
	lista->seguinte = nova_celula;
}

void inserir_fim(int value, celula* lista) {
	celula* nova_celula = criar_celula(value);
	celula* atual = lista;
	while (atual->seguinte != lista) {
		atual = atual->seguinte;
	}
	atual->seguinte = nova_celula;
	nova_celula->seguinte = lista;
}

int remover_inicio(celula* lista) {
	if (lista->seguinte == lista) {
		return 0;
	}
	else {
		celula* lixo = lista->seguinte;
		lista->seguinte = lixo->seguinte;
		free(lixo);
		return 1;
	}
}

int remover_fim(celula* lista) {
	if (lista->seguinte == lista) {
		return 0;
	}
	else {
		celula* atual = lista;
		while (atual->seguinte->seguinte != lista) {
			atual = atual->seguinte;
		}
		celula* lixo = atual->seguinte;
		atual->seguinte = lista;
		free(lixo);
		return 1;
	}
}

int  limpar_lista(celula* lista) {
	if (lista->seguinte == lista) {
		return 0;
	}
	else {
		celula* atual = lista->seguinte;
		while (atual != lista) {
			celula* lixo = atual;
			atual = atual->seguinte;
			free(lixo);
		}
		lista->seguinte = lista;
		return 1;
	}
}

void imprimir_lista(celula* lista) {
	if (lista->seguinte == lista) {
		printf("Lista vazia!\n");
	}
	else {
		celula* celula_atual = lista->seguinte;
		while (celula_atual != lista) {
			printf("%d ", celula_atual->conteudo);
			celula_atual = celula_atual->seguinte;
		}
		printf("\n\n");
	}
}