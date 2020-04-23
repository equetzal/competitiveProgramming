#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void bicolorable(vector< vector<int> > &graph, int startNode){
	vector < pair<bool, char> > bicolorNodes(graph.size(), make_pair(false,'B'));
	queue <int> Q;
	Q.push(startNode);
	bicolorNodes[startNode].second = 'A';

	while(Q.size() != 0){
		// cout << bicolorNodes[Q.front()].second << " ";
		for(int a:graph[Q.front()]){
			if(bicolorNodes[a].first == false){
				bicolorNodes[a].first = true;
				Q.push(a);
				if(bicolorNodes[Q.front()].second == 'A')
					bicolorNodes[a].second = 'R';
				else
					bicolorNodes[a].second = 'A';
			}else{
				if(bicolorNodes[a].second == bicolorNodes[Q.front()].second){
					cout << "NOT BICOLORABLE." << endl;
					return;
				}
			}
		}
		Q.pop();
	}
	cout << "BICOLORABLE." << endl;
}

int main(){
	int nodes, edges, nodeA, nodeB;

	while(cin >> nodes){
		if(nodes == 0)
			break;
		cin >> edges;
		vector < vector <int> > graph(nodes);

		for(int i=0; i<edges; i++){
			cin >> nodeA >> nodeB;
			graph[nodeA].push_back(nodeB);
		}

		bicolorable(graph, 0);
	}
	// cout << endl;
	return 0;
}