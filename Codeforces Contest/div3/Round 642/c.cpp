//CF Problemset 1353C - Board Moves

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t; cin >> t;
	while(t--){
		lli n; cin >> n;
		n = floor(n/2)+1;

		lli sum4 = 0;
		for(lli i=0, m=1; i<n; i++, m+=2){
			sum4 += i*m;
		}

		sum4 -= (n*(n-1))/2;

		lli sum = 4*sum4;
		cout << sum << endl;
	}

	return 0;
}
