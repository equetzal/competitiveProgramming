//CF Gym 102035E - New Max

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	int n,m,k; cin >> n >> m >> k;
	map<int,int> freq;
	int val;

	while(n--){
		cin >> val;
		freq[val]++;
	}

	int needed = 0;
	for(auto p:freq){
		if(p.first > m)
			needed += p.second;
	}

	if(needed == 0 && freq[m] == 0)
		needed++;

	if(k >= needed)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

