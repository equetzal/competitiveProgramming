#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

bool isSol(lli n, lli x){
/*	lli lo = 0;
	lli hi = x;
	lli d = (lo+hi)/2;
	
	int it=64;
	while(it--){
		lli val = n*(d*2 + (n-1)) - x*2;
		
		if(val == 0)
			return true;
		
		if(val < 0){
			lo = d;
		}else if(val > 0){
			hi = d;
		}
		d = (lo+hi)/2;
	}
	
	return false;*/
	double d = (((double(x)*2.0)/double(n)) - double(n-1))/2.0;
	
	if((d - double(lli(d))) < 0.0000001)
		return true;
	return false;
	
}


int main(){
	int t; cin >> t;
	
	for(int caso=1; caso<=t; caso++){
		lli x; cin >> x;
		lli sq = sqrt(x)+2;
		
		lli ans=0;
		for(lli i=0; i<sq; i++){
			if(isSol(i, x)){
				ans++;
			}
		}
		
		cout << "case " << caso << ": " << ans << endl;
	}
	
	return 0;
}
