#include <iostream>

using namespace std;
// Tipo estrutura criado com os os pontos x e y inteiros
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
    // declaração de estrutura do tipo struct(Estrutura)
    Estrutura minha_estrutura;

    minha_estrutura.x = 12;
    minha_estrutura.y = 15;

    // Ponteiro para a struct criada e apontar para o endereço da minha_estrutura
    Estrutura *pEstrutura = &minha_estrutura; 

    /*

                                                    // desferenciar, para acessar com o '.'
    cout << "minha_estrutura tem valor em x como " << (*pEstrutura).x<<endl;
                                                    // desferenciar, para acessar com o '.'
    cout << "minha_estrutura tem valor em y como " << (*pEstrutura).y<<endl;

    */
                                                   // a seta acessa diretamente a variável
    cout << "minha_estrutura tem valor em x como " <<pEstrutura->x<<endl;
                                                   // a seta acessa diretamente a variável
     cout << "minha_estrutura tem valor em y como " <<pEstrutura->y<<endl;

    // O operador seta garante que, não precisa desferenciar para ter acesso as variáveis

    return 0;


}
