//CF ProblemSet 755B - PolandBall and Game

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, count = 1;
	string tmp;
	set<string> palabras;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		palabras.insert(tmp);
	}
	int remW = m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (palabras.find(tmp) != palabras.end()) {
			if (count % 2 == 0)
				n--;
			else
				remW--;
			count++;
		}
		else {
			palabras.insert(tmp);
		}
	}
	if (n > remW)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
