//CF ProblemSet 1270B - Interesting Subarray

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x:v) cin >> x;

		bool isSol = false;
		for(int i=0; i<(n-1); i++){
			if(abs(v[i]-v[i+1]) >= 2){
				isSol = true;
				cout << "YES" << endl << i+1 << " " << i+2 << endl;
				break;
			}
		}

		if(isSol)
			continue;
		cout << "NO" << endl;
	}


	return 0;
}
