//CF Gym 101498I - Rock Piles

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t; cin >> t;
	while(t--){
		lli a,b; cin >> a >> b;

		if(!(a&1) && !(b&1))
			cout << "abdullah" << endl;
		else
			cout << "hasan" << endl;
	}

	return 0;
}
