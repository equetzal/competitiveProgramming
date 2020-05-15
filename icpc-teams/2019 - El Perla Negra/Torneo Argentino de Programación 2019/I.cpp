#include <bits/stdc++.h>
#define xx first
#define yy second
#define forn(a,n) for(int i = (a) ; i < (n) ; ++i)
using namespace std;
#define endl "\n"
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n , m , q;
	ll a , b , k;
	cin >> n >> m >> q;
	++n;

	vector<map<ll,ll> > v1(n);
	
	vvll m1(n,vll(n));
//	cout << n << ' ' << m << ' ' << q << "  K\n";
	while(m--)
	{
		cin >> k >> a >> b;
	//	cout << a << ' ' << b << ' ' << k << "  K\n";
		v1[a][b]++;
		v1[b][a]++;
		if(a+k >= n || b+k >= n)
			continue;
		v1[a+k][b+k]++;
		v1[b+k][a+k]++;
	}

	map<ll,ll>::iterator it;
	forn(0,n)
	{
		for(it = v1[i].begin() ; it != v1[i].end() ; it++)
		{
			m1[i][it->xx] = it->yy;
			m1[it->xx][i] = it->yy;

		}
	}
	for(int x = 1 ; x < n ; x++)
	{
		for(int y = 1 ; y < n ; y++)
		{
			m1[x][y] += m1[x-1][y-1];
			m1[x][y] %= 2;
		}
	}

	while(q--)
	{
		cin >> a >> b;
		if(m1[a][b])
			cout << "SI\n";
		else
			cout << "NO\n";
	}


	return 0;
}