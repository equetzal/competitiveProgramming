#include <bits/stdc++.h>
#define xx first;
#define yy second;
#define forn(a,n) for(int i = (a) ; i < (n) ; ++i)
using namespace std;
#define endl "\n"
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n , ans = 0, x;
	cin >> n;
	--n;
	vll v(n);
	cin >> x;
	forn(0,n)
	{
		cin >>  v[i];
	}
	sort(v.begin() , v.end());
	forn(0,n)
		ans += (v[i]-1)*(n-i)+(n-i-1);
	if(ans >= x)
		cout << "NO\n";
	else
		cout << "SI\n";

	return 0;
}