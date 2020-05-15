//CF ProblemSet 960A - Check the string

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	string s; cin >> s;
	bool a=false, b=false, c=false;
	int A=0, B=0, C=0;


	bool ans = true;
	for(auto ch:s){
		if(ch == 'a'){
			if(b || c){
				cout << "NO" << endl;
				return 0;
			}
			a = true;
			A++;
		}else if(ch == 'b'){
			if(!a || c){
				cout << "NO" << endl;
				return 0;
			}
			b = true;
			B++;
		}else{
			if(!a || !b){
				cout << "NO" << endl;
				return 0;
			}
			c = true;
			C++;
		}
	}

	if(C != A && C!= B || A == 0 || B == 0 || C == 0)
		ans = false;

	if(ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}
