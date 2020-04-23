#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

vector< vector<int> > graph, scc;
vector<int> dfs_low, dfs_num, Stack;
vector<bool> visited;
int dfsContador, numSCC;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsContador++;
	Stack.push_back(u);
	visited[u] = 1;

	for(int i = 0; i<graph[u].size(); i++){
		int v = graph[u][i];
		if(dfs_num[v] == -1)
			tarjanSCC(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]){
		numSCC++;
		vector<int> component;

		while(true){
			int v = Stack.back();
			Stack.pop_back();
			visited[v] = 0;
			component.push_back(v);
			if(u == v) break;
		}

		scc.push_back(component);
	}
}

void printGraph(vector< vector<int> > &graph){
	cout << "--------- Graph ---------" << endl;
	for(int  i=0; i<graph.size(); i++){
		cout << i+1 << " -> ";
		for(int j:graph[i])
			cout << j+1 << " ";
		cout << endl;
	}
	cout << "-------------------------" << endl;

}

vector< vector<int> > reconstructGraph(vector< vector<int> > graph, vector< vector<int> > components){
	map<int,int> equivalent; //Viejo Nodo -> Nuevo Nodo
	for(int i=0; i<components.size();i++){
		for(int node:components[i]){
			equivalent[node] = i;
		}
	}

	vector< vector<int> > resGraph(components.size());
	vector< set<int> > preGraph(components.size());
	for(int i=0; i<graph.size(); i++){
		for(int j:graph[i]){
			preGraph[equivalent[i]].insert(equivalent[j]);
		}
	}

	for(int i=0; i<preGraph.size(); i++){
		for(auto e:preGraph[i]){
			if(i != e)
				resGraph[i].push_back(e);
		}
	}


	return resGraph;
}

// int dfs_search(vector < vector<int> > &graph, int pos, vector<bool> &visited){
// 	if(graph[pos].empty())
// 		return pos;

// 	for(int i = 0; i<graph[pos].size(); i++){
// 		if(!visited[graph[pos][i]]){
// 			visited[graph[pos][i]] = true;
// 			dfs_search(graph, graph[pos][i], visited);
// 		}
// 	}
// 	return -1;
// }

// int dfs(vector< vector<int> > &graph, int pos){
// 	vector<bool> visited(graph.size(), false);
// 	visited[pos] = true;

// 	for(int i = 0; i<graph.size(); i++){
// 		int val = dfs_search(graph, i, visited);
// 		if(val != -1)
// 			return val;
// 	}

// 	return -1;
// }

// void linkComponents(vector< vector<int> > &graph){
// 	vector< vector<int> > reversedGraph(graph.size());
// 	for(int i=0; i<graph.size(); i++){
// 		for(int j:graph[i]){
// 			reversedGraph[j].push_back(i);
// 		}
// 	}
// 	cout << "//Reversed graph" << endl;
// 	printGraph(reversedGraph);

// 	int aNode = dfs(reversedGraph, 0);
// 	int bNode = dfs(graph, aNode);

// 	graph[bNode].push_back(aNode);

// 	return;
// }

// int solve(){
// 	int ans=0; 

// 	while(graph.size() > 1){
// 		dfsContador=0, numSCC=0;
// 		for(int i=0;  i<graph.size(); i++){
// 			if(dfs_num[i] == -1)
// 				tarjanSCC(i);
// 		}
// 		graph = reconstructGraph(graph, scc);
// 	}

// 	return ans;
// }

vector< vector<int> > reverseGraph(vector< vector<int> > &graph){
	vector< vector<int> > reversedGraph(graph.size());
	for(int i=0; i<graph.size(); i++){
		for(int j:graph[i]){
			reversedGraph[j].push_back(i);
		}
	}

	return reversedGraph;
}
int main(){
	int nodes, edges; cin >> nodes >> edges;

	graph.resize(nodes); dfs_low.resize(nodes); 
	dfs_num.resize(nodes,-1); Stack.resize(nodes);
	visited.resize(nodes, false);

	//Leemos el grafo
	for(int i=0; i<edges; i++){
		int a,b; cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
	}

	// printGraph(graph);

	//Iniciamos Tarjan para obtener las Componentes Fuermente Conexas
	dfsContador=0, numSCC=0;
	for(int i=0;  i<nodes; i++){
		if(dfs_num[i] == -1)
			tarjanSCC(i);
	}

	graph = reconstructGraph(graph, scc);
	vector< vector<int> > reversedGraph = reverseGraph(graph);

	int in=0, out=0;
	for(int i = 0; i<graph.size(); i++){
		if(graph[i].empty())
			out++;
		if(reversedGraph[i].empty())
			in++;
	}

	if(graph.size() == 1)
		cout << 0 << endl;
	else
		cout << max(in,out) << endl;


	// printGraph(scc);

	// printGraph(ansGraph);
	// linkComponents(ansGraph);

	// cout << "Linked components" << endl;
	// printGraph(ansGraph);
	// return 0;
}