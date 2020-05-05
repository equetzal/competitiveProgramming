//CF ProblemSet 1295A - Display The Number

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;

	while(t--){
		int n, ones; cin >> n;

		if(n%2 == 0){
			ones = n/2;
		}else{
			ones = n/2 - 1;
			cout << 7;
		}

		while(ones--)
			cout << 1;
		cout << endl;
	}

	return 0;
}

