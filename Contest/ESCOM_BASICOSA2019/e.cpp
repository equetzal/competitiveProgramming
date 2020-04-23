//CF ProblemSet 682B - Alyona and Mex

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x:v) cin >> x;

	sort(v.begin(), v.end());
	int mn = 1;

	for(auto x:v)
		if(x >= mn)
			mn++;

	cout << mn << endl;


	return 0;
}
