#include <bits/stdc++.h>

using namespace std;

set< pair<int,int> > deeperTree;

int deepCounter(vector< pair<int,vector<int> > > &graph, int me){
	if(graph[me].second.size() == 0){
		graph[me].first = 1;
		return graph[me].first;
	}

	for(auto child:graph[me].second){
		graph[me].first = max(graph[me].first, deepCounter(graph, child));
	}
	graph[me].first++;
	return graph[me].first;
}

void killSons(vector< pair<int,vector<int> > > &graph, int me, int &killed){
	if(killed == 0)
		return;
	if(graph[me].first == killed){
		deeperTree.erase(make_pair(killed, me));
	}
	for(auto child:graph[me].second){
		if(graph[child].first == (killed-1)){
			killed--;
			killSons(graph, child, killed);
			return;
		}
	}
	return;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k; cin >> n >> k;
	vector< pair<int,vector<int> > > graph(n);

	graph[0].first = -1;
	for(int i=1; i<n; i++){
		int idx; cin >> idx; idx--;
		graph[i].first = -2;
		graph[idx].second.push_back(i);
	}


	deepCounter(graph,0);
	for(int i=0; i<graph.size(); i++){
		deeperTree.insert(make_pair(graph[i].first, i));
//		cout << graph[i].first << " " << i << endl;
	} 


/*	auto it=deeperTree.end();
	it--;
	for(; it!=deeperTree.begin(); it--){
		cout << it->first << " " << it->second << endl;
	}
*/
	int totalKilled = 0;
	while(k-- && !deeperTree.empty()){
		auto it = deeperTree.end();
		it--;
		if(it == deeperTree.begin())
			break;
		int toKill = it->first;
		totalKilled += toKill;
//		cout << "to kill " << toKill << endl;
		killSons(graph, it->second, toKill);
	}	

	cout << totalKilled << endl;

	return 0;
}