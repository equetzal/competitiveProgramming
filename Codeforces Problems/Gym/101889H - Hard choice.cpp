//CF Gym 101889H - Hard choice

#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[3], b[3], c[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    
                c[0] = (b[0]-a[0]);
                c[1] = (b[1]-a[1]);
                c[2] = (b[2]-a[2]);
    
    int ans = 0;
        if(c[0] > 0)
            ans += c[0];
        if(c[1] > 0)
            ans += c[1];
        if(c[2] > 0)
            ans += c[2];

    
    cout << ans << endl;
}
