#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
int n, c, t1, t2;
int a[1005];
 
int dp[1005];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
 
	cin >> n >> c >> t1 >> t2;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
 
	int sol = 123123123;
 
	for (int i=0; i<n; i++) {
 
		memset(dp, 63, sizeof(dp));
		dp[0] = 0;
		for (int j=1; j<=n; j++) {
			int x = a[j-1];
			auto it1 = lower_bound(a, a+n, x - t1) - a;
			auto it2 = lower_bound(a, a+n, x - t2) - a;
			dp[j] = min(dp[it1] + t1, dp[it2] + t2);
		}
 
		sol = min(sol, dp[n]);
 
		rotate(a, a+1, a+n);
		a[n-1] += c;
	}
 
	cout << sol << '\n';
}