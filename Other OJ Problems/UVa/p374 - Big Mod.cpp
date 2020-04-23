#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
// Exponenciacion binaria a^n mod m.
lli Exponenciar(lli a, lli n, lli m) {
    lli resultado = 1;
    for (; n; n >>= 1) {
        if (n & 1) resultado = (resultado * a) % m;
        a = (a * a) % m;
    }
    return resultado;
}

int main(){
	lli b,p,m;

	while(cin >> b >> p >> m){
		cout << Exponenciar(b,p,m) << endl;
	}

	return 0;
}