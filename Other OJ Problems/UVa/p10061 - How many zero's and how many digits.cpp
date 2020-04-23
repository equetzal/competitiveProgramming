//UVa p10061 - How many zero's and how many digits

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	lli n, b;

	while(cin >> n >> b){
		double N,B; N = (double)(n); B = (double)(b);
		double p1 = log(N)/log(B) + 1.0;
		cout << p1 << endl;
		lli digits = floor((log(double(n))/log(double(b))) + 1.0);
		cout << digits << endl;
	}

	return 0;
}
