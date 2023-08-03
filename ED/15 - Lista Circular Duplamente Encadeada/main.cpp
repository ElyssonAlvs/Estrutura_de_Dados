#include <iostream>
#include "List.h"

using namespace std;

int main(){
    List lst;

    for(int i = 1; i <= 9;++i){
        lst.push_back(i);
    }
    auto it = lst.begin();
    auto it_end = lst.end();
    while(it != it_end){
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
}