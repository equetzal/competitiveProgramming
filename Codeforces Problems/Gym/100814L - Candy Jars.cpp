//CF Gym 100814L - Candy Jars
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//ECPC 2015
//Los Hermanos Computadores de Paine

#include<bits/stdc++.h>

using namespace std;

int main(){
  int T,N;
  cin>>T;
  while(T--){
    bool alice=false;
    int aux;
    cin>>N;
    long long int maxi=N*(N-1);
    for(int i=0; i<N;i++){
      cin>>aux;
      if(!alice){
        int range= aux%maxi;
        if(1<=range and range<N){
          alice=false;
        }else alice=true;
      }
    }
    if(alice)
      cout<<"Alice\n";
    else
      cout<<"Bob\n";
  }
  return 0;
}

