//CF Gym 100753B - Bounty Hunter II

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1010;
vector <int> adj[MAXN];
vector <bool> used(MAXN), visit(MAXN);
int match[MAXN], dist[MAXN];


void bfs(int n1, int n2){
    fill(dist, dist+n1, -1);
    queue<int> q;
    
    for(int u=0; u<n1; u++){
        if(!used[u]){
            q.push(u);
            dist[u] = 0;
        }
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int j=0; j<(int)adj[u].size(); j++){
            int v = match[adj[u][j]];
            if(v >= 0 && dist[v] < 0){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
}

bool dfs(int u){
    visit[u] = true;
    for(int j=0; j< (int)adj[u].size(); j++){
        int v = match[adj[u][j]];
        if(v<0 || (!visit[v] && (dist[v] == dist[u] + 1) && dfs(v))){
            match[adj[u][j]] = u;
            used[u] = true;
            return true;
        }
    }
    return false; 
}

int hopcroft_karp(int n1, int n2){
    fill(match, match+n2, -1);
    fill(used.begin(), used.end(), false);
    int res = 0;
    
    for(;;){
        bfs(n1,n2);
        fill(visit.begin(), visit.end(), false);
        int f=0;
        for(int u=0; u<n1; u++){
            if(!used[u] && dfs(u)){
                f++;
            }
            
        }
        if(f == 0){
            return res;
        }
        res += f;
    }
    return res;
}

int main(){
    int nNodes, k;
    cin >> nNodes;
    
    for(int i=0; i<nNodes; i++){
        cin >> k;
        if(k == 0)
            continue;
        
        int desNode;
        while(k--){
            cin >> desNode;
            adj[i].push_back(desNode);
        }
    }
    
    cout << nNodes - hopcroft_karp(nNodes, nNodes) << "\n";
    
    return 0;
}
