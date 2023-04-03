#include <iostream>
#include <string>

using namespace std;

struct Aluno{
    int matricula=0;
    string nome_completo;
    double nota;
};

Aluno pegar_dados(){
    Aluno aluno;
    
    cin>>aluno.matricula;
    cin.ignore();
    
    getline(cin,aluno.nome_completo);
    cin>>aluno.nota;
    
    return aluno;
}

void mostra_aluno(Aluno aluno){
    
    if(aluno.matricula == 0){
        cout<<"NAO ENCONTRADA";
    }else{
        cout.precision(1);
        cout<<aluno.nome_completo<<endl;
        cout<<fixed<<aluno.nota;
    }
}

Aluno encontra_aluno(Aluno alunos[], int tam, int matricula){
    for (int i = 0; i < tam; i++)
        if(alunos[i].matricula == matricula)
            return alunos[i];
    
    Aluno a;
    return a;
}

int main(){
    Aluno alunos[50];
    int qtd_alunos,matricula;
    
    cin>>qtd_alunos;
    
    for(int i = 0; i < qtd_alunos; i++){
        alunos[i] = pegar_dados();
    }
    
    cin>>matricula;
    
    Aluno aluno = encontra_aluno(alunos,qtd_alunos,matricula);
    mostra_aluno(aluno);
    
}