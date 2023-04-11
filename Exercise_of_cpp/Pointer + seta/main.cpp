#include <iostream>

using namespace std;

typedef struct Estrutura{
    int x;
    int y;
} Estrutura;

int main(){
/*
    int a = 5;
    int *b;
    b = &a;
*/
    Estrutura minha_estrutura;

    minha_estrutura.x = 12;
    minha_estrutura.y = 15;

    Estrutura *pEstrutura = &minha_estrutura;

    cout << "minha_estrutura tem valor em x como " << (*pEstrutura).x << endl;

    cout << "minha_estrutura tem valor em y como " << (*pEstrutura).y << endl;

    return 0;
}
