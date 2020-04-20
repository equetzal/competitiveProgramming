//Nicoleta and the circle of kids - CF Gym 101875A

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long int n, k; cin >> n >> k;
 
	cout << (long long int)((n-1)*k-__gcd(n,k)+1) << endl;
}
