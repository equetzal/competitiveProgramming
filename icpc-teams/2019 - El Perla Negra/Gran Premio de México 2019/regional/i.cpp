#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN = 10000;
const int mod = 1000000007;
vector<int> graph[MAXN];
vector<pair<bool,int>> vis(MAXN,{false,0});
set<int> who;
int dfs(int i){
    vis[i].first = true;
    if(graph[i].size()==0){who.insert(i);vis[i].first = true;return 1;}
    for(auto v: graph[i]){
        if(vis[v].first){
            vis[i].second=(vis[i].second +vis[v].second)%mod;
            continue;
        }
        else {
            vis[i].second= (vis[i].second+dfs(v))%mod;       
        }
    }
    return vis[i].second;
} 
int main(){
    int n,l,k,v;
    cin>>n>>l;
    for(int i = 0;i<l;i++){
        cin>>k;
        for(int j = 0;j<k;j++){
            cin>>v;
            v--;
            graph[i].push_back(v);
        }
    }
    for(int i = l;i<n;i++){vis[i].first = false;vis[i].second= 1;}
    cout<<dfs(0);
    cout<<" "<<who.size()<<endl;
    return 0;
}
