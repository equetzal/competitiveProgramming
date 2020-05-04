//CF ProblemSet 1343B - Balanced Array

#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;


int main(){
	int t; cin >> t;
	while(t--){
		lli n; cin >> n;
		if((n/2)%2 == 1){
			cout << "NO" << endl;
			continue;
		}else{
			cout << "YES" << endl;
			for(int i=1; i<=n/2; i++)
				cout << 2*i << " ";
			for(int i=1; i<n/2; i++)
				cout << 2*i-1 << " ";
			cout << 2*(n/2)-1+(n/2) << endl;
		}
	}
	return 0;
}
