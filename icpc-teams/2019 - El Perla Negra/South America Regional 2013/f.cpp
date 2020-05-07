#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   ll n , k;
   while(cin >> n >> k)
   {
        ll g = 0 , e = 0, ans = 0 , x , y;
        multiset<ll> p;
    
        for(int i = 0 ; i < n ; i++)
        {
            cin >> x >> y;
            if(x > y)
                ++g;
            else if(x == y)
                ++e;
            else
                p.insert(y-x);
        }
        ans += g*3;
        ll f = min(e,k);
        e -= f;
        k -= f;
        ans += (f*3)+e;
        multiset<ll>::iterator it = p.begin();
        while(k > 0 && it != p.end())
        {
            k -= *it+1;
            it++;
            if(k >= 0)
                ans += 3;
            if(k == -1)
                ans++;
        }
        cout << ans << '\n';
   }
    return 0;
}
