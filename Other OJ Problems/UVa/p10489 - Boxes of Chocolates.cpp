//UVa p10489 - Boxes of Chocolates

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli Multiplicar(lli a, lli b, lli m) {
    lli resultado = 0;
    for (; b; b >>= 1) {
        if (b & 1) resultado = (resultado + a) % m;
        a = (a + a) % m;
    }
    return resultado;
}


int main(){
	int t; cin >> t;
	while(t--){
		int m,c; cin >> m >> c;
		lli sum = 0;
		while(c--){
			int cajas; cin >> cajas;
			lli val = 1;
			while(cajas--){
				lli a; cin >> a;
				val = Multiplicar(val,a,m);
			}
			sum += val;
			sum %= m;
		}
		cout << sum << endl;
	}
	return 0;
}
