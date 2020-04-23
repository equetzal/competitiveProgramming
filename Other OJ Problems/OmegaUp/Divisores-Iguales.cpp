//https://omegaup.com/arena/problem/Divisores-Iguales/

#include <iostream>
#include <cmath>
#include <map>
using namespace std;

typedef unsigned long long int ulli;

ulli numberOfDivisors(ulli n){
	map <ulli,ulli> factors;  

    while (n%2 == 0){
    	factors[2]++; 
        n = n/2; 
    } 

    for (ulli i = 3; i <= sqrt(n); i = i+2){ 
        while (n%i == 0){ 
            factors[i]++;
            n = n/i; 
        } 
    } 
  
    if (n > 2) 
    	factors[n]++;

    ulli divisors = 1;
    for(auto f:factors){
    	divisors *= (f.second+1);
    }
    if(divisors == 6)
    	for(auto f:factors){
    		cout << "\t" <<  f.first << " " << f.second << endl;
    	}
    return divisors;

}

ulli closestNumber(ulli n, ulli m){ 
    int q = n / m; 
    int n1 = m * q; 
    int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1)); 
    if (abs(n - n1) < abs(n - n2)) 
        return n1; 
    return n2;     
} 

int main(){
	for(int i=1; i<50; i++){
		cout << i << " " << numberOfDivisors(i) << endl;
	}
}
