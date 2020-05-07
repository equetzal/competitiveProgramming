#include <bits/stdc++.h>
using namespace std;
vector<int>GN[40007],GQ[40007];
vector<int> dis1;
vector<int> dis2;
typedef long long int lli;
int bfs(int diameter,vector<int> graph[],int source,int who){
    vector<int> vis(40007,-1);
    queue<int> Q;
    Q.push(source);
    int u;
    vis[source] = 0;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        if(diameter)
            if(who) 
                dis1[u] = max(dis1[u],vis[u]);
            else 
                dis2[u] = max(dis2[u],vis[u]);
        for(auto v:graph[u]){
            if(vis[v] == -1){
                vis[v] = vis[u]+1;
                Q.push(v);
            }
        }
    }
    return u;
}

int main(){
    int n,q,u,v,maxd=0;
    lli ans=0;
    cout<<fixed<<setprecision(3);
    vector<lli> Acum(40007);
    while(cin>>n>>q){
        maxd = 0;
        ans = 0;
        for(int i=0;i<max(n,q);i++){GN[i].clear();GQ[i].clear();}
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            GN[--u].push_back(--v);  
            GN[v].push_back(u);  
        }
        for(int i=0;i<q-1;i++){
            cin>>u>>v;
            GQ[--u].push_back(--v);
            GQ[v].push_back(u);    
        }
        dis1.assign(n,0);
        dis2.assign(q,0);
        pair<int,int> DN;
        pair<int,int> DQ;
        DN.first = bfs(0,GN,0,0);
        DN.second = bfs(0,GN,DN.first,0);
        DQ.first = bfs(0,GQ,0,0);
        DQ.second = bfs(0,GQ,DQ.first,0);
        bfs(1,GN,DN.first,1);
        bfs(1,GN,DN.second,1);
        bfs(1,GQ,DQ.first,0);
        bfs(1,GQ,DQ.second,0);
        for(int i=0;i<n;i++)maxd=max(maxd,dis1[i]);
        sort(dis2.begin(),dis2.end());
        for(int i=0;i<q;i++)maxd=max(maxd,dis2[i]);
        Acum[q-1]=dis2[q-1];
        for(int i=q-2;i>=0;i--)Acum[i]=dis2[i]+Acum[i+1];
        for(int i=0;i<n;i++){     
            int id=lower_bound(dis2.begin(),dis2.end(),maxd-(dis1[i]+1))-dis2.begin();
            ans+=(lli)maxd*id;
            if(id<q)ans+=Acum[id]+(dis1[i]+1)*(lli)(q-id);      
        }
        cout<<(double)ans/((lli)n*q)<<"\n";
    }
     
    return 0;
}
