#include <iostream>

using namespace std;
// Estrutura aluno
struct Aluno{
    char nome[80];
    int matricula;
    char disciplina[120];
    double nota;
};
// Pegar dados do aluno
Aluno pegar_dados(){
    Aluno aluno;
    cin>>aluno.nome;
    cin>>aluno.matricula;
    
    cin.ignore();
    
    cin>>aluno.disciplina;
    cin>>aluno.nota;
    
    return aluno;
}
// Verifcar a nota
void verificar_nota(Aluno aluno){
    if(aluno.nota >= 7){
        cout<<aluno.nome<<" aprovado(a) em "<<aluno.disciplina;
    }else{
        cout<<aluno.nome<<" reprovado(a) em "<<aluno.disciplina;
    }
}

int main(){
    Aluno aluno = pegar_dados();
    // Limpar o buffer de entrada
    cin.ignore();
    verificar_nota(aluno);
    
}