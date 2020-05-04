//CF ProblemSet 1335B - Construct the String

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		lli n, l, k; cin >> n >> l >> k;
		string abc = "abcdefghijklmnopqrstuvwxyz";

		string sL(l,'a');
		for(int i=0; i<l; i++){
			sL[i] = abc[i%k];
		}

		string ans(n,'a');
		for(int i=0; i<n; i++){
			ans[i] = sL[i%l];
		}

		cout << ans << endl;
	}

	return 0;
}

