#include <iostream>

using namespace std;

struct Carro{
    string nome;
    string cor;
    int pot;
    int velMax;
};

int main(){
    
    Carro car1;
    Carro car2;

    car1.nome = "Tornado";
    car1.cor = "Vemelho";
    car1.pot = 450;
    car1.velMax = 350;

    car2.nome = "Luxo";
    car2.cor = "Preto";
    car2.pot = 250;
    car2.velMax = 260;

    cout<<"Nome.............: "<<car1.nome<<endl
        <<"Cor..............: "<<car1.cor<<endl
        <<"Potencia.........: "<<car1.pot<<endl
        <<"Velocidade Maxima: "<<car1.velMax<<endl;

    cout<<endl;
    
    cout<<"Nome.............: "<<car2.nome<<endl
        <<"Cor..............: "<<car2.cor<<endl
        <<"Potencia.........: "<<car2.pot<<endl
        <<"Velocidade Maxima: "<<car2.velMax<<endl;


    return 0;
}