#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n , k;
	cin >> n >> k;
		ll unos = 0 , ceros = 0 , z , x = 0 , ans;
		ll t = 0;
		bool f = true;
		for(int i = 63 ; i >= 0 ; i--)
		{
			if((((ll)1<<i)&n)==0)
				continue;
			else
			{
				x = i;
				break;
			}
		}
		for(int i = x ; i >= 0 ; i--)
		{
			if((((ll)1<<i)&n)!=0)
			{
				t++;
			}else
			{
				z = i;
				f = false;
				unos += t;
				t = 0;
			}
		}
		if(!f)
		{
			if(unos >=  k)
			{
				x++;
				ans = ((ll)1<<x);
				k--;
				for(int i = 0 ; i < k ; i++)
				{
					ans += ((ll)1<<i);
				}
			}else
			{
				for(int i = z-1 ; i >= 0 ; i--)
				{
					if((((ll)1<<i)&n)==0)
					{
						ceros++;
						z--;
					}else
					{
						break;
					}
				}
				ans = n+((ll)1<<z);
				for(int i = z-1 ; i >= 0 ; i--)
				{
					if((((ll)1<<i)&ans)!=0)
						ans -= ((ll)1<<i);
				}
				for(int i = 0 , j = 0 ; j < k-unos-1;i++)
				{
					if((((ll)1<<i)&ans)!=0)
						continue;
					ans += ((ll)1<<i);
					j++;

				}
			}
		}else
		{
			x++;
			ans = ((ll)1<<x);
			k--;
			for(int i = 0 ; i < 63 && k > 0 ; i++)
			{
				if((((ll)1<<i)&ans)!=0)
						continue;
				ans += ((ll)1<<i);
				k--;
			}
		}
		cout << ans << '\n';
	
		
	
	return 0;
}
