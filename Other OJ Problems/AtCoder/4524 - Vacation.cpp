//AtCoder 4524 - Vacation

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int hap[100001][3];
int memo[100001][3];
int n;

lli dp(int act, int pos){
	if(pos == n-1)
		return hap[pos][act];

	if(memo[pos][act] != -1)
		return memo[pos][act];

	lli ans = hap[pos][act];
	if(pos+1 < n)
		ans += max(dp((act+1)%3,pos+1), dp((act+2)%3,pos+1));
	return memo[pos][act] = ans;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> hap[i][0] >> hap[i][1] >> hap[i][2];

	memset(memo, -1, sizeof(memo));
	lli mx = dp(0, 0);
	memset(memo, -1, sizeof(memo));
	mx = max(mx, dp(1,0));
	memset(memo, -1, sizeof(memo));
	mx = max(mx, dp(2,0));

	cout << mx << endl;
	return 0;
}
