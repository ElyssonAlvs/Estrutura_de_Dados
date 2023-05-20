#include <iostream>

using namespace std;

int main(){
    int linha, coluna, nlinha, ncoluna;
    cin >> nlinha >> ncoluna;
    int matriz[nlinha][ncoluna];

    for(linha = 0; linha < nlinha; linha++){
        for(coluna = 0; coluna < ncoluna; coluna++){
            cin >> matriz[linha][coluna];
        }
    }

    int contador = 0;
    for(linha = 1; linha < nlinha; linha++){
        for(coluna = 0; coluna < ncoluna; coluna++){
                if(matriz[linha][coluna] < matriz[linha - 1][coluna]){
                    contador++;
                }
            }
        }
    cout << contador;
    }

