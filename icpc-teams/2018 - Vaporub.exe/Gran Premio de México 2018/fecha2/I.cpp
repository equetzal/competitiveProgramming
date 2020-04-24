#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		int n;
		cin >> n;
		string s;

		vector < vector<int> > graph(n);
		//vector <string> res;

		for(int i=0; i<n; i++){
			int tam; cin >> tam;
			for(int j=0; j<tam; j++){
				int dNode; cin >> dNode;
				graph[i].push_back(dNode);
			}
		}

/*
		for(int i=0; i<n; i++){
			cout << i << "-> ";
			for(auto a:graph[i]){
				cout << a << " ";
			}
			cout << endl;
		}*/

		for(int i=0; i<n; i++)
			s.push_back(i+'0');		

		do {
			vector <bool> visited(n,false);
			//cout << s << ": "<< endl;

			bool sePuede = true;
			for(int i=0; i<n; i++){
				//cout << "checando nodo " << s[i]-'0'<< endl;
				for(auto a:graph[s[i]-'0']){

					if(visited[a] == false){
						sePuede = false;
						break;
					}
				}
				visited[s[i]-'0'] = true;
			}
			if(sePuede){
				cout << s[0];
				for(int i=1; i<n; i++){
					cout << " " << s[i];
				}
				cout << "\n";
				//res.push_back(s);
			}
		}
		while(next_permutation(s.begin(), s.end()));




	}

	return 0;
}