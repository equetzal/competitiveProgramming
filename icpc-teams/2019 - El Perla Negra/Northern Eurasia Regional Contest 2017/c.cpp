#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  int n; 
  vector<int> padre, tam;
  UnionFind(int N) : n(N), tam(N, 1), padre(N) {
    while (--N) padre[N] = N;
  }
  int Raiz(int u) {
    if (padre[u] == u) return u;
    return padre[u] = Raiz(padre[u]);
  }
  bool SonConexos(int u, int v) {
    return Raiz(u) == Raiz(v);
  } 
  int  Unir(int u, int v) {
    int Ru = Raiz(u); 
	int Rv = Raiz(v);
    if (Ru == Rv) return 0;
    --n, padre[Ru] = Rv;
    tam[Rv] += tam[Ru];
    return 1;
  }
  
  int NumC(){
  	int Nc = 1;
  	int padreA = Raiz(0);
	for(int i=1;i<=100;i++){
    	    if(Raiz(i)!= padreA) {
			Nc++; 
    	    padreA = Raiz(i);	
			}
    }
	}
  int Tamano(int u) {
    return tam[Raiz(u)];
  }
};

int main(){
    int t,n,u,v,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        UnionFind DSU(n);
        vector< pair<pair<int,int>,bool> >all;
        vector<pair<int,int>> need;
        for(int i = 0;i<m;i++){
            cin>>u>>v;
            u--;
            v--;
            int un = DSU.Unir(u,v);
            if(un){
                need.push_back({u,v});
                all.push_back({{u,v},true});
            }
            else 
                all.push_back({{u,v},false});
        }
        int i = 0;
        cout<<"     "<<need.size()<<endl;
        while(need.size()<=2*n){
            while(all[i].second!= true)i++;
            need.push_back(all[i].first);
            all[i].second= true;
        }
        for(int i = 0;i<m;i++)
            if(all[i].second == false)cout<<all[i].first.first<<" "<<all[i].first.second<<endl;
    
    }
    return 0;
}