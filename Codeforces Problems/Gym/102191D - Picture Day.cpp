//CF Gym 102191D - Picture Day
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//PSUT Coding Marathon 2019
//Los Hermanos Computadores de Paine

#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	int n; cin >> n;
	vector<pair<int,int>> v(n/2);
	for(auto &x:v){
		cin >> x.first >> x.second;
		if(x.second > x.first)
			swap(x.first, x.second);
	}

	sort(v.rbegin(), v.rend());

	list<int> ans;
	bool isPossible = true;
	for(auto p:v){
		if(ans.size() == 0 || ans.back() >= p.first){
			ans.push_back(p.first);
			ans.push_back(p.second);
		}else if(ans.front() >= p.first){
			ans.push_front(p.first);
			ans.push_front(p.second);
		}else{
			isPossible = false;
		}
	}

	if(!isPossible){
		cout << -1 << endl;
		return 0;
	}
	for(auto x:ans)
		cout << x << " ";
	cout << endl;

	return 0;
}

