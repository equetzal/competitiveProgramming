//CF Gym 102191E - Snake Moves
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
	string s; cin >> s;

	map<pair<int,int>,int> lastVisit;
	pair<int,int> pos = make_pair(0,0);//x,y
	int ini = 0, mx = 0;
	lastVisit[pos] = 0;
	for(int i=1; i<=n; i++){
		if(s[i-1] == 'U')
			pos.second++;
		if(s[i-1] == 'D')
			pos.second--;
		if(s[i-1] == 'L')
			pos.first--;
		if(s[i-1] == 'R')
			pos.first++;

		if(lastVisit.count(pos) > 0 && lastVisit[pos] >= ini){
			ini = lastVisit[pos]+1;
		}
		lastVisit[pos] = i;
		mx = max(mx, i-ini);
	}

	cout << mx << endl;

	return 0;
}

