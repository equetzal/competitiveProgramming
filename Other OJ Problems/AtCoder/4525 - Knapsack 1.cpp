//AtCoder 4525 - Knapsack 1

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
lli w[110], v[110];

lli memo[110][100010];
lli dp(int pos, lli weight){
	if(memo[pos][weight] != -1)
		return memo[pos][weight];

	if(pos == 0 || weight == 0)
		return 0;

	if(w[pos] > weight)
		return memo[pos][weight] = dp(pos-1, weight);
	return memo[pos][weight] = max(dp(pos-1, weight), v[pos]+dp(pos-1,weight-w[pos]));
}

int main(){
	int N,W; cin >> N >> W;
	w[0] = v[0] = 0;
	for(int i=1; i<=N; i++)
		cin >> w[i] >> v[i];

	memset(memo, -1, sizeof(memo));
	cout << dp(N, W) << endl;

	return 0;
}

