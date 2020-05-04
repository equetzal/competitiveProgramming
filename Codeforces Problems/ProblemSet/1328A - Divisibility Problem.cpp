//CF ProblemSet 1328A - Divisibility Problem

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		lli a,b; cin >> a >> b;
		lli r = a%b;
		if(r == 0){
			cout << 0 << endl;
		}else{
			cout << b-r << endl;
		}
	}

	return 0;
}
