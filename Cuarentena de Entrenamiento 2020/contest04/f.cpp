//CF ProblemSet 1009A - Game Shopping

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vari(v); int v; cin >> v;
#define varl(v); lli v; cin >> v;
#define vecn(v,n); vector<lli> v(n);
#define readv(v); for(auto &x:v) cin >> x;
#define readvp(v); for(auto &x:v) cin >> x.first >> x.second;
#define printv(v); for(auto x:v) cout << x << " "; cout << endl;
#define printvp(v); for(auto x:v) cout << "(" <<  x.first << "," << x.second << ")" << endl;
#define multicase(t); lli t; cin >> t; while(t--)

int main(){
	varl(n); varl(m);
	vecn(games,n);
	vecn(wallet,m);
	readv(games);
	readv(wallet);

	lli ans = 0;
	for(int i=0, j=0; i<n && j<m; i++){
		if(games[i] <= wallet[j]){
			ans++;
			j++;
		}
	}

	cout << ans << endl;

	return 0;
}

