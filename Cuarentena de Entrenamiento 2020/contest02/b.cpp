//Original by https://codeforces.com/profile/Marckess - Daily Training
//https://codeforces.com/group/PzLcHnJr9l/contest/273894/problem/B

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

lli getMotivation(lli l, lli r, vector<lli> &v){
	map<lli,int> freq; //number, freq
	for(lli i=l; i<=r; i++)
		freq[v[i]]++;

	int mnF=200,mxF=-1;
	for(auto p:freq){
		mnF = min(mnF, p.second);
		mxF = max(mxF, p.second);
	}

	lli mn = 1000000010, mx = -1;
	for(auto p:freq){
		if(p.second == mnF){
			mn = min(mn,p.first);
		}
		if(p.second == mxF){
			mx = max(mx,p.first);
		}
	}

	return mx-mn;
}

int main(){
	fast_io

	int n,k; cin >> n >> k;
	vector<lli> problems(n);
	for(auto &x:problems) cin >> x;

	lli motivation[n+1][n+1]; memset(motivation, 0, sizeof(motivation));
	lli memo[k][n]; memset(memo, 0, sizeof(memo));

	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			motivation[i][j] = motivation[j][i] = getMotivation(i,j, problems);
		}
	}

	for(int i=0; i<n; i++){
		memo[0][i] = motivation[i][n-1];
	}

	for(int i=1; i<k; i++){
		for(int j=0; j<n; j++){
			lli best = 0, val = 0;
			for(int a=j; a<n; a++){
				if(a+1 < n)
					val = motivation[j][a] + memo[i-1][a+1];
				else
					val = motivation[j][a];
				best = max(best,val);
			}
			memo[i][j] = best;
		}
	}

	cout << memo[k-1][0] << endl;

	return 0;
}
