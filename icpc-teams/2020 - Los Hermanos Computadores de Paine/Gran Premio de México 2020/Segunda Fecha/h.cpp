#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef unsigned long long int lli;

unordered_map<lli,lli> memo[51][51];
lli a,b,n,k;

inline bool isValid(lli sum){
	if(sum < a || sum > b)
		return false;
	return true;
}

int dp(int pos, int taken, lli sum, vector<lli> &arr){
	if(taken == k && isValid(sum)){
		return 1L;
	}
	if(pos >= n){
		return 0L;
	}
	if(memo[pos][taken].find(sum) != memo[pos][taken].end())
		return memo[pos][taken][sum];

	lli sol = 0;
	sol += dp(pos+1, taken, sum, arr);
	if(arr[pos] <= b - sum){
		sol += dp(pos+1, taken+1, sum+arr[pos], arr);
	}

	return memo[pos][taken][sum] = sol;
}

int main(){
	fast_io
	cin >> n >> k;
	vector<lli> arr(n);
	for(auto &x:arr) cin >> x;
	cin >> a >> b;

	cout << dp(0,0,0,arr) << endl;
	return 0;
}

