//CF ProblemSet 1335A - Candies and Two Sisters

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		lli n; cin >> n;
		if(n == 0 || n == 1 || n == 2)
			cout << 0 << endl;
		else
			cout << lli((n-1)/2) << endl;
	}

	return 0;
}

