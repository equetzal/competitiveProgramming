//CF ProblemSet 118D - Caesar's Legions

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define mod 100000000

lli dp[110][110][20][20];
lli go(lli n, lli m, lli f, lli h, lli &orgf, lli &orgh){
	if(n == 0 && m == 0)
		return 1;
	if(n < 0 || m < 0)
		return 0;

	if(dp[n][m][f][h] != -1)
		return dp[n][m][f][h];

	lli sol = 0;
	if(f > 0)
		sol += go(n-1,m,f-1,orgh, orgf,orgh);
	if(h > 0)
		sol += go(n,m-1,orgf,h-1, orgf, orgh);

	sol %= mod;

	return dp[n][m][f][h] = sol;
}


int main(){
	lli n,m; cin >> n >> m;
	lli f,h; cin >> f >> h;

	memset(dp, -1, sizeof(dp));
	cout << go(n,m,f,h,f,h) << endl;

	return 0;
}
