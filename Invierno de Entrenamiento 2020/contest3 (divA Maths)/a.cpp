//CF ProblemSet 1216E2 - Numerical Sequence (hard version)

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli sum(lli n) {
	return (n+1)*n/2;
}

lli lenght(lli k, bool need) {
	lli pwr=1;
	lli ans=0, add=0, digits=0;

	for(lli i=1; ; i++) {
		if((pwr*10-1) < k) {
			digits = pwr*10-pwr;
			if(need){
				ans += i*sum(digits) + add*digits;
				add += i*digits;
			}else{
				ans += i*digits;
			}
		}else{
			digits = k-pwr+1;
			if(need){
				ans += i*sum(digits) + add*digits;
			}else{
				ans += i*digits;
			}
			break;
		}
		pwr *= 10;
	}
	return ans;
}

lli level(lli k){
	lli lo = 1, hi = 1000000000LL, mid;

	lli ans = -1;
	while(hi-lo >= 0){
		mid = (lo+hi)/2;
		if(lenght(mid, 1) > k){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}

	return ans;
}

lli digitsUntilK(lli lvl, lli kp){
	lli lo = 1, hi = lvl, mid;

	lli ans = -1;
	while(hi-lo >= 0){
		mid = (lo+hi)/2;
		if(lenght(mid,0) > kp){
			ans = mid;
			hi = mid-1;
		}else{
			lo = mid+1;
		}
	}

	return ans;
}

int main() {
	int t; cin >> t;
	while (t--) {
		lli k; cin >> k;
		
		lli lvl = level(k-1);
		lli kp = k-lenght(lvl-1, 1)-1;
		lli num = digitsUntilK(lvl,kp);
		cout << to_string(num)[kp-lenght(num-1,0)] << endl;
	}
	
	return 0;
}
