#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
    Tree emptyTree;
    Tree t1(10, emptyTree, emptyTree);
    Tree t2(20, emptyTree, emptyTree);
    Tree t3(2, t1, t2);
    Tree t4(7, t3, emptyTree);
    t4.preordem();

    cout<<t4.contains(7)<<endl;
}