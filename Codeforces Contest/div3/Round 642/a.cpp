//CF Problemset 1353A - Most Unstable Array

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t; cin >> t;
	while(t--){
		lli n,m; cin >> n >> m;

		if(n == 1){
			cout << 0 << endl;
			continue;
		}
		if(n == 2){
			cout << m << endl;
			continue;
		}
		if(n >= 3){
			cout << 2*m << endl;
			continue;
		}

	}

	return 0;
}
