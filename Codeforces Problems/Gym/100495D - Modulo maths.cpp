//CF Gym 100495D - Modulo maths

#include <bits/stdc++.h>

#define MAXN 10007
#define ll long long int

using namespace std;

int criba[MAXN];
void prime(){
  memset(criba,0,sizeof(criba));

  for(int i=2; i <= MAXN; i++){
    if(!criba[i]){
      for(int j=2; j*i <= MAXN; j++)
        criba[i*j] = 1;
    }
  }


  return;
}

ll pow_mod(ll a,ll b,ll mo){
    ll ans=1;
    a%=mo;
    while (b){
        if (b&1)
          ans=(ans*a)%mo;
        b>>=1;
        a=a*a%mo;
    }
    return ans%mo;
}

int main(){
    ll n,m;
    cin>>n;
    int t=1;
    prime();

    while(n--){
      cin>>m;
      if(m==1)
        cout<<"Case #"<<t<<": "<<1<<endl;
      else if(!criba[m]){
        cout<<"Case #"<<t<<": "<<pow_mod(2,m-1,m)<<endl;
      }else{
        cout<<"Case #"<<t<<": "<<(((m-1)%m)*((m-1)%m))%m<<endl;
      }
      t++;
    }

  return 0;
}
