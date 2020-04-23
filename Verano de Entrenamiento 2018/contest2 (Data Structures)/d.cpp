//Timus 1146 - Maximum Sum

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n, acum[110][110];

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> acum[i][j];
			if (i > 0) acum[i][j] += acum[i - 1][j];
			if (j > 0) acum[i][j] += acum[i][j - 1];
			if (i > 0 && j > 0) acum[i][j] -= acum[i - 1][j - 1];	
		}
	}

	int maxSum = -1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < n; l++) {
					int sum = acum[k][l];
					if (i > 0) sum -= acum[i - 1][l];
					if (j > 0) sum -= acum[k][j - 1];
					if (i > 0 && j > 0) sum += acum[i - 1][j - 1];
					maxSum = max(maxSum, sum);
				}
			}
		}
	}
	cout << maxSum << "\n";
	return 0;
}
