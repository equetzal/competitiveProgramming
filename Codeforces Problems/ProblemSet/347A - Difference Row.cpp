//CF ProblemSet 347A - Difference Row

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x:v)cin >> x;

	sort(v.begin(), v.end());

	cout << v[n-1] << " ";
	for(int i=1; i<(n-1); i++)
		cout << v[i] << " ";
	cout << v[0] << endl;


	return 0;
}
