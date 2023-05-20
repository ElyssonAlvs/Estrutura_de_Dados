#include <iostream>
#include <vector>

using namespace std;

vector<int> matchingStrings(vector<string> consulta, vector<string> busca){
    vector<int> matches;
    for(int i = 0; i < (int) busca.size(); i++){
        int contador = 0;
        for(int j = 0; j < (int) consulta.size(); j++){
            if(busca[i] == consulta[j]){
                contador++;
            }
        }
        matches.push_back(contador);
    }
    return matches;
}

int main(){
    int tamanho_consulta;
    cin>>tamanho_consulta;
    vector<string> consulta;
    for(int i = 0; i<tamanho_consulta; i++){
        string auxiliar;
        cin>>auxiliar;
        consulta.push_back(auxiliar);
    }
    
    int tamanho_busca;
    cin>>tamanho_busca;
    vector<string> busca;
    for(int i = 0; i < tamanho_busca; i++){
        string auxiliar;
        cin>>auxiliar;
        busca.push_back(auxiliar);
    }
    
    vector<int> matches = matchingStrings(consulta, busca);
    
    for(int i = 0; i < (int)matches.size();i++){
        if(i!=0){
            cout<<" ";
        }
        cout<<matches[i];
    }
    cout<<endl;
}