#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll N, k, memo[100000][20];

ll bitsOn(ll x) {
	ll cnt = 0;
	while (x) {
		if (x & 1) 
			cnt++;
		x /= 2;
	}
	return cnt;
}

ll dp(ll mask, ll i) {
	
	if (bitsOn(mask) != k && i > 10) return LONG_MAX;
	if (mask > N && bitsOn(mask) == k) return mask;
	if (memo[mask][i] != -1) return memo[mask][i];
	return memo[mask][i] = min(dp(mask | (1LL << i), i + 1), dp(mask, i + 1));
}

int main() {
		
	scanf("%lld %lld", &N, &k);
	memset(memo, -1, sizeof(memo));
	printf("%lld", dp(0, 0));
	return 0;
}