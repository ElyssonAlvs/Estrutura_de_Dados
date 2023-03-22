/*
Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas
de um ponto em um plano. A seguir, determine qual o quadrante ao qual pertence o
ponto, ou se está sobre um dos eixos cartesianos ou na origem (x = y = 0).
Se o ponto estiver na origem, escreva a mensagem “Origem”.
Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou “Eixo Y”, conforme for a
situação

Read 2 values ​​with one decimal place (x and y), which must represent the coordinates
from a point in a plane. Next, determine which quadrant the
point, or whether it is on one of the Cartesian axes or at the origin (x = y = 0).
If the point is at the origin, write the message “Origin”.
If the point is on one of the axes, write “X axis” or “Y axis”, according to the
situation
*/
#include <iostream>

using namespace std;

int main(){
    float x,y;
    cout << "Coord. X : ";
    cin >> x;
    cout << "Coord. Y : ";
    cin >> y;
    if((x == 0) && (y == 0)){
        cout << "Origin";
    }else if((x > 0) && (y > 0)){
        cout << "Q1";
    }else if((x < 0) && (y > 0)){
        cout << "Q2";
    }else if((x < 0) && (y < 0)){
        cout << "Q3";
    }else if((x > 0) && (y < 0)){
        cout << "Q4";
    }
}
