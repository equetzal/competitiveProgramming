//CF ProblemSet 580A - Kefa and First Steps

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	fast_io
	lli n; cin >> n;
	vector<lli> v(n);
	for(auto &x:v) cin >> x;

	lli mx = 1, cnt = 1;
	for(lli i=1; i<n; i++){
		if(v[i] < v[i-1]){
			mx = max(mx,cnt);
			cnt = 1;
		}else{
			cnt++;
			if(i == n-1)
				mx = max(mx,cnt);
		}
	}

	cout << mx << endl;


	return 0;
}
