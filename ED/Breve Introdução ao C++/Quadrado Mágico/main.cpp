#include <iostream>

using namespace std;
#define tam 3

int main(){
    int matriz[tam][tam];
    int linha, coluna;
    // Pegar a matriz
    for(linha = 0; linha < tam; linha++){
        for(coluna = 0; coluna < tam; coluna++){
            cin >> matriz[linha][coluna];
        }
    }

    int somadsecundaria = matriz[0][0] + matriz[1][1] + matriz[2][2];
    int somadprincipal = matriz[2][0] + matriz[1][1] + matriz[0][2];
    bool ehdiagonal = somadprincipal == somadsecundaria;
    /*
    // Realizar a soma da diagonal principal
    for(linha = 0; linha < tam; linha++){
        dprincipal += matriz[linha][linha];
    }
    // realiza a soma da diagonal secundaria
    for(linha = 0; linha < tam; linha++){
        dsecundaria += matriz[linha][tam - 1 - linha];
    }
    */
    int somalinha1 = matriz[0][0] + matriz[0][1] + matriz[0][2];
    int somalinha2 = matriz[1][0] + matriz[1][1] + matriz[1][2];
    int somalinha3 = matriz[2][0] + matriz[2][1] + matriz[2][2];
    bool ehlinha = somalinha1 == somalinha2 && somalinha1 == somalinha3;

    int somacoluna1 = matriz[0][0] + matriz[1][0] + matriz[2][0];
    int somacoluna2 = matriz[0][1] + matriz[1][1] + matriz[2][1];
    int somacoluna3 = matriz[0][2] + matriz[1][2] + matriz[2][2];
    bool ehcoluna = somacoluna1 == somacoluna2 && somacoluna1 == somacoluna3;
    /*
    // Soma das Linhas
    for(linha = 0; linha < tam; linha++){
        for(coluna = 0; coluna < tam; coluna++){
            totcolunas += matriz[linha][coluna];
        }
    }
    // Soma das colunas
    for(coluna = 0; coluna < tam; coluna++){
        for(linha = 0; linha < tam; linha++){
            totlinhas += matriz[linha][coluna];
        }
    }
    */
    // Verificação
    if(ehdiagonal && ehcoluna && ehlinha){
        cout << "sim";
    }else{cout << "nao";}
    
}