//CF Gym 102191B - Final Problem
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
	vector<int> teams(n);
	vector<int> problems(10);
	for(auto &x:teams)cin >> x;
	for(auto &x:problems)cin >> x;
	sort(teams.begin(), teams.end());
	sort(problems.begin(), problems.end());
    if(teams[0]>=problems[0])return cout<<10<<endl,0;
    else return cout<<teams[0]<<endl,0; 
	return 0;
 
}
