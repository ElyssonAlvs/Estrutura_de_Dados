#include <iostream>

using namespace std;

struct Carro{
    // características do carro
    string nome;
    string cor;
    int pot;
    int velMax;
    int vel;
    // métodos para a atribuição de variáveis

    // Inserir os dados
    void insere(string stnome, string stcor, int stpot, int stvelMax){
        nome = stnome;
        cor = stcor;
        pot = stpot;
        velMax = stvelMax;
        vel = 0;
    } 
    // Mostra os dados do carro
    void mostra(){
        cout<<"Nome.............: "<<nome<<endl
            <<"Cor..............: "<<cor<<endl
            <<"Potencia.........: "<<pot<<endl
            <<"Velocidade atual.: "<<vel<<endl
            <<"Velocidade Maxima: "<<velMax<<endl;

        cout<<endl;
    }
    // Mudar a velocidade atual pela velocidade máxima se possível
    void mudavel(int mv){
        vel = mv;
        // A velocidade do carro nunca ultrapassa a sua máxima velocidade, pelo menos não deveria
        if(vel > velMax){
            vel = velMax;
        }else if(vel < 0){
            vel = 0;
        } 
    }
};

int main(){
    
    Carro car1, car2;
    
    car1.insere("Tornado", "Vermelho", 450,350);
    car2.insere("Luxo", "Preto", 250, 260);
    // Exibe os dados antes da mudaça
    car1.mostra();
    // Ocorre a mudança de dados, se a velocidade fosse alterada para além da máxima, ele iria imprimir a velocidade máxima do carro
    car1.mudavel(150);
    // Exibe com os dados modificados
    car1.mostra();

    /*
    car1.mostra();
    car2.mostra();
    */

    return 0;
}