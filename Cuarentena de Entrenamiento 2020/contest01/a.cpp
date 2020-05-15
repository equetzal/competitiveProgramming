#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

pair<lli,lli> lps(string s){
	bool memo[s.size()][s.size()];
	memset(memo, 0, sizeof(memo));

	lli mx = 1, nMx = s.size();
	for(lli i=0; i<s.size(); i++){
		memo[i][i] = true;
	}

	for(lli i=0; i<s.size()-1; i++){
		if(s[i] == s[i+1]){
			memo[i][i+1] = true;
			nMx = 2;
		}
	}

	for(lli sz=3; sz <= s.size(); sz++){
		for(lli i=0; i<(s.size()-sz+1); i++){
			if(memo[i+1][i+sz-2] && s[i] == s[i+sz-1]){
				memo[i][i+sz-1] = true;
				if(sz > mx){
					nMx = 0;
					mx = sz;
				}
				if(sz == mx){
					nMx++;
				}
			}
		}
	}

/*	for(int i=0; i<s.size(); i++){
		for(int j=0; j<s.size(); j++){
			cout << memo[i][j] << " ";
		}
		cout << endl;
	}
*/
	return make_pair(mx,nMx);
}

int main(){
	lli n; cin >> n;
	string s; cin >> s;

	auto ans = lps(s);
	cout << ans.first << endl << ans.second << endl;

	return 0;
}
