//Kattis Open cocoacoalition - Cocoa Coalition
//NCPC 2019
//Los Hermanos Computadores de Paine - Coded by Quetzalli

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define endl "\n"

int main(){
	lli n,m,a; cin >> n >> m >> a;
	if(a%n == 0 || a%m == 0){
		cout << 1 << endl;
	}else{
		bool isPossible = false;
        for(lli i = 1; i<=n; i++){
            if(a%i == 0 && a/i < m){
                isPossible = true;
            }
        }
		a = n*m-a;
		for(lli i = 1; i<=n; i++){
            if(a%i == 0 && a/i < m){
                isPossible = true;
            }
        }
		if(isPossible)
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}

	return 0;
}
