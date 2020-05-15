//Original by https://codeforces.com/profile/Marckess - Alternating signs
//https://codeforces.com/group/PzLcHnJr9l/contest/275813/problem/F

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vari(v); int v; cin >> v;
#define varl(v); lli v; cin >> v;
#define readv(v); for(auto &x:v) cin >> x;
#define readvp(v); for(auto &x:v) cin >> x.first >> x.second;
#define printv(v); for(auto x:v) cout << x << " "; cout << endl;
#define printvp(v); for(auto x:v) cout << "(" <<  x.first << "," << x.second << ")" << endl;
#define multicase(t); lli t; cin >> t; while(t--)

lli memo[100010][2];

lli dp(int pos, bool mysign, vector<lli> &v){
	if(pos > v.size()-1)
		return 0;

	if(memo[pos][mysign] != -1)
		return memo[pos][mysign];

	if(mysign && v[pos] < 0 || !mysign && v[pos] > 0 || v[pos] == 0){
		return memo[pos][mysign] = dp(pos+1, mysign, v);
	}

	return memo[pos][mysign] = max(v[pos]+dp(pos+1, !mysign, v), dp(pos+1,mysign,v));
}

int main(){
	lli n; cin >> n;
	vector<lli> v(n);
	for(auto &x:v) cin >> x;

	memset(memo, -1, sizeof(memo));
	lli ans = dp(0,true,v);
	memset(memo, -1, sizeof(memo));
	cout <<  max(ans, dp(0,false,v)) << endl;

	return 0;
}

