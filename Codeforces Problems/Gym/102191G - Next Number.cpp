//CF Gym 102191G - Next Number
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//PSUT Coding Marathon 2019
//Los Hermanos Computadores de Paine

#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  set<int>s;
  int N,B,max;
  cin>>N>>B;
  int nums[N];
  for(int i=0; i<N;i++){
    cin>>nums[i];
  }
  for(int i=0; i<B;i++)
    s.insert(i);

  // max=B-1;
  int last=-1;//ultimo numero disponible
  for(int i=0; i<N;i++){
    if(nums[i]< *(--s.end()))
      last=i;
    if(s.find(nums[i])!=s.end())
      s.erase(nums[i]);
    else{
      break;
    }
  }

  if(last==-1){//incrementar un digito
    for(int i=0;i<N+1;i++){
      if(i==0) cout<<"1 ";
      else if(i==1) cout<<"0 ";
      else cout<<i<<" ";
    }
    cout<<"\n";
  }else{
    set<int> ns;
    for(int i=0; i<B;i++)
      ns.insert(i);
    for(int i=0; i<last;i++)
      ns.erase(nums[i]);
    nums[last]++;
    // for (auto const &e: ns) {
  	// 	cout<<e<<" ";
  	// }
    // cout<<endl;
    while(ns.find(nums[last]++)==ns.end());
    nums[last]--;
    // cout<<last<<endl;
    ns.erase(nums[last]);
    for(int i=last+1; i<N;i++){
      nums[i]=*(ns.begin());
      ns.erase(ns.begin());
    }
    for(int i=0;i<N;i++){
      cout<<nums[i]<<" ";
    }
    cout<<"\n";

  }


  return 0;
}

