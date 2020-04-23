#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <chrono>

using namespace std;

bool visited[1003][1003];
char doc[1003][1003];
vector< pair<int,int> > pattern;
vector< pair<int,int> > ink;


inline void getPatternOfSeal(vector< vector<char> > &seal){
	bool firstFound = false;

	int x,y;
	for(int i=0; i<seal.size(); i++){
		for(int j=0; j<seal[i].size(); j++){
			// cout << seal[i][j] << " ";
			if(seal[i][j] == 'x'){ //If X
				if(!firstFound){
					pattern.push_back(make_pair(0,0));
					x = i;
					y = j;
					firstFound = !firstFound;
				}else{
					pattern.push_back(make_pair(i-x, j-y));
				}
			}
		}
		// cout << endl;
	}

	// cout << endl;
}

inline bool isValid(int n, int m, int x, int y){
	if(x >= n || y >= m)
		return false;
	if(x < 0 || y < 0)
		return false;

	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	auto start_time = std::chrono::high_resolution_clock::now();

	int cases; cin >> cases;

	while(cases--){
		// cout << "CASE: " << endl;
		int n,m,a,b; cin >> n >> m >> a >> b;
		vector< vector<char> > seal(a, vector<char>(b));

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> doc[i][j];
			}
		}

		for(int i=0; i<a; i++){
			for(int j=0; j<b; j++){
				char c; cin >> seal[i][j];
			}
		}
			

		memset(visited, false, sizeof(visited));
		pattern.clear();
		ink.clear();
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(doc[i][j] == 'x'){
					ink.push_back(make_pair(i,j));
				}
			}
		}

		getPatternOfSeal(seal);
		int totalVisited = 0;
		for(auto i:ink){
			// cout << "checando " << i.first << " " << i.second << endl;
			if(!visited[i.first][i.second]){	
				bool isPrintable = true;
				for(auto p:pattern){
					// cout << "consultado (" << i.first + p.first << "," << i.second + p.second << ")" << endl;
					if(isValid(n,m, i.first + p.first, i.second + p.second)){
						if(visited[i.first + p.first][i.second + p.second] || doc[i.first + p.first][i.second + p.second] == '.'){
							isPrintable = false;
						}
					}
					else{
						isPrintable = false;
					}
				}
				if(isPrintable){
					// cout << "es imprimible" << endl;
					totalVisited += pattern.size();
					for(auto p:pattern)
						visited[i.first + p.first][i.second + p.second] = true;
				}
			}
		}

		if(totalVisited == ink.size())
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}
	auto end_time = std::chrono::high_resolution_clock::now();
  	auto time = end_time - start_time;

  	cout << "time: " << time/std::chrono::microseconds(1) << "ms" << endl;

	return 0;
}