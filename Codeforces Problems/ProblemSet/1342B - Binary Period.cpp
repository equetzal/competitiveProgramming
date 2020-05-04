//CF ProblemSet 1342B - Binary Period

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int z=0,o=0;
		for(auto c:s){
			if(c == '0')
				z++;
			else
				o++;
		}

		if(z == s.size() || o == s.size()){
			cout << s << endl;
			continue;
		}

		bool isOne = (s[0]=='1')?true:false;
		string ans;
		for(int i=0; i<s.size();){
			if(s[i]-'0' == isOne){
				ans.push_back(s[i]);
				i++;
			}else{
				if(isOne)
					ans.push_back('1');
				else
					ans.push_back('0');
			}
			isOne = !isOne;
		}

		cout << ans << endl;
	}

	return 0;
}
