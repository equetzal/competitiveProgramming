//CF Gym 101252C - Electrician

#include <bits/stdc++.h>
 
using namespace std;
 
#define maxn 30110
 
typedef long long ll;
 
int par[maxn], sz[maxn], n;
map<int,int> pos;
set<int> s;
 
struct edge{
	int u,v,r,ind;
	ll w;
}ara[maxn];
 
bool cmp(edge a, edge b){
	if(a.r != b.r)
		return a.r > b.r;
	return a.w > b.w;
}
 
int root(int x){
	if(par[x] == 0)
		return x;
	return root(par[x]);
}
 
ll merge_node(int x, int y, ll w){
	x = root(x);
	y = root(y);
	
	if(x == y)
		return 0LL;
	if(sz[x] < sz[y])
		swap(x,y);
	par[y] = x;
	sz[x] += sz[y];
	
	return w;
}
 
ll kruskal(){
	sort(ara, ara+n, cmp);
	ll sum = 0LL;
	for(int i=0; i<n; i++){
		sum += merge_node(ara[i].u, ara[i].v, ara[i].w);
	}
	return sum;
}
 
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> ara[i].u >> ara[i].v >> ara[i].r >> ara[i].w;
		ara[i].ind = i+1;
		s.insert(ara[i].u);
		s.insert(ara[i].v);
	}
	
	set<int> :: iterator it;
	
	int actPos = 1;
	for(it = s.begin(); it != s.end(); it++){
		pos[*(it)] = actPos;
		actPos++;
	}
	
	for(int i=0; i<n; i++){
		ara[i].u = pos[ara[i].u];
		ara[i].v = pos[ara[i].v];
	}
	
	cout << kruskal() << endl;
	
	for(int i=n-1; i>=0; i--){
		if(i != (n-1))
			cout << " ";
		cout << ara[i].ind;
	}
	cout << endl;	
	
	return 0;
}
