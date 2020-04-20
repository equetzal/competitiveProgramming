#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int ans = 0;
	string text, pattern;

	cin >> text >> pattern;
	for (int i = 0; i <= (int)(text.size() - pattern.size()); i++) {
		int j;
		for (j = 0; j < pattern.size(); j++) {
			if (text[i + j] == pattern[j])
				break;
		}
		if (j == pattern.size())
			ans++;
	}
	cout << ans << "\n";
	return 0;
}