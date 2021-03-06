//CF ProblemSet 1343A - Candies

#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		lli n; cin >> n;

		lli sum = 1;
		for(int i=1; i<63; i++){
			sum += (1<<i);
			if(n%sum == 0){
				cout << n/sum << endl;
				break;
			}
		}
	}

	return 0;
}
