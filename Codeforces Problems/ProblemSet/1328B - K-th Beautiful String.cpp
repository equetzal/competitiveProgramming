//CF ProblemSet 1328B - K-th Beautiful String

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

lli gauss(lli n){
	return (n*(n-1))/2;
}

lli findBlock(lli k){
	lli lo = 1, hi = 100000;
	lli mi = (lo+hi)/2;

	int it = 32;
	while(it--){
		if(gauss(mi) < k)
			lo = mi;
		else
			hi = mi;
		mi = (lo+hi)/2;
	}
	return lo;
}

int main(){
	fast_io

	int t; cin >> t;
	while(t--){
		lli n,k; cin >> n >> k;
		lli block = findBlock(k);
		lli el = k-gauss(block);

		string ans;
		for(lli i=0; i<n; i++)
			ans.push_back('a');
		ans[ans.size()-el] = 'b';
		ans[ans.size()-(block+1)] = 'b';

		cout << ans << endl;
	}

	return 0;
}
