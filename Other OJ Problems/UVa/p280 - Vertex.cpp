//UVa p280 - Vertex

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

void bfs(vector < vector <int> > &graph, int caseNode){
	int notReachableNodes = 0;
	vector <bool> reachedNode(graph.size(),false);
	queue <int> Q;
	Q.push(caseNode);

	while(Q.size() != 0){
		for(int a:graph[Q.front()-1]){
			if(reachedNode[a-1] == false){
				Q.push(a);
				reachedNode[a-1] = true;
			}
		}
		Q.pop();
	}

	for(int i=0; i<graph.size(); i++)
		if(reachedNode[i] == false)
			notReachableNodes++;

	cout << notReachableNodes ;

	for(int i=0; i<graph.size(); i++)
		if(reachedNode[i] == false)
			cout << " " << i+1;
	cout << "\n";
}

int main(){
	int nodes, actNode, conectionNode, caseNode, testCases;
	cin >> nodes;

	do{
		if(nodes == 0)
			break;

		vector < vector <int> > graph(nodes);

		//Lectura y construccion del grafo
		while(cin >> actNode){
			if(actNode == 0)
				break;
			while(cin >> conectionNode){
				if(conectionNode == 0)
					break;
				graph[actNode-1].push_back(conectionNode);
			}
		}

		//Lectura de casos de prueba
		cin >> testCases;
		for(int i=0; i<testCases; i++){
			cin >> caseNode;
			bfs(graph, caseNode);
		}

	}while(cin >> nodes);


}
