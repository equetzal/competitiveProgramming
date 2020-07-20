//CF Gym 100814D - Frozen Rivers
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//ECPC 2015
//Los Hermanos Computadores de Paine - Coded by Quetzalli

#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

void dfs(int me, lli t, vector<vector<pair<int,int>>> &graph, vector<lli> &time){
	if(graph[me].size() == 0){ //Soy hijo
		time.push_back(t);
		return;
	}

	sort(graph[me].begin(), graph[me].end());
	lli mn = graph[me][0].first;
//	cout << "me=" << me+1 << ", min= " << mn << endl;

	for(auto child:graph[me]){
//		cout << "yendo a " << child.second+1 << ", distance= " << child.first << endl;
		dfs(child.second, t+mn+((child.first-mn)*2), graph, time);
	}

	return;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<pair<int,int>>> graph(n);

		int p,c;
		for(int i=1; i<n; i++){
			cin >> p >> c;
			graph[p-1].push_back(make_pair(c,i));
		}

		vector<lli> time;
		dfs(0, 0, graph, time);
		sort(time.begin(), time.end());

		lli q, ti, pos; cin >> q;
		while(q--){
			cin >> ti;
			pos = (upper_bound(time.begin(), time.end(), ti) - time.begin());
			cout << pos << endl;
		}

	}
	return 0;
}

