//https://codeforces.com/group/YjFmW2O15Q/contest/101919
//TAP2018 - Fusión de empresas

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, m, x;
	set<int> dif;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		dif.insert(x);
	}

	if(m == 1 && n != 1)
		cout << "1\n";
	else if(dif.size() < m)
		cout << m << "\n";
	else
		cout << "0\n";

	return 0;
}
