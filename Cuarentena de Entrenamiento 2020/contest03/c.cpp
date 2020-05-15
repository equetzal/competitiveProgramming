//CF ProblemSet 749A - Bachgold Problem

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	fast_io
	lli n; cin >> n;

	lli k = floor(n/2);
	cout << floor(n/2) << endl;

	if(n&1){
		cout << 3 << " ";
		k--;
	}

	while(k--) cout << 2 << " ";
	cout << endl;

	return 0;
}
