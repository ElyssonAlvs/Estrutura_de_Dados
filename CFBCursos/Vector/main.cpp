#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vct = {9, 2, 7, 4, 5, 6, 3, 8, 0, 1, 3, 2, 5};
    vector<int> vct2;
    // Funções de iteração
    /*
     begin aponta para o início da coleção
     end aponta para o final da coleção
     Começando de 1 e não de 0
     */
    for (auto it = vct.begin(); it != vct.end(); it++){
        cout<<*it<<endl;
    }
    cout<<endl;

    // Funções de capacidade

    cout<<"empty() se o vector estiver vazio ele retorna True, se nao, False: "<<endl;
    if (vct.empty()){
        cout<<"Vector vazio"<<endl;
    }
    else{
        cout<<"Vector nao esta vazio"<<endl;
    }
    cout<<endl;
    cout<<"size() retorna o tamanho da colecao: ";
    cout<<vct.size()<<endl;
    cout<<endl;
    cout<<"max_size() retorna a capacidade maxima da colecao: ";
    cout<<vct.max_size()<<endl;

    // comecando de 1 e não de 0
    cout<<"rsize() redimenciona a colecao: ";
    vct.resize(5);
    cout<<vct.size()<<endl;

    for(auto x : vct){
        cout<<x<<endl;
    }

    cout<<endl;

    //shirk_to_fit() redimenciona a capacidade de acordo com a quantidade de elementos
    vct.shrink_to_fit();

    cout<<"capacity() retorna a capacidade do vector na sua criacao: ";
    cout<<vct.capacity()<<endl;

    cout<<endl;

    // Funções de acesso
    cout<<"Pelos colchetes, e a forma tradicional, atraves do at ocorre uma verificao se a posicao requerida e valida: "<<endl;
    cout << vct[3]<<endl;
    cout << vct.at(3)<<endl;
    cout<<"front() retorna o primeiro elemento da colecao: "<<endl;
    cout << vct.front()<<endl;
    cout<<"back() retorn o ultimo elemento da colecao: "<<endl;
    cout << vct.back()<<endl;

    cout << endl;

    // Funções Modificadoras

    // vct2.assign(10,0);
    //assingn(quantidade de elementos, elemento que deseja atribuir)
    vct2.assign(vct.begin(), vct.end()); //(começo, final)
    //Adiciona o elemento na ultima posicao
    vct.push_back(0);
    //Retira o ultimo elemento da colecao
    vct.pop_back();
    for (auto x : vct2){
        cout<<x<< endl;
    }

    return 0;
}