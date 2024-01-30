#include <iostream>
#include "list.h"
#include <chrono>

void testa_algoritmoBubblesort(const List& lst)
{
    auto start = std::chrono::steady_clock::now();
    lst; // Cria uma cópia da lista se necessário
    lst.bubble_sort();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout <<"\n \n \n Bubblesort: " << duration.count() << " microssegundos \n \n \n" << std::endl;
}
void testa_algoritmoQuicksort(const List& lst)
{
    auto start = std::chrono::steady_clock::now();
    lst; // Cria uma cópia da lista se necessário
    lst.quick_sort();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout <<"\n \n \n Quicksort: " << duration.count() << " microssegundos \n \n \n" << std::endl;
}

void testa_algoritmoMergesort(const List& lst)
{
    auto start = std::chrono::steady_clock::now();
    lst; // Cria uma cópia da lista se necessário
    lst.merge_sort();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout <<"\n \n \n Mergesort: " << duration.count() << " microssegundos \n \n \n" << std::endl;
}

void testa_algoritmoSelectionSort(const List& lst)
{
    auto start = std::chrono::steady_clock::now();
    lst; // Cria uma cópia da lista se necessário
    lst.selection_sort();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout <<"\n \n \n Selection Sort: " << duration.count() << " microssegundos \n \n \n" << std::endl;
}

void testa_algoritmoInsertionSort(const List& lst)
{
    auto start = std::chrono::steady_clock::now();
    lst; // Cria uma cópia da lista se necessário
    lst.insertion_sort();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout <<"\n \n \n Insertion Sort: " << duration.count() << " microssegundos \n \n \n" << std::endl;
}

int main()
{
    List lst;
    const int tamanho {99000};
    for (int i = 0; i < tamanho; i++){
      lst.push_back(rand() % 99000);
    }

    //testa_algoritmoBubblesort(lst);
    testa_algoritmoQuicksort(lst);
    //testa_algoritmoMergesort(lst);
    //testa_algoritmoSelectionSort(lst);
    //testa_algoritmoInsertionSort(lst);


}