//CF Problemset 1353B - Two Arrays And Swaps

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t; cin >> t;
	while(t--){
		int n,k; cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);

		for(auto &x:a) cin >> x;
		for(auto &x:b) cin >> x;

		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());

		int i=0, j=0;
		while(k--){
			if(b[i] > a[j]){
				a[i] = b[j];
				i++, j++;
			}
		}

		int sum = 0;
		for(auto x:a)
			sum += x;
		cout << sum << endl;
	}

	return 0;
}
