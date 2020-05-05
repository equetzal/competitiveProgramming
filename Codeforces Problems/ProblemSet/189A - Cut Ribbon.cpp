//CF ProblemSet 189A - Cut Ribbon

#include <bits/stdc++.h>

using namespace std;

int n,a,b,c;
int memo[4010];

int dp(int l){
	if(l == 0) return 0;
	if(l > 0 && l < min(a,min(b,c))) return -4005;
	if(l < 0) return -4005;

	if(memo[l] == 0)
		memo[l] = max(dp(l-a), max(dp(l-b), dp(l-c))) + 1;
	return memo[l];
}

int main(){
	memset(memo, 0, sizeof(memo));

	cin >> n >> a >> b >> c;
	cout << dp(n) << endl;
}
