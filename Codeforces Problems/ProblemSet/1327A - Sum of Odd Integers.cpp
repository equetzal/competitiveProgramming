//CF ProblemSet 1327A - Sum of Odd Integers

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

lli oddSum(lli k){
	return k*k;
}

bool isPossible(lli n, lli k){
	if(n == oddSum(k))
		return true;

	if(n >= oddSum(k)){
		if((n&1 && k&1) || (!(n&1) && !(k&1)))
			return true;
	}
	return false;
}

int main(){
	int t; cin >> t;
	while(t--){
		lli n,k; cin >> n >> k;

		if(isPossible(n,k))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
