#include <vector>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main(){
	int p, r, c;
	cin >> p >> r >> c;

	vector < pair <int, vector< pair <int,int> > > > ref(r);
	vector < int, vector< pair <int,int> > > pue(p);
	vector <int> lPue(p,0);

	for(int i=0; i<r; i++){
		cin >> ref[i].first;
	}

	for(int i=0; i<p; i++){
		cin >> pue[i].first;
	}

	while(c--){
		int o, d, p;
		cin >> o >> d >> p;

		ref[o-1].second.push_back(make_pair(d-1,p));
		pue[d-1].second.push_back(make_pair(o-1,p));
		lPue[o-1]++;
	}

	for(int i=0; i<lPue.size();i++){
		if(lPue[i]==1){
			if(ref[i].second.second > ref[i].first){
				cout << "-1\n";
				return 0;
			}
			else{
				ref[i] -= ref[i].second.second;
				pue[ref[i].second.first] = 0;
			}	
		}
	}

	queue < pair <int, pair<int,int> > > camiones;

	while(!camiones.empty()){
		
	}

	return 0;
}
