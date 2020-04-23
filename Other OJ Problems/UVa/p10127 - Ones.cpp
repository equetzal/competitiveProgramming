//UVa p10127 - Ones

#include <bits/stdc++.h>

using namespace std;

typedef __int128 lli;

int main(){
	long long int n;
	while(cin >> n){
		lli ac = 0;
		int ans = -1;
		if(n == 0){
			cout << "0" << endl;
			continue;
		}

		for(lli i=1, k=1; i<1e18; i *= 10, k++){
			ac += i;
			if(ac%n == 0){
				ans = k;
				break;
			}
		}
		
		if(ans > 0)
			cout << ans << endl;
	}
}
