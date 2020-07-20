//CF Gym 102191C - Seating Arrangement
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//PSUT Coding Marathon 2019
//Los Hermanos Computadores de Paine

#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin>>N;
  long long int nums[N];
  long long int nNums[N];

  for(int i=0;i<N;i++){
    cin>>nums[i];
  }
  if(N<5){
    cout<<"-1\n";
  }else{
    int j=0;
    for(int i=0; i<N;i+=2,j++){
      nNums[j]=nums[i];
    }
    for(int i=1; i<N;i+=2,j++){
      nNums[j]=nums[i];
    }
    if(N%2==0){
      swap(nNums[0],nNums[1]);
    }
    for(int i=0;i<N;i++)
      cout<<nNums[i]<<" ";
    cout<<endl;
  }
  return 0;
}

