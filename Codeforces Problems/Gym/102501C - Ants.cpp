//CF Gym 102501C - Ants

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MAXN 1000010

int main(){
	lli n; cin >> n;
	bool nums[MAXN];
	memset(nums,0,sizeof(nums));

	string s;
	while(n--){
		cin >> s;
		if(s.size() < 10){
			lli val = stol(s);
			if(val >= 0 && val < MAXN)
				nums[val] = true;;
		}
	}

	for(lli i=0; i<MAXN; i++){
		if(!nums[i]){
			cout << i << endl;
			break;
		}
	}

	return 0;
}
