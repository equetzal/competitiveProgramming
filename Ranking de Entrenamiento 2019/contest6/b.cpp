//CF Gym 101522K - Knights

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int n,m,k; cin >> n >> m >> k;
	bool hackerland[n][m];
	memset(hackerland, false, sizeof(hackerland));
 
	while(k--){
		int x,y; cin >> x >> y;
		x--; y--;
		hackerland[x][y] = true;
	}
 
	int needed;
	if(n == 1){
		if(m == 1)
			cout << (hackerland[0][0]?0:1) << endl;
		else{	
			needed = 2;
			if(hackerland[0][0])
				needed--;
			if(hackerland[0][m-1])
				needed--;
			cout << needed << endl;
		}
	}else{
		if(m == 1){
			needed = 2;
			if(hackerland[0][0])
				needed--;
			if(hackerland[n-1][0])
				needed--;
			cout << needed << endl;
		}else{
			needed = 4;
			if(hackerland[0][0])
				needed--;
			if(hackerland[n-1][0])
				needed--;
			if(hackerland[0][m-1])
				needed--;
			if(hackerland[n-1][m-1])
				needed--;
			cout << needed << endl;
		}
	}
 
	return 0;
}
