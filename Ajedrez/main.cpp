#include<vector>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;

enum Colors {
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGREY = 7,
 DGREY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};

class Pieza{
    private:
        int posicion_x,posicion_y,equipo,pieza_valor;
        string nombre;
    public:
        Pieza(){};
        void mover(int,int);
        void set(int,int,string);
        int posicionX();
        int posicionY();
};
void Pieza::set(int team,int valor,string pieza){
    equipo = team;
    pieza_valor = valor;
    nombre = pieza;
}

void Pieza::mover(int x, int y){
    posicion_x = x;
    posicion_y = y;
}

int Pieza::posicionX(){
    return posicion_x;
}

int Pieza::posicionY(){
    return posicion_y;
}

void color(int Background, int Text);
int main(){
    //int tablero[8][8];
    int i, j, k, l;
    Pieza *claras;
    claras = new Pieza[16];
    bool ocupadoClaro;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            ocupadoClaro = false;
                for(k=0;k<16;k++){
                        if(claras[k].posicionX()==j || claras[k].posicionY()==i){
                            ocupadoClaro=true;
                        }
                }
            if(ocupadoClaro){
                color(LGREEN,BLACK);
                cout<<"Pieza";
            }else{
                if(j%2==0){
                    if(i%2==0){
                        color(BROWN,BROWN);
                        cout<<"----";
                    }else{
                        color(YELLOW,YELLOW);
                        cout<<"----";
                    }
                }else{
                    if(i%2!=0){
                        color(BROWN,BROWN);
                        cout<<"----";
                    }else{
                        color(YELLOW,YELLOW);
                        cout<<"----";
                    }
                }
            }
        }
        cout<<endl;
    }
    color(BLACK,LGREEN);
 return 0;
}

void color(int Background, int Text){
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    int    New_Color= Text + (Background * 16);
    SetConsoleTextAttribute(Console, New_Color);
}
