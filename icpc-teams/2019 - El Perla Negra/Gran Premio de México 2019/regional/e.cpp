#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    string s;
    cin>>s;
    int n = s.size(),x;
    cin>>x;
    x = min(x,n);
    lli ans = 0;
    vector<int> until(2*n,0);
    s= s+s;
    bool flag = false;
    for(int i = 0;i<n;i++){
        int cont = 0;
        while(s[i+cont]!='E'){
            if(i+cont>=2*n){flag = true;break;}
            cont++;
        }
        int z;
        if(flag)z = 10000000;
        else z = cont;
        for(int j = 0;j<cont;j++){
            until[i+j] = z;
            z--;
        }
        i = (i+cont);
    }

    for(int i = 0;i<n;i++){
        int pos = x-until[i];
        if(pos<=0)continue;
        else ans += pos;
    }


    cout<<ans<<endl;
    return 0;
}