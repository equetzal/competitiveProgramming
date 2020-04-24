#include <bits/stdc++.h>
using namespace std;

struct robot 
{
	int x, r, q;
	bool operator<(const robot &otro) {
		return x < otro.x;
	}
};

int main() {
	int n, k, ans;
	vector<robot> v;

	cin >> n >> k;
	v.assign(n, (robot){0,0,0});
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].r >> v[i].q;
	}
	ans = 0;
	int left = 0, right = 1;
	while (left != v.size()) {
		
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; v[i].x + v[i].r <= v[j].x; j++) {

		}
	}
	return 0;
}
