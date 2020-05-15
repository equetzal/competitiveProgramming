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

struct circle
{
	double x , y , r;
};

bool intersec(circle c1 , circle c2)
{
	double dist = sqrt(fabs(c2.x-c1.x)*fabs(c2.x-c1.x) + fabs(c2.y-c1.y)*fabs(c2.y-c1.y));
	double sr = (c1.r+c2.r);
	double dr = fabs(c1.r-c2.r);
	if(dist > sr || dist - dr < 0)
		return false;
	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	double x , y , z;
	cin >> n;
	vector<circle> v(n);
	forn(0,n)
	{
		cin >> v[i].x >> v[i].y >> v[i].r;
	}
	bool f = false;
	forn(0,n-1)
	{
		for(int j = i+1 ; j < n && !f ; ++j)
		{
			f |= intersec(v[i],v[j]);
		}
	}
	if(f)
		cout << "NO\n";
	else
		cout << "SI\n";

	return 0;
}