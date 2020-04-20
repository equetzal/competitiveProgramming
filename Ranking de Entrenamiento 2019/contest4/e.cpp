//CF Gym 102156H - Jeopardy

#include <bits/stdc++.h>

using namespace std;

int main(){
	short n; cin >> n;
	
	vector<short> row(n,111);
	for(short i=0; i<n; i++){
		for(int j=0; j<n; j++){
			short temp; cin >> temp;
			row[i] = min(row[i],temp);
		}
	}
	
	short ans = -1;
	for(short i=0; i<n; i++){
		ans = max(ans,row[i]);
	}
	
	cout << ans << endl;	
	
	return 0;
}
