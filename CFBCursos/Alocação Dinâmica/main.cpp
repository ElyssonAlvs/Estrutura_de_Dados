#include <iostream>
#include <stdio.h> // para função gets
#include <stdlib.h> // para função malloc

using namespace std;

int main(){
    
    char *vnome;
    vnome = (char *) malloc(sizeof(char));

    gets(vnome);

    // apenas o primeiro nome
    // cin>>vnome;

    cout<<vnome<<endl;

    cout<<sizeof(vnome); 

    return 0;
}
