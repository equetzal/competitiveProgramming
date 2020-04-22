//CF ProblemSet 192A - Funky Numbers

#include <iostream>

using namespace std;

typedef long long int lli;

lli eq(lli n){
	return (n*(n+1))/2;
}

lli k2(lli n, lli k1){
	lli mn = 0;
	lli mx = 50000;
	lli K1 = eq(k1);

	int it = 32;
	while(it--){
		lli md = (mn+mx)/2;
		lli K2 = eq(md);

		lli K = K1+K2;

		if(K==n)
			return -1;
		else if(K < n)
			mn = md;
		else
			mx = md;
	}

	return mx;
}

bool k1(lli n){
	lli mn = 0;
	lli mx = 50000;

	int it = 32;
	while(it--){
		lli md = (mn+mx)/2;

		lli K1 = eq(md);
		lli K2 = k2(n,md);

		if(K2 == -1)
			return true;
		else if(K1 < n)
			mn = md;
		else
			mx = md;
	}

	return false;
}

int main(){
	lli n; cin >> n;

	if(k1(n))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
