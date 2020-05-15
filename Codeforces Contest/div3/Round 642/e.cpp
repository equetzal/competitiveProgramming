//CF Problemset 1353E - K-periodic Garland

#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		int n,k; cin >> n >> k;
		string s,S; cin >> S;

		bool firstOne = false;
		for(auto c:S){
			if(c == '1'){
				firstOne = true;
			}
			if(firstOne){
				s.push_back(c);
			}
		}

		firstOne = false;
		for(int i=s.size()-1; i>=0; i--){
			if(s[i] == '1')
				firstOne = true;
			if(!firstOne){
				s.pop_back();
			}
		}

		n = s.size();

		int ones = 0;
		for(int i=1; i<n; i++){
			ones += (s[i] == '1');
		}

		int toAdd, ans = n, actOnes;
		for(int i=0; i<k; i++){
			toAdd = 0, actOnes = 0;
			for(int j=i; j<n; j+=k){
				if(s[j] == '0'){
					toAdd++;
				}else{
					actOnes++;
				}
			}
			ans = min(ans,(ones-actOnes)+toAdd);
		}

		cout << ans << endl;
	}

	return 0;
}
