//CF ProblemSet 864B - Polycarp and Letters

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
	int n; cin >> n;
	set<char> dis;
	string s; cin >> s;
	s += 'A';

	int mx = 0;
	for(auto c:s){
		if(islower(c)){
			dis.insert(c);
		}else{
			mx = max(mx, int(dis.size()));
			dis.clear();
		}
	}

	cout << mx << endl;

	return 0;
}

