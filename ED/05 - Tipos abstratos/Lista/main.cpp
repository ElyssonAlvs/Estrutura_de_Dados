#include<iostream>
#include "ForwardList.h"

using namespace std;

int main(){
    ForwardList lista;

    for(int i = 3; i <= 8; i++){
        lista.push_back(i);
    }

    lista.print();
}




