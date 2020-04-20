//CF Gym 101915C - Shahhoud Training Hussain

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		long long int k,p,n; cin >> k >> p >> n;

		if(p>=k)
			cout << 0 << endl;
		else
			cout << k*n-p*n << endl;
	}

	return 0;
}
