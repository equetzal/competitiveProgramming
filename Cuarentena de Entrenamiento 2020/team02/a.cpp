//CF Gym 102191A - Generous Eater
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//PSUT Coding Marathon 2019
//Los Hermanos Computadores de Paine

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x = n/3;
    int y = n-x*3;
    cout<<(x*2)+y;
    return 0;
}
