#include <bits/stdc++.h>
using namespace std;

struct espectaculo {
	int horaI, horaF, canciones, id;
	bool operator<(espectaculo otro) {
		if (horaI < otro.horaI)
			return true;
		else if (horaI == otro.horaF){
			if (horaF < otro.horaF)
				return true;
			else
				return false;
		}
		else {
			return false;
		}

	}
};

int N, k;
vector<espectaculo> v;
int memo[1010][1 << 11];

int next(int idx) {

	for (int i = idx; i < N; i++) {
		if (v[i].horaI >= v[idx].horaF)
			return i;
	}
	return N;
}

int dp(int idx, int mask){
	
	if (idx == N && mask == (1 << k) - 1) return 0;
	if (idx == N && mask != ((1 << k) - 1)) return -1e9;
	if (memo[idx][mask] != -1) return memo[idx][mask];
	return memo[idx][mask] = max(dp(next(idx), mask | 1 << (v[idx].id)) + v[idx].canciones, dp(idx + 1, mask));
}

int main() {
	
	int x, a, b, c;

	cin >> k;
	N = 0;
	for (int i = 0; i < k; i++) {
		cin >> x;
		N += x;
		for (int j = 0; j < x; j++) {
			cin >> a >> b >> c;
			v.push_back({a,b,c,i});
		}
	}
	sort(v.begin(), v.end());
	memset(memo, -1, sizeof(memo));
	int ans = dp(0, 0);
	if (ans <= 0)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}