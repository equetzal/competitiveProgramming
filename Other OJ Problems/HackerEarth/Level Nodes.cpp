//HackerEarth - Level Nodes

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int c=0;

void bfs(vector < pair < vector <int>,bool > > &tree, int level, int currentLevel, int node){
	// cout << "--------------------------- lvl " << currentLevel << endl;
	queue< pair <int, int> > Q;
	Q.push(make_pair(node,1));
	tree[Q.front().first-1].second = true;

	while(Q.size() != 0){
		if(level == Q.front().second){
			c++;
		}
		if(Q.front().second > level){
			return;
		}

		for(auto a:tree[Q.front().first-1].first){
			if(tree[a-1].second == false){
				tree[a-1].second = true;
				Q.push(make_pair(a,Q.front().second+1));
			}
		}
		Q.pop();
	}
}

int main(){
	int N, x;
	cin >> N;

	vector < pair < vector <int> , bool > > node (N);

	int fn, sn;

	for(int i=0; i<N; i++){
		node[i].second = false;
	}

	for(int i=1; i<N; i++){
		cin >> fn >> sn;
		node[fn-1].first.push_back(sn);
		node[sn-1].first.push_back(fn);
	}

	// for(int i=0; i<N; i++){
	// 	cout << "Nodo " << i+1 << " [" << node[i].second << "]: ";
	// 	sort(node[i].first.begin(),node[i].first.end());
	// 	for(auto a:node[i].first){
	// 		cout << a << ", ";
	// 	}
	// 	cout << endl;
	// }


	cin >> x; 
	bfs(node, x, 1, 1);
	// cout << "Level: " << x << " ans: " << c << endl;
	cout << c << "\n";

	// for(int i=0; i<8; i++){
	// 	bfs(node, i, 1, 1);
	// 	// cout << "Level: " << x << " ans: " << c << endl;
	// 	cout << c << "\n";
	// }



	return 0;
}
