//CF Gym 101853B - New Assignment

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const int MAXN = 10005;
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

map<lli,lli>  primeFactors(lli n){
    map<lli,lli> primeFrec;
    
    while(!(n&1)){ 
    	primeFrec[2]++;
        n = n/2; 
    } 

    lli sq = sqrt(n);
    for(lli i = 3; i <= sq+2; i += 2){ 
        while (n%i == 0){
        	primeFrec[i]++; 
            n = n/i; 
        } 
    } 

    if(n > 2)
    	primeFrec[n]++; 
    
    return primeFrec;
}

int main() {
	int t; cin >> t;
	while(t--){
		for(int i=0; i<MAXN; i++)
			adj[i].clear();
		
		int n; cin >> n;
		vector<int> personality(n);
		vector<int> boys,girls;
		map<int, vector<int> > commonDivisors; //Primo, Nodos 
		int n1=0,n2=0;
		
		for(int i=0; i<n; i++)
			cin >> personality[i];
		for(int i=0; i<n; i++){
			char sx; cin >> sx;
			if(sx == 'F')
				girls.push_back(personality[i]);
			else
				boys.push_back(personality[i]);
		}
		
		for(int i=0; i<boys.size(); i++){
			map<lli,lli> factors = primeFactors(boys[i]);
			for(auto f:factors){
				commonDivisors[f.first].push_back(i);
			}
		}
		
		for(int i=0; i<girls.size(); i++){
			map<lli,lli> factors = primeFactors(girls[i]);
			for(auto f:factors){
				for(auto j:commonDivisors[f.first]){
					adj[i].push_back(j);
				}
			}
		}
		
		cout << n-hopcroft_karp(girls.size(), boys.size()) << endl;
	}
  return 0;
}
