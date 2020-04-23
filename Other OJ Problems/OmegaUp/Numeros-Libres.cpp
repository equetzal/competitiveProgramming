//https://omegaup.com/arena/problem/Numeros-Libres/

#include <iostream>
#include <cmath>
#include <map>

using namespace std;

typedef unsigned long long int ulli;

map <ulli,ulli> factors;  

void primeFactors(ulli n) { 
    while (n%2 == 0){
    	factors[2]++; 
        n = n/2; 
    } 

    for (int i = 3; i <= sqrt(n); i = i+2){ 
        while (n%i == 0){ 
            factors[i]++;
            n = n/i; 
        } 
    } 
  
    if (n > 2) 
    	factors[n]++;
} 

int gcd(ulli a, ulli b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main(){
	int t; cin >> t;

	while(t--){
		ulli a,b; cin >> a >> b;

		if(gcd(a,b) == 1)
			cout << "SI\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}
