//CF ProblemSet 797B - Odd sum

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vari(v); int v; cin >> v;
#define varl(v); lli v; cin >> v;
#define readv(v); for(auto &x:v) cin >> x;
#define readvp(v); for(auto &x:v) cin >> x.first >> x.second;
#define printv(v); for(auto x:v) cout << x << " "; cout << endl;
#define printvp(v); for(auto x:v) cout << "(" <<  x.first << "," << x.second << ")" << endl;
#define multicase(t); lli t; cin >> t; while(t--)

int main(){
	fast_io

	lli n; cin >> n;
	vector<lli> v(n);
	for(auto &x:v) cin >> x;

	lli mnPos = 400010, mnNeg = -400010;
	lli sum = 0;
	for(auto i:v){
		if(i%2){
			if(i > 0)
				mnPos = min(mnPos, i);
			else if(i < 0)
				mnNeg = max(mnNeg, i);
		}
		if(i > 0)
			sum += i;
	}

	if(sum%2)
		cout << sum << endl;
	else
		cout << sum-min(mnPos, abs(mnNeg)) << endl;

	return 0;
}

