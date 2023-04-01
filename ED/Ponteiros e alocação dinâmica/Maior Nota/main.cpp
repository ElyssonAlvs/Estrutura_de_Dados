#include <iostream>

using namespace std;

// Criando uma estrutura Aluno, composto com nome, matricula, disciplina e a nota 
struct Aluno{
    char nome[80];
    int matricula;
    char disciplina[120];
    double nota;
};

// Uma função aluno, no qual os seus parâmetros são as variáveis da estrutura Aluno, portanto, não precisa especificar
Aluno pegar_dados(){
    Aluno aluno;
    cin>>aluno.nome;
    cin>>aluno.matricula;
    // limpar o buffer de entrada de dados, evitar erros
    cin.ignore();
    
    cin>>aluno.disciplina;
    cin>>aluno.nota;
    // retorna o os dados do aluno
    return aluno;
}

void maior_nota(Aluno aluno1, Aluno aluno2){
    // ponto de precisão de 1 após a vírgula
    cout.precision(1);
    
    if(aluno1.nota > aluno2.nota){
        cout<<aluno1.nome<<" , "<<fixed<<aluno1.nota;
    }else if(aluno1.nota < aluno2.nota){
        cout<<aluno2.nome<<" , "<<fixed<<aluno2.nota;
    }else{
        cout<<aluno1.nome<<" e "<<aluno2.nome<<" , "<<fixed<<aluno1.nota;
    }
}

int main(){
    Aluno aluno1 = pegar_dados();
    cin.ignore();
    Aluno aluno2 = pegar_dados();
    maior_nota(aluno1,aluno2);
    
}