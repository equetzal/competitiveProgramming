//Original by https://codeforces.com/profile/alaneos777 - Having fun with blocks
//https://codeforces.com/group/4Drl6UlALp/contest/264646/problem/E

#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef long long int ll;
typedef vector<ll> Vector;
typedef vector<Vector> Matrix;

Matrix multMatrix(Matrix &a, Matrix &b, ll m) {
	Matrix c(a.size(), Vector(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) {
				c[i][j] += (a[i][k] % m) * (b[k][j] % m);
				c[i][j] %= m;
			}
		}
	}
	return c;
}

Matrix matrixPower(Matrix &a, ll n, ll m) {
	Matrix result(a);
	while (n) {
		if (n & 1)
			result = multMatrix(result, a, m);
		a = multMatrix(a, a, m);
		n >>= 1;
	}
	return result;
}

lli getKthN(Matrix mat, lli m){
	return (mat[1][0]*3+mat[1][1])%m;
}

int main() {
	
	lli k; cin >> k;
	if(k == 1){
		cout << 1 << endl;
		return 0;
	}

	Matrix base(2, Vector(2, 0));

	base[0][0] = 3, base[0][1] = 8;
	base[1][0] = 1, base[1][1] = 3;
	
	lli n = getKthN(matrixPower(base,k-2, 1000000007), 1000000007);
	cout << (n*n)%1000000007 << endl;

	return 0;
}

