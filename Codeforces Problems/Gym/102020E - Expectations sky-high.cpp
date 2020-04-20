//CF Gym 102020E - Expectations sky-high

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define modulo 1000000007
 
ll inv(ll b, ll M){
	ll u = 1, x = 0, s = b, t = M;
	while (s){
		ll q = t / s;
		swap(x -= u * q, u);
		swap(t -= s * q, s);
	}
	return (x %= M) >= 0 ? x : x + M;
}
 
ll sz[200010], s[200010];
ll ans = 0;
void dfs(int u, int parent, vector < vector<int> > &graph){
	sz[u] = 1;
	for(auto v:graph[u]){
		if(v != parent){
			dfs(v,u, graph);
			ans += s[u] * sz[v] + sz[u] * (sz[v] + s[v]);
			ans %= modulo;
			s[u] += sz[v] + s[v];
			sz[u] += sz[v];
		}
	}
}
 
int main(){
	long long int n; cin >> n;
	vector< vector<int> > graph(n);
	
	for(int i=0; i<(n-1); i++){
		int a,b; cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	memset(sz, 0, sizeof(sz));
	memset(s, 0 , sizeof(s));
	
	dfs(0,-1,graph);
	ll num = ans, den;
	den = ((n*(n-1)/2)+n)%modulo;
	
	ll res = (num*inv(den,modulo))%modulo;
	
	cout << res << endl;
	
}
