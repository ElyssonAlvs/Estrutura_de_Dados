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
    // Alocação dinâmica de um array do tipo Carro, com capacidade para 5 elementos
    // Struct + alocação dinâmica = ponteiro
    Carro *carros = new Carro[5];
    
    Carro car1, car2, car3, car4, car5;
    
    carros[0] = car1;
    carros[1] = car2;
    carros[2] = car3;
    carros[3] = car4;
    carros[4] = car5;

    carros[0].insere("Tornado", "Vermelho", 450, 350);
    carros[1].insere("Luxo", "Preto", 250, 260);
    carros[2].insere("Familia", "Prata", 150, 180);
    carros[3].insere("Trabalho", "Branco", 80, 120);
    carros[4].insere("Padrao", "Cinza", 100, 150);

    for(int i = 0; i < 5; i++){
        carros[i].mostra();
    }

    return 0;
}