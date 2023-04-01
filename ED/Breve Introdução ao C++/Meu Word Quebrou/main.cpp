#include <iostream>


using namespace std;

int main(){
    char frase[101], opcao;
    
    cin.get(frase,101);
    
    cin>>opcao;
    
    if(opcao == 'M'){
        for(int i = 0; frase[i] != '\0'; i++){
            // transformar em miúsculo
            if(frase[i] >= 97 && frase[i] <= 122){
                frase[i] -= 32;
            }
        }
    }else if(opcao == 'm'){
        // transformar em minúsculo
        for(int i = 0; frase[i] != '\0'; i++){
            if(frase[i] >= 65 && frase[i] <= 90){
                frase[i] += 32;
            }
        }
    }else if(opcao == 'i'){
        // inverter as letras
        for(int i = 0; frase[i] != '\0'; i++){
            if(frase[i] >= 65 && frase[i] <= 90){
                frase[i] += 32;
            }else if(frase[i] >= 97 && frase[i] <= 122){
                frase[i] -= 32;
            }
        }
    }else if(opcao == 'p'){
        // transformar primeira letra em maiúscula
        for(int i = 0; frase[i] != '\0'; i++){
            if(i == 0){
                if(frase[i] >= 65 && frase[i] <= 90){
                    frase[i] += 32;
                    }
                }else if(frase[i - 1] == ' ' && frase[i + 1] != ' '){
                    if(frase[i] >= 97){
                        frase[i] -= 32;
                    }
                }  
            }
        }
    cout<<frase;
}

