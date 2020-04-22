//CF Gym 102412I - Find the Vertex

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lli n,m; cin >> n >> m;
	vector<vector<int>> graph(n);

	vector<int> dist(n);
	queue<int> toCheck;
	for(int i=0; i<n; i++){
		cin >> dist[i];
		if(dist[i] == 0)
			toCheck.push(i);
	}

	lli u,v;
	while(m--){
		cin >> u >> v;
		u--,v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	lli ans;
	while(!toCheck.empty()){
		bool isRight = true;
		for(auto i:graph[toCheck.front()]){
			if(1 != dist[i])
				isRight = false;
		}
		if(isRight){
			ans = toCheck.front();
			break;
		}
		toCheck.pop();
	}

	cout << ans+1 << endl;

	return 0;
}
