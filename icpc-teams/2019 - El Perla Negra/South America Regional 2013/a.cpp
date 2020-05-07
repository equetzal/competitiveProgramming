#include <bits/stdc++.h>
using namespace std;
const int MAXN = 107;
vector<int> G[MAXN*MAXN];
char grid[MAXN][MAXN];
int cols[MAXN + 3][MAXN + 3];
int rows[MAXN + 3][MAXN + 3];
int newCol,newRow;
#define NIL 0
#define INF (1<<28)
int nn, m;
vector<int> match(MAXN,0), dist(MAXN,0);
bool bfs() {
    int i, u, v, len;
    queue<int> Q;
    for(i=1; i<=nn; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    while(bfs())
        for(i=1; i<=nn; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}
int main(){
    int n;
    while(cin>>n){
        memset( cols, 0, sizeof( cols ) );
        memset( rows, 0, sizeof( rows ) );
        newCol = 0;
        for(int i = 0;i<n;i++)cin>>grid[i];
        for(int i = 0;i<n;i++)if(grid[0][i] == '.')cols[0][i] =++newCol;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '.'){
                    if(cols[i - 1][j] == 0) cols[i - 1][j] = ++newCol;
                    cols[i][j] = cols[i - 1][j];
                }
            }
        }  
        nn = newCol;
        for(int i  = 0;i<m;i++)G[i].clear();
        for(int i = 0;i<n;i++)if(grid[i][0] == '.')rows[i][0] =++newCol;
        for(int i = 0;i<n;i++){
            for(int j = 1;j<n;j++){
                if(grid[i][j] == '.'){
                    if(rows[i][j-1] == 0) rows[i][j-1] = ++newCol;
                    rows[i][j] = rows[i][j-1];
                }
            }
        }      
       
        m = newCol;
        match.assign(m+1,0);
        dist.assign(m+1,0);
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                if(grid[i][j] == '.')
                    G[cols[i][j]].push_back(rows[i][j]);
        cout<<hopcroft_karp()<<endl;        
    }
    return 0;
}
