#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){

	double a , b , c;
	cin >> a >> b;
	c = (10.0*a*b)/100.0;
	double sum=0.0; 
	for(int i=1; i<10; i++){
		sum += c;
		cout << (ll)ceil(sum) << ((i == 9)?'\n':' '); 
	}


	return 0;
}