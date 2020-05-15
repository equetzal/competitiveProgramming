//CF ProblemSet 870B - Maximum of Maximums of Minimums

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vari(v); int v; cin >> v;
#define varl(v); lli v; cin >> v;
#define vecn(v,n); vector<lli> v(n);
#define readv(v); for(auto &x:v) cin >> x;
#define readvp(v); for(auto &x:v) cin >> x.first >> x.second;
#define printv(v); for(auto x:v) cout << x << " "; cout << endl;
#define printvp(v); for(auto x:v) cout << "(" <<  x.first << "," << x.second << ")" << endl;
#define multicase(t); lli t; cin >> t; while(t--)

int main(){
	fast_io
	varl(n); varl(k);
	vecn(v,n);
	readv(v);

	lli ans = 0;
	//Si K es 1, siempre es el menor
	if(k == 1){
		cout << *min_element(v.begin(), v.end()) << endl;
	}
	else if(k == 2){ //Si K = 2, es el mejor de los posibles cortes
		cout << max(v[0],v[n-1]) << endl;
	}else{ //Si k es mayor a 2, siempre podremos hacer un subarreglo donde solo este el mas grande
		cout << *max_element(v.begin(), v.end()) << endl;
	}

	return 0;
}

