//CF ProblemSet 779B - Weird Rounding

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
	string s; cin >> s;
	int k; cin >> k;
	int zeroes = 0;

	for(auto c:s)
		if(c == '0') zeroes++;

	if(s.size() == 1 && zeroes == 0){
		cout << 0 << endl;
		return 0;
	}

	if(zeroes < k && zeroes != 0){
		cout << s.size()-1 << endl;
		return 0;
	}

	int subK = 0, ans = 0;
	for(int i=s.size()-1; i>=0; i--){
		if(s[i] == '0') subK++;
		else ans++;

		if(subK >= k)
			break;
	}

	cout << ans << endl;

	return 0;
}

