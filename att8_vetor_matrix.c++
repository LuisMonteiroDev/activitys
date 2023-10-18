#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
    int x, y = 0;
    float notas[4][10];
    for(x=0;x<5;x=x+1){
        for(y=0;y<10;y=y+1){
            notas [x][y] = y * 6;
        }
    }

    for(x=0;x<4;x=x+1){
        for(y=0;y<4;y=y+1){
            cout<<x<<" "<<y<<" NOTAS: "<<notas [x][y]<<"\n";
        }
        cout<<"\n";
    }
    cout << "[1][4] " << " NOTAS: " << notas[1][4] << "\n";
    cout << "[2][8] " << " NOTAS: " << notas[2][8] << "\n";
    cout << "[3][1] " << " NOTAS: " << notas[3][1] << "\n";
    return 0;
}