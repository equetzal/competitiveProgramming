//CF Gym 100814K - PhD math
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//ECPC 2015
//Los Hermanos Computadores de Paine

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

ll dp[3][300];

int main(){
  ull a,b;
  ll T,n,p,res;
  cin>>T;
  while(T--){
    cin>>a>>b>>n>>p;
    int digits[n+1];
    memset(digits,0,sizeof(digits));
    memset(dp,0,sizeof(dp));
    for(int i=0 ; i<n ; i++){
      a*=10;
      digits[i]=a/b;
      a=(a%b);
      // cout<<digits[i]<<" ";
    }
    // cout<<endl;
    bool alt=false;
    res=0;
    for(int i=0 ; i<n ; i++){
      for(int j=0; j<p; j++)
        dp[alt][j]=0;

      dp[alt][digits[i]%p]++; //mult directo
      for(int j=0; j<p; j++){
        dp[alt][(j*10+digits[i])%p]+=dp[!alt][j]; // nums sin tomar j
      }
      res+=dp[alt][0];
      alt=!alt;//tomar no tomar
    }
    cout<<res<<"\n";
  }


  return 0;
}

