//CodeChef KMHAMHA - Kamehameha

#include <algorithm>
#include <queue> 
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 1010;

vector <int> adj[MAXN];
vector <bool> used(MAXN), visit(MAXN);
int match[MAXN], dist[MAXN];

void bfs(int n1, int n2){
    fill(dist, dist+n1, -1);
    queue <int> q;
    
    for(int u=0; u<n1; u++){
        if(!used[u]){
            q.push(u);
            dist[u] = 0;
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int j=0; j < (int)adj[u].size(); j++){
            int v = match[adj[u][j]];
            if(v >= 0 && dist[v] < 0){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

bool dfs(int u){
    visit[u] = true;
    
    for(int j=0; j < (int)adj[u].size(); j++){
        int v = match[adj[u][j]];
        
        if(v < 0 || (!visit[v] && dist[v] == dist[u] + 1 && dfs(v))){
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
        if(f==0){
            return res;
        }
        res += f;
    }
    return res;
}

int main(){
    int cases;
    cin >> cases;
 
    while(cases--){
        int cells;
        cin >> cells;
        
        int x,y;
        int tamX=0, tamY=0;
        while(cells--){
            cin >> x >> y;
            tamX = max(x,tamX);
            tamY = max(y,tamY);
            
            adj[x].push_back(y);
        }
        
        cout << hopcroft_karp(tamX+1, tamY+1) << "\n";
    }
    
    
    return 0;
}
