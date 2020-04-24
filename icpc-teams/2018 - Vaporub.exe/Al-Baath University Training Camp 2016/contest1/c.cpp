//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028C - A or B Equals C

#include <bits/stdc++.h>

using namespace std;

long long int Exponenciar(long long int a, long long int n, long long int m) {
    long long int resultado = 1;
    for (; n; n >>= 1) {
        if (n & 1) resultado = (resultado * a) % m;
        a = (a * a) % m;
    }
    return resultado;
}

int main(){
	int t;  cin >> t;
	while(t--){
		int len; cin >> len;
		string A, B; cin >> A >> B;

		bool impossible = false;
		int match = 0;
		for(int i=0; i<len; i++){
			if(A[i] == '1' && B[i] == '0')
				impossible = true;
			if(A[i] == '1' && B[i] == '1')
				match++;
		}

		if(impossible)
			cout << "IMPOSSIBLE\n";
		else
			cout << Exponenciar(2,match, 1000000007) << "\n";
	}
	return 0;
}
