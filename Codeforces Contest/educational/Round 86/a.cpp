//CF ProblemSet 1342A - Road To Zero

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t; cin >> t;
	while(t--){
		lli x,y,a,b; cin >> x >> y >> a >> b;

		lli ans = min( abs(x-y)*a+min(x,y)*b, x*a+y*a);
		cout << ans << endl;
	}

	return 0;
}
