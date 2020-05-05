//CF ProblemSet 69A - Young Physicist

#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main(){
	int n; cin>>n;
	int x = 0;
	int sx = 0, sy= 0, sz =0;
	while(n--){
		cin>>x;
		sx += x;
		cin>>x;
		sy += x;
		cin>>x;
		sz += x;
	}
	if( sx == 0 && sy == 0 && sz == 0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
