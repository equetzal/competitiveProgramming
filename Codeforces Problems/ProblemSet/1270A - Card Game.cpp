//CF ProblemSet 1270A - Card Game

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main(){
	int t; cin >> t;
	while(t--){
		int n,k1,k2; cin >> n >> k1 >> k2;
		int mx1=-1,mx2=-1,temp;

		while(k1--){
			cin >> temp;
			mx1 = max(mx1,temp);
		}

		while(k2--){
			cin >> temp;
			mx2 = max(mx2,temp);
		}

		if(mx1 > mx2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
