#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T;
	cin >> T;

	while(T--){
		int pI, pF, resi, pares, impares;
		cin >> pI >> pF;

		if((pI%2==0) && (pF%2==1)){
			resi = pF - pI + 1;
			pares = resi/2;
			impares = resi/2;
		}
		if((pI%2==1) && (pF%2==0)){
			resi = pF - pI + 1;
			pares = resi/2;
			impares = resi/2;
		}

		if((pI%2==0) && (pF%2==0)){
			resi = pF - pI + 1;
			impares = resi/2;
			pares = resi-impares;
		}

		if((pI%2==1) && (pF%2==1)){
			resi = pF - pI + 1;
			pares = resi/2;
			impares = resi-pares;
		}

		printf("%d %d\n", pares , impares);
	}

	return 0;
}