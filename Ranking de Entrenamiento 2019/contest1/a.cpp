//CF Gym 101875A - Nicoleta and the circle of kids

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long int n, k; cin >> n >> k;
 
	cout << (long long int)((n-1)*k-__gcd(n,k)+1) << endl;
}