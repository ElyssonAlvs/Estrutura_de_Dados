/**
 * Arquivo List.cpp
 * Elysson A.Lacerda
 * Gustavo A.Monteiro
 */
#include "List.h"

#include <functional>
using std::function;

#include <iostream>
using std::swap;

List::List()
{
	this->head_ = new node(0, nullptr, nullptr);
	this->tail_ = new node(0, nullptr, nullptr);
}

List::List(const List &lst)
{
	clear();
	node *current = lst.head_->next;
	while (current)
	{
		push_back(current->value);
		current = current->next;
	}
}

List::List(const int vet[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		push_back(vet[i]);
	}
}

bool List::empty() const { return size_ == 0; }

int List::size() const { return size_; }

void List::push_back(const int &value)
{
	const auto new_node = new node(value, nullptr, nullptr);
	if (size_ == 0)
	{
		head_->next = new_node;
		tail_->prev = new_node;
	}
	else
	{
		node *temp = tail_->prev;
		new_node->prev = temp;
		temp->next = new_node;
		tail_->prev = new_node;
	}
	size_++;
}

void List::push_front(const int &value)
{
	const auto new_node = new node(value, nullptr, nullptr);
	if (size_ == 0)
	{
		head_->next = new_node;
		tail_->prev = new_node;
	}
	else
	{
		node *temp = head_->next;
		new_node->next = temp;
		temp->prev = new_node;
		head_->next = new_node;
	}
	size_++;
}

void List::pop_back()
{
	const node *temp = tail_->prev;
	tail_->prev = temp->prev;
	tail_->prev->next = nullptr;
	delete temp;
	if (size_ == 1)
	{
		head_->next = nullptr;
	}
	size_--;
}

void List::pop_front()
{
	const node *temp = head_->next;
	head_->next = temp->next;
	head_->next->prev = nullptr;
	delete temp;
	if (size_ == 1)
	{
		tail_->prev = nullptr;
	}
	size_--;
}

void List::clear()
{
	node *current = head_->next;
	while (current)
	{
		const node *lixo = current;
		current = current->next;
		delete lixo;
	}
	head_->next = nullptr;
	tail_->prev = nullptr;
	size_ = 0;
}

int List::operator[](const int value) const
{
	node *current = head_->next;
	for (int i = 0; i < value; i++)
	{
		current = current->next;
	}
	return current->value;
}

void List::bubble_sort() const
{
	if (this->size_ < 2)
	{
		return;
	}

	for (node *current_a = head_->next; current_a; current_a = current_a->next)
	{
		for (node *current_b = current_a->next; current_b; current_b = current_b->next)
		{
			if (current_a->value > current_b->value)
			{
				swap(current_a->value, current_b->value);
			}
		}
	}
}

void List::insertion_sort() const
{
	if (size_ < 2)
	{
		return;
	}

	node *current_a = head_->next->next;
	while (current_a)
	{
		const int value = current_a->value;
		node *current_b = current_a->prev;
		while (current_b && current_b->value > value)
		{
			current_b->next->value = current_b->value;
			current_b = current_b->prev;
		}
		current_b ? current_b->next->value = value : head_->next->value = value;
		current_a = current_a->next;
	}
}

void List::selection_sort() const
{
	if (size_ < 2)
	{
		return;
	}

	node *current_a = head_->next;
	while (current_a)
	{
		node *min = current_a;

		node *current_b = current_a->next;
		while (current_b)
		{
			if (current_b->value < min->value)
			{
				min = current_b;
			}
			current_b = current_b->next;
		}
		swap(current_a->value, min->value);
		current_a = current_a->next;
	}
}

void List::merge_sort() const
{
	if (size_ < 2)
	{
		return;
	}

	List left_half;
	List right_half;

	const int half = size_ / 2;

	node *current = head_->next;
	for (int i = 0; i < half; i++)
	{
		left_half.push_back(current->value);
		current = current->next;
	}
	while (current)
	{
		right_half.push_back(current->value);
		current = current->next;
	}

	left_half.merge_sort();
	right_half.merge_sort();

	node *current_l = left_half.head_->next;
	node *current_r = right_half.head_->next;
	current = head_->next;

	while (current_l && current_r)
	{
		if (current_l->value <= current_r->value)
		{
			current->value = current_l->value;
			current_l = current_l->next;
		}
		else
		{
			current->value = current_r->value;
			current_r = current_r->next;
		}
		current = current->next;
	}

	while (current_l)
	{
		current->value = current_l->value;
		current_l = current_l->next;
		current = current->next;
	}

	while (current_r)
	{
		current->value = current_r->value;
		current_r = current_r->next;
		current = current->next;
	}
}
/**
 * 1. Primeiro, a função tenta quick_sort para o vetor inteiro.
 * 2. Se o os argumentos (inicio e fim das posições a serem ordenadas) passados forem diferentes, ele executa particion,
 * que pega um pivô e passa os elementos menores que o pivo para a esquerda e os maiores a direita. No final, retorna a posição do pivô.
 * 3. Recursivamente, ele ordena os elementos menores e maiores que o pivô.
 *
 * O motivo das lambdas:
 * 1. Primeiramente, para deixar mais modular, decidimos não colocar argumentos na função-membro.
 * 2. Para não criar funções privadas, decidimos usar as lambdas reprensentando as funções que seriam usadas no algoritmo.
 * 3. O algoritmo é o mesmo usado em sala.
 * 4. A primeira função pensada foi partition.
 * 5. A chamada feita a função-membro é apenas uma fachada para a real função - quick_sort_util.
 * 6. Declarar ela como uma function foi a forma mais fácil de usá-la.
 * 7. function serve para empacotar a função para o uso.
 */
void List::quick_sort() const
{
	function<void(node *, node *)> quick_sort_util = [&](node *start, node *end)
	{
		auto partition = [&](node *left, node *right)
		{
			const int pivot = right->value;

			node *i = left->prev;
			for (node *j = left; j != right; j = j->next)
			{
				if (j->value <= pivot)
				{
					i = i == nullptr ? left : i->next;
					swap(i->value, j->value);
				}
			}
			i = i == nullptr ? left : i->next;
			swap(i->value, right->value);
			return i;
		};

		if (end != nullptr && start != end && start != end->next)
		{
			const node *pivot = partition(start, end);
			quick_sort_util(start, pivot->prev);
			quick_sort_util(pivot->next, end);
		}
	};

	if (size_ < 2)
	{
		return;
	}

	quick_sort_util(head_->next, tail_->prev);
}

void List::cocktail_sort() const
{
	if (size_ < 2)
	{
		return;
	}

	bool swapped = true;
	node *first = head_->next;
	node *last = tail_->prev;

	while (swapped)
	{
		swapped = false;

		for (node *current_a = first; current_a != last; current_a = current_a->next)
		{
			if (current_a->value > current_a->next->value)
			{
				swap(current_a->value, current_a->next->value);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;

		last = last->prev;

		for (node *current_a = last->prev; current_a != first->prev; current_a = current_a->prev)
		{
			if (current_a->value > current_a->next->value)
			{
				swap(current_a->value, current_a->next->value);
				swapped = true;
			}
		}

		first = first->next;
	}
}

List::~List()
{
	node *current = head_->next;
	while (current)
	{
		const node *lixo = current;
		current = current->next;
		delete lixo;
	}
	delete head_;
	delete tail_;
}
