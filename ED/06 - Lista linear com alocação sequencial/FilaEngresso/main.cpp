#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    
    string fila;
    getline(cin,fila);
    
    stringstream ss;
    ss<<fila;
    vector<int> vetor;
    
    int auxiliar;
    while(ss>>auxiliar){
        vetor.push_back(auxiliar);
    }
    
    int m;
    cin>>m;
    cin.ignore();
    
    string fora;
    getline(cin,fora);
    
    stringstream ssFora;
    ssFora<<fora;
    
    while(ssFora>>auxiliar){
        for(int i = 0; i < (int)vetor.size();i++){
            if(auxiliar == vetor[i]){
                vetor.erase(vetor.begin()+i);
            }
        }
    }
    
    for (int i = 0; i < (int) vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;   
    
}