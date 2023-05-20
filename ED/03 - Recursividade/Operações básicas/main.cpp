#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
// imprime o vetor
void vet(vector<int> &v, int tam){
    if(tam == 1){
        cout << v[0] << " ";
    }else{
        // passa uma posição depois imprime
        vet(v, tam-1);
        cout << v[tam-1] << " ";
    }
}
// imprime ao contrário
void rvet(vector<int> &v, int tam){
    if(tam == 1){
        cout << v[0] << " ";
    }else{
        // imprime depois passa uma posição
        cout << v[tam-1] << " ";
        rvet(v, tam-1);
    }
}
// soma dos elementos
int sum(vector<int> v, int tam){
    int s = 0;
    
    if(tam == 1){
        return v[0];
    }else{
        s = v[tam-1] + sum(v, tam-1);
        return s;
    }
}
// multiplicação dos elementos
int mult(vector<int> v, int tam){
    int m = 0;
    
    if(tam == 1){
        return v[0];
    }else{
        m = v[tam-1] * mult(v, tam-1);
        return m;
    }
}
// imprime o inverso
void inv(vector<int> &v, int i, int f){
    if(i < f){
        int aux = v[i];
        v[i] = v[f];
        v[f] = aux;
        
        inv(v, i+1, f-1);
    }
}
// imprime o menor elemento
int min(vector<int> v, int tam){
    if(tam == 1) return v[0];
    else{
        int aux = min(v, tam-1);
        if(v[tam-1] > aux)
            return aux;
        else
            return v[tam-1];
    }
}
int main(){
    // pegar 
    string numeros;
    getline(cin, numeros);
    
    stringstream ss(numeros);
    
    vector<int> vetor;
    
    int value;
    while(ss>>value){
        vetor.push_back(value);
    }
    
    cout << "vet : [ ";
    vet(vetor, (int)vetor.size());
    cout << "]" << endl;
    cout << "rvet: [ ";
    rvet(vetor, (int)vetor.size());
    cout << "]" << endl;
    cout << "sum : " << sum(vetor, (int)vetor.size()) << endl;
    cout << "mult: " << mult(vetor, (int)vetor.size()) << endl;
    cout << "min : " << min(vetor, (int)vetor.size()) << endl;
    cout << "inv : [ ";
    inv(vetor, 0, (int)vetor.size()-1);
    vet(vetor, (int)vetor.size());
    cout << "]" << endl;   
}