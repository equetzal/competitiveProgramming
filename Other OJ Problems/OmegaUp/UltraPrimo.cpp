//https://omegaup.com/arena/problem/UltraPrimo/

#include <iostream>
#include <string>
#include <cmath>

//El problema tiene mal sus casos de prueba y considera al numero 1 como un numero primo

using namespace std;

typedef unsigned long long int ulli;

bool isPrime(ulli n){ 
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
}

ulli sumDigits(string &cad){
	ulli sum = 0;
	for(auto c:cad){
		sum += (c-'0');
	}

	return sum;
}

int main(){
	int t; cin >> t;

	while(t--){
		string num; cin >> num;

		ulli res = sumDigits(num);
		if(res == 1 || isPrime(res))
			cout << "UltraPrimo" << endl;
		else
			cout << "No UltraPrimo" << endl;

	}
}
