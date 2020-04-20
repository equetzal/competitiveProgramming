#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int TC, N, K;
	string line;

	cin >> TC;
	while (getchar() != '\n');
	while (TC--) {
		cin >> N >> K;
		while (getchar() != '\n');
		for (int i = 0; i < N; i++) {
			getline(cin, line);
			for (int i = 0; i < line.size(); i++) {
				if (line[i] >= 'A' && line[i] <= 'Z') {
					char c = (line[i] + (K % 26));
					if (c > 'Z') c -= (91 - 65);
					printf("%c", c);
				}
				else
					printf("%c", line[i]);
			}
			printf("\n");
		}
	}
	return 0;
}