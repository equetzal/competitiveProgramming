#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x:v) cin >> x;

	int mx = 100;
	int curr = 100;
	for(auto x:v){
		curr += x;
		mx = max(mx, curr);
	}

	cout << mx << endl;

	return 0;
}
