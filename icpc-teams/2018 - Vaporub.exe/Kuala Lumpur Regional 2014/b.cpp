//UVaLive p6801 - Sequence 

#include <stdio.h>
#include <string.h>

typedef __int128 ll;
const ll mod = 1e9 + 7;

long long int n, k;
ll memo[1110][1110];

ll dp(long long int i, long long int unos) {
	ll ceros = n - unos;
	if (i == 0 && unos == 0) return 1;
	if (i == 0 && unos != 0) return 0;
	if (memo[i][unos] != -1) return memo[i][unos];

	ll ans = 0;		
	if (unos < n)
		ans = (ans%mod + (ceros*dp(i-1, unos+1))%mod)%mod;
	if (unos > 0)
		ans = (ans%mod + (unos*dp(i-1, unos-1))%mod)%mod;
	ans%=mod;
	return memo[i][unos] = ans;
}

int main() {
	long long int TC, c, i, unos, cases = 0;

	scanf("%lld", &TC);
	while (TC--) {
		scanf("%lld %lld", &n, &k);
		unos = 0;
		for (i = 0; i < n; i++) {
			scanf("%lld", &c);
			if (c == 1) unos++;
		}
		memset(memo, -1, sizeof(memo));
		long long int ans = dp(k, unos);
		printf("Case #%lld: %lld\n", ++cases, ans);
	}
	return 0;
}
