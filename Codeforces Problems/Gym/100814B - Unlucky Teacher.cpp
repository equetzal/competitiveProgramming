//CF Gym 100814B - Unlucky Teacher
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//ECPC 2015
//Los Hermanos Computadores de Paine

#include<bits/stdc++.h>

using namespace std;

int main(){
  int Q,M,T;
  char op,re;
  cin>>T;
  while(T--){
    cin>>Q>>M;
    vector<set<char>> cont(Q);

    for(int i=0; i<Q; i++){
      cont[i].insert('A');
      cont[i].insert('B');
      cont[i].insert('C');
      cont[i].insert('D');
    }

    for(int i=0; i<M;i++){
      for(int j=0; j<Q;j++){
        cin>>op>>re;
        if(re=='T'){
          cont[j].clear();
          cont[j].insert(op);
        }else
          cont[j].erase(op);
      }
    }
    for(int i=0; i<Q; i++){
      if(cont[i].size()==1){
        set<char>::iterator it = (cont[i]).begin();
        cout<<*it;
      }else{
        cout<<"?";
      }
      if(i!=Q-1) cout<<" ";
      
    }
    cout<<"\n";

  }


  return 0;
}

