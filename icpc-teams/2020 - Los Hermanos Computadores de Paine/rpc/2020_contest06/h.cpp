//Kattis Open hothike - Hot Hike
//NCPC 2019
//Los Hermanos Computadores de Paine - Coded by Quetzalli

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define endl "\n"

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(auto &x:v) cin >> x;

	int temp=0, ans=1000; 
	for(int i=1; i<(n-1); i++){
		if(max(v[i-1], v[i+1]) < ans){
			ans = max(v[i-1], v[i+1]);
			temp = i;	
		}
	}

	cout << temp << " " << ans << endl;

	return 0;
}
