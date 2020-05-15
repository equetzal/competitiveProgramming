//CF ProblemSet 782A - Andryusha and Socks

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
	set<int> table;
	int n; cin >> n;

	int sock, ans = 0;
	for(int i=0; i<2*n; i++){
		cin >> sock;
		if(table.count(sock) > 0){
			table.erase(sock);
		}else{
			table.insert(sock);
		}
		ans = max(ans,int(table.size()));
	}

	cout << ans << endl;

	return 0;
}

