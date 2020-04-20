#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int TC, N, ans;
	string str;
	map<string,int> palabras;

	cin >> TC;
	while (TC--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> str;
			sort(str.begin(), str.end());
			palabras[str]++;
		}
		ans = 0;
		for (auto p : palabras) {
			//cout << p.first << " " << p.second << "\n";
			if (p.second > 1) {
				int n = p.second - 1;
				n = (n * (n + 1)) / 2;
				ans += n * 2;
			}
		}
		ans += N;
		printf("%d\n", ans);
		palabras.clear();
	}
	return 0;
}