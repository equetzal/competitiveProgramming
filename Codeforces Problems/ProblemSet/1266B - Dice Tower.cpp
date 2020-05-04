//CF ProblemSet 1266B - Dice Tower

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		lli x; cin >> x;
		if(x <= 20){
			if(x >= 15 && x <= 20)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			continue;
		}

		lli k = (x-15)/14;
		if(x >= (14*k + 15) && x <= (14*k + 20))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;
}

