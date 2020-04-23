#include <iostream>

using namespace std;

long long int binPow[32];

int main(){
	binPow[0] = 0;
	for(int k=1; k<=30; k++){
		long long int sum = ((long long int)(1<<k)-1)*(1<<k)/2;
		binPow[k] = binPow[k-1] +  sum;
	}

	long long int n; cin >> n;

	int k=0;
	for(int i=n, c=0; i>0; i=(i>>1), c++){
		if(i&1)
			k = c;
	}

	long long int add = n - (1<<k);
	add = (add)*(add+1)/2;
	cout << binPow[k-1]+add << endl;
}