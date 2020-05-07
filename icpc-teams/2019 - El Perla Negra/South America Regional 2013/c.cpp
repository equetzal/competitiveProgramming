#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int lli;
#define endl "\n";

lli cuentaK(lli n, int k){
    lli tam = (1LL<<k);
    //cout << tam << ">" << n << endl;
    if(tam > n)
        return 0;
    n++;
    lli div = n/tam;
    bool isOnOne = bool(div&1);
    lli ones = div/2;
    ones *= tam;
    ones += (n%tam)*lli(isOnOne);
    return ones;
}

lli cuentaUnos(lli n){
    lli suma = 0;
    for(int i=63; i>=0; i--){
        //cout << "k[" << i << "]: " << cuentaK(n,i) << endl;
        suma += cuentaK(n, i);
    }
    return suma;
}

int main(){
    lli a,b; 
    //cout << "28: " << cuentaUnos(28) << endl; 
    while(cin >> a >> b){
        cout << cuentaUnos(b)-cuentaUnos(a-1) << endl;
    }
    
    return 0;
}
