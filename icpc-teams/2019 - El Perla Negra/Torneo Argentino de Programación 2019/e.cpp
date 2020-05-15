#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
typedef long long int lli;

int main(){
	lli tA,tB; cin >> tA >> tB;
	lli oA, oB; cin >> oA >> oB;

	pair<lli,lli> A,B;
	A.first = (oA*tB)+(oB*tA);
	A.second = (tA*tB*2);
	B.first = oA+oB;
	B.second = tA+tB;

	lli gcd = __gcd(A.first,A.second);
	A.first /= gcd;
	A.second /= gcd;

	gcd = __gcd(B.first, B.second);
	B.first /= gcd;
	B.second /= gcd;

	// cout << A.first << "/" << A.second << endl;
	//cout << B.first << "/" << B.second << endl;

	if(A == B){
		cout << "C" << endl;
	}else if(double(double(A.first)/double(A.second)) > double(double(B.first)/double(B.second))){
		cout << "A" << endl;
	}else{
		cout << "B" << endl;
	}

	return 0;
}