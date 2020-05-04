//UVa p11340 - Newspaper

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t; cin >> t;
	while(t--){
		int k; cin >> k;
		unordered_map<char,int> p;

		string ch; int val;
		while(k--){
			cin >> ch >> val;
			p[ch[0]] = val;
		}

		int m; cin >> m;
		string line; getline(cin,line);
		lli sum = 0;
		while(m--){
			getline(cin, line);
			for(auto c:line)
				sum += p[c];
		}

		cout << lli(sum/100) << ".";
		if(sum%100 < 10)
			cout << 0;
		cout << sum%100 << "$" << endl;
	}

	return 0;
}
