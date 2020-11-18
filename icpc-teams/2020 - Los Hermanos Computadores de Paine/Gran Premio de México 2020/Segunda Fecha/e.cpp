#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


typedef long long int lli;

void getOrder(int start, vector<vector<int>> &graph, vector<int> &order){
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	q.push(start);
	visited[start] = true;

	int curr;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		order.push_back(curr);

		for(auto child:graph[curr]){
			if(!visited[child]){
				q.push(child);
				visited[child] = true;
			}
		}
	}
	
	reverse(order.begin(), order.end());
}

void getParent(int me, int father, vector<vector<int>> &graph, vector<int> &myParent){
	myParent[me] = father;
	for(auto child:graph[me]){
		if(child != father){
			getParent(child, me, graph, myParent);
		}
	}
	return;
}

void propagateParents(vector<set<int>> &propParents, vector<int> &order, map<int,pair<int,int>> &fiesta, vector<int> &edad, vector<int> &myParent){
	int father;
	for(auto node:order){
		father = myParent[node];
		queue<int> toUp;
		for(auto thisParty:propParents[node]){
			if(edad[father] <= fiesta[thisParty].second){
				toUp.push(thisParty);
			}
		}

		while(!toUp.empty()){
			propParents[node].erase(toUp.front());
			propParents[father].insert(toUp.front());
			toUp.pop();
		}
	}
}

void propagateChilds(int me, int father, vector<vector<int>> &graph, vector<set<int>> &propParents, ordered_set &propChilds, vector<int> &edad, vector<int> &partyPerNode, map<int,pair<int,int>> &fiesta){
	for(auto party:propParents[me]){
		propChilds.insert(fiesta[party].first);
	}

	//L -> 10 20 30 40, yo = 20
	partyPerNode[me] = propChilds.order_of_key(edad[me]);
	if(propChilds.find(edad[me]) != propChilds.end()){
		partyPerNode[me]++;
	}

	for(auto child:graph[me]){
		if(child != father){
			propagateChilds(child, me, graph, propParents, propChilds, edad, partyPerNode, fiesta);
		}
	}

	for(auto party:propParents[me]){
		propChilds.erase(fiesta[party].first);
	}
}

int main(){
	int n,m; cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> edad(n);
	vector<int> order, myParent(n);

	int e,v;
	for(int u=0; u<n; u++){
		cin >> e >> v;
		v--;
		edad[u] = e;
		graph[u].push_back(v);
		graph[v].push_back(u);
		myParent[u] = v;
	}

	vector<set<int>> propagation(n);
	map<int,pair<int,int>> fiesta; //idEvento -> edad
	
	int org,l,r;
	for(int i=0; i<m; i++){
		cin >> org >> l >> r;
		org--;
		fiesta[i] = {l,r};
		propagation[org].insert(i); 
	}
	
	vector<int> partyPerNode(n,0);
	getOrder(0, graph, order);
	propagateParents(propagation, order, fiesta, edad, myParent);


	ordered_set propChild;
	propagateChilds(0, 0, graph, propagation, propChild, edad, partyPerNode, fiesta);

	for(int i=0; i<n-1; i++){
		cout << partyPerNode[i] << " ";
	}
	cout << partyPerNode[n-1] << endl;

	return 0;
}