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

lli gauss(lli n){
	return (n*(n+1))/2;
}

int main(){
	fast_io
	lli n; cin >> n;
	unordered_map<string,lli> eq;
	lli even = 0, justOneOdd=0;

	string s;
	while(n--){
		cin >> s;
		set<char> oddChars;
		for(auto c:s){
			if(oddChars.count(c) > 0){
				oddChars.erase(c);
			}else{
				oddChars.insert(c);
			}
		}

		string oddString;
		for(auto c:oddChars)
			oddString.push_back(c);
		if(oddString.size() == 0)
			even++;
		else
			eq[oddString]++;
		if(oddString.size() == 1)
			justOneOdd++;
	}

	lli ans = 0;

	if(even > 0) ans += gauss(even-1) + justOneOdd*even;

	for(auto p:eq)
		ans += gauss(p.second-1);

	cout << ans << endl;

	return 0;
}

