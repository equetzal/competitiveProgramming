#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll fn(vll &v, ll k , ll c , ll n , double t)
{

	 ll ans = 0;
	k = (ll)ceil((double)n/(double)c);
	vll b(c);
	vll ind(c-1);
	for(int i = 0 , j = 0 ; i < n ; i++)
	{
		if(i%k == 0 && i > 0)
		{
			ind[j] = i-1;	
			j++;
		}
		b[j] += v[i];
	}
	bool f = false;

	do
	{
		f = false;
		ll x = 0;
		double y , z;
		double mx;
		while(x < ind.size())
		{
			mx = ceil((double)max(b[x],b[x+1])/(t));
			z = ceil((double)(b[x]+v[ind[x]+1])/t);
			y = ceil((double)(b[x+1]-v[ind[x]+1])/t);
			if(max(z,y) < mx)
			{
				b[x] = b[x]+v[ind[x]+1];
				b[x+1] = b[x+1]-v[ind[x]+1];
				ind[x]++;
				f = true;
				continue;
			}
			z = ceil((double)(b[x]-v[ind[x]])/t);
			y = ceil((double)(b[x+1]+v[ind[x]])/t);
			if(max(z,y) < mx)
			{
				b[x] = b[x]-v[ind[x]];
				b[x+1] = b[x+1]+v[ind[x]];
				ind[x]--;
				f = true;
				continue;
			}
			x++;
		}	
	}while(f);

	for(int i = 0 ; i < b.size() ; i++)
		ans = max(ans,b[i]);
	return (ceil)((double)ans/t);

}


int main(){

ll n, c , t , k;
ll ans1 = 0 , ans2 = 0;
cin >> n >> c >> t;
vll v(n);
for(int i = 0 ; i < n ; i++)
{
	cin >> v[i];
}
	ans1 = fn(v,k,c,n,(double)t);
	reverse(v.begin(),v.end());
	ans2 = fn(v,k,c,n,(double)t);
	cout << min(ans1,ans2) << endl;

	return 0;
}