#include <iostream>

using namespace std;
/*
void contador(int num){
    for(int i = 0; i <= num; i++){
        cout<<i<<endl;
    }
}
*/

void contador(int num, int cont = 0){
    cout<<cont<<endl;
    if(num > cont){
        // cont++ -> entra em loop pois o incremento é feito depois
        contador(num,++cont);
    }
}


int main(){
    contador(10);
    return 0;
}
