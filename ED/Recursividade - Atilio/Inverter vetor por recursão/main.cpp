#include <iostream>

using namespace std;

void inverte(int v[], int ini, int fim){
    if(ini < fim){
        int aux = v[ini];
        v[ini] = v[fim];
        v[fim] = aux;
        inverte(v, ini + 1, fim - 1);
    }
}

int main(){
    int vec[9] = {1,2,3,4,5,6,7,8,9};
    for(int i : vec){
        cout << i << " ";
    }
    inverte(vec, 0, sizeof(vec) / sizeof(vec[0]) - 1);
    cout << endl;
    for(int i : vec){
        cout << i << " ";
    }
    
    return 0;
}