#include <iostream>

using namespace std;

int main(){

    string veiculos = "Carro";
    string *pv;

    pv = &veiculos; // Ponteiro pv recebe o endereço da varíavel veiculo

    cout<<"Endereco: "<<pv<<endl<<"Valor: "<<*pv<<endl;

    *pv = "Moto"; // No endereço apontado por *pv adicione o valor novo
    cout<<endl;

    cout<<"Endereco: "<<pv<<endl<<"Valor: "<<*pv<<endl;

}