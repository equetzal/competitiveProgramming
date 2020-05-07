#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;
std::vector<int> adj[MAXN];
std::vector<bool> used(MAXN), visit(MAXN);
int match[MAXN], dist[MAXN];

void bfs(int n1, int n2) {
  std::fill(dist, dist + n1, -1);
  std::queue<int> q;
  for (int u = 0; u < n1; u++) {
    if (!used[u]) {
      q.push(u);
      dist[u] = 0;
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = 0; j < (int)adj[u].size(); j++) {
      int v = match[adj[u][j]];
      if (v >= 0 && dist[v] < 0) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

bool dfs(int u) {
  visit[u] = true;
  for (int j = 0; j < (int)adj[u].size(); j++) {
    int v = match[adj[u][j]];
    if (v < 0 || (!visit[v] && dist[v] == dist[u] + 1 && dfs(v))) {
      match[adj[u][j]] = u;
      used[u] = true;
      return true;
    }
  }
  return false;
}

int hopcroft_karp(int n1, int n2) {
  std::fill(match, match + n2, -1);
  std::fill(used.begin(), used.end(), false);
  int res = 0;
  for (;;) {
    bfs(n1, n2);
    std::fill(visit.begin(), visit.end(), false);
    int f = 0;
    for (int u = 0; u < n1; u++) {
      if (!used[u] && dfs(u)) {
        f++;
      }
    }
    if (f == 0) {
      return res;
    }
    res += f;
  }
  return res;
}

int main() {
	int n;
	while(cin >> n){
		short rows[n][n], cols[n][n];
		char mat[n][n];
		for(int i=0; i<MAXN; i++)
			adj[i].clear();
		
		fill(dist, dist+MAXN, -1);
    fill(match, match+MAXN, -1);
    fill(used.begin(), used.end(), false);
    fill(visit.begin(), visit.end(), false);

    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin >> mat[i][j];

		int rMax = 0, cMax = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(mat[i][j] == 'X'){
					if(j!=0) rMax++;
					rows[i][j] = -1;
				}else{
					rows[i][j] = rMax;
				}
			}
			rMax++;
		}
		for(int j=0; j<n; j++){
			for(int i=0; i<n; i++){
				if(mat[i][j] == 'X'){
					if(i!=0) cMax++;
					cols[i][j] = -1;
				}else{
					cols[i][j] = cMax;
				}
				if(mat[i][j] == '.'){
					adj[rows[i][j]].push_back(cols[i][j]);
				}
			}
			cMax++;
		}

		cout << hopcroft_karp(rMax+1,cMax+1) << endl;
	}

  return 0;
}
