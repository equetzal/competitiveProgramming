//UVa 11080 - Place the Guards

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	int cases;
	cin >> cases;

	while(cases--){
		cout << "--------" << endl;
		int nodos, caminos, n1,n2;
		cin >> nodos >> caminos;
		vector < vector <int> > nodo(nodos);
		for(int i=0; i<caminos; i++){
			cin >> n1 >> n2;
			nodo[n1].push_back(n2);
			nodo[n2].push_back(n1);
		}

		for(int i=0; i<nodos; i++){
			cout << i << " -> ";
			for(auto a:nodo[i]){
				cout << a << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
