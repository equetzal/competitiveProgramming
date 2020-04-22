//CF ProblemSet 295A - Greg and Array

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	lli n,m,k; cin >> n >> m >> k;

	vector<lli> nums(n), numsLeisi(n+1,0);
	for(auto &x:nums) cin >> x;

	lli x,y,d;
	vector<tuple<lli,lli,lli>> ops;
	vector<lli> opsLeisi(m+1,0);
	for(int i=0; i<m; i++){
		cin >> x >> y >> d;
		ops.push_back(make_tuple(x-1,y-1,d));
	}

	lli l,r;
	for(int i=0; i<k; i++){
		cin >> l >> r;
		opsLeisi[l-1]++;
		opsLeisi[r]--;
	}

	for(int i=1; i<opsLeisi.size()+1; i++){
		opsLeisi[i] += opsLeisi[i-1];
	}

	for(int i=0; i<opsLeisi.size()-1; i++){
		x = get<0>(ops[i]), y = get<1>(ops[i]);
		d = opsLeisi[i]*get<2>(ops[i]);
		numsLeisi[x] += d;
		numsLeisi[y+1] -= d;
	}

	for(int i=1; i<numsLeisi.size()+1; i++){
		numsLeisi[i] += numsLeisi[i-1];
	}

	for(int i=0; i<n; i++){
		cout << nums[i]+numsLeisi[i] << " ";
	}
	cout << endl;

	return 0;
}
