//CF Gym 101982D - Count The Bits

#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli dp[130][130][1005];
const lli mod=1e9+9;

lli go(lli pos, lli res, lli ones, lli maxn, lli &k){
    if(pos <= 0)
	if(res == 0)
		return ones;
	else
		return 0;

	if(!maxn && dp[pos][ones][res] != -1)
		return dp[pos][ones][res];

	lli ans=0;
	for(lli i=0; i<=1; i++){
		ans = (ans + go(pos-1, (res*2+i)%k, ones+i, maxn&i, k)) % mod;
	}

	return dp[pos][ones][res] = ans;
}

int main(){
	memset(dp,-1,sizeof(dp));

	lli k,b; cin >> k >> b;
	cout << go(b, 0, 0, 1, k) << endl;

	return 0;
}

