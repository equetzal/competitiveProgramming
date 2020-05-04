//CF ProblemSet 1335C - Two Teams Composing

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<int,int> freq;

		int val, mx = -1;
		while(n--){
			cin >> val;
			freq[val]++;
			mx = max(mx,freq[val]);
		}

		if(mx == freq.size())
			cout << mx-1 << endl;
		else
			cout << min(mx,int(freq.size())) << endl;
	}

	return 0;
}

