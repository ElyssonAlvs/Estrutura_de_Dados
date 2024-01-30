/**
 * Arquivo List.cpp
 * Elysson A.Lacerda
 * Gustavo A.Monteiro
 */
#ifndef INC_01_LISTAENCADEADA_LIST_H
#define INC_01_LISTAENCADEADA_LIST_H

#include <ostream>

struct node
{
	int value;
	node* prev;
	node* next;

	node(const int value, node* prev, node* next) {
		this->prev = prev;
		this->value = value;
		this->next = next;
	}
};

class List
{
	friend std::ostream& operator<<(std::ostream& os, const List& list);
private:
	int size_{ 0 };
	node* head_{ nullptr };
	node* tail_{ nullptr };
public:
	List();
	List(const List& lst);
	List(const int vet[], const int n);

	bool empty() const;
	int size() const;
	void push_back(const int& value);
	void push_front(const int& value);
	void pop_back();
	void pop_front();
	void clear();
	int operator[](const int value) const;

	void bubble_sort() const;
	void insertion_sort() const;
	void selection_sort() const;
	void merge_sort() const;
	void quick_sort() const;
	void cocktail_sort() const;

	~List();
};

#endif //INC_01_LISTAENCADEADA_LIST_H
