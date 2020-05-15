//CF ProblemSet 651B - Beautiful Paintings

#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
typedef long long int lli;
 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main(){
	fast_io
 
	int n; cin >> n;
	vector<lli> v(n);
	map<lli,int> freq;
	for(auto &x:v){
		cin >> x;
		freq[x]++;
	}
 
	lli ans = 0;
	while(!freq.empty()){
		ans += freq.size()-1;
		auto copy = freq;
		for(auto p:copy){
			if(p.second == 1)
				freq.erase(p.first);
			else
				freq[p.first]--;
		}
	}
 
	cout << ans << endl;
 
	return 0;
}
