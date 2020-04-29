//AtCoder 4522 - Frog 1

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);


lli memo[100001];
lli dp(int pos, vector<int> &v){
	if(pos == v.size()-1)
		return 0;

	if(memo[pos] != -1)
		return memo[pos];

	lli ans = dp(pos+1,v)+abs(v[pos+1]-v[pos]);
	if(pos+2 < v.size())
		ans = min(ans, dp(pos+2,v)+abs(v[pos+2]-v[pos]));

	return memo[pos] = ans;
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x:v) cin >> x;

	memset(memo, -1, sizeof(memo));
	cout << dp(0, v) << endl;

	return 0;
}
