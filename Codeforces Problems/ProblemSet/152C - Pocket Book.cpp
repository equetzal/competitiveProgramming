//CF ProblemSet 152C - Pocket Book

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007

lli mul(lli a, lli b){
	return ((a%MOD)*(b%MOD)%MOD);
}

int main(){
	fast_io

	lli n,m; cin >> n >> m;
	vector<string> v(n);
	for(auto &x:v) cin >> x;

	vector<set<char>> possibleCharsInPos(m);
	for(lli pos=0; pos<m; pos++){
		for(lli i=0; i<n; i++){
			possibleCharsInPos[pos].insert(v[i][pos]);
		}
	}

	lli ans = 1;
	for(auto s:possibleCharsInPos){
		ans = mul(ans,s.size());
	}

	cout << ans << endl;

	return 0;
}
