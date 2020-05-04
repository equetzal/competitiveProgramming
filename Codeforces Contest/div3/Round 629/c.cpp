//CF ProblemSet 1328C - Ternary XOR

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
	int t; cin >> t;
	while(t--){
		lli n; cin >> n;
		string x; cin >> x;

		string a = x;
		string b = x;
		a[0] = '1', b[0] = '1';
		bool down = false;

		for(lli i=1; i<n; i++){
			if(!down){
			if(x[i-1] == '2' || x[i-1] == '0'){
				if(x[i] == '0'){
					a[i] = '0', b[i] = '0';
				}
				if(x[i] == '1'){
					down = true;
					a[i] = '1', b[i] = '0';
				}
				if(x[i] == '2'){
					a[i] = '1', b[i] = '1';
				}
			}else{
				if(x[i] == '0'){
					a[i] = '0', b[i] = '0';
				}
				if(x[i] == '1'){
					a[i] = '1', b[i] = '0';
					down = true;
				}
				if(x[i] = '2'){
					a[i] = '0', b[i] = '2';
				}
			}}else{
				if(x[i] == '0'){
					a[i] = '0', b[i] = '0';
				}
				if(x[i] == '1'){
					a[i] = '0', b[i] = '1';
				}
				if(x[i] == '2'){
					a[i] = '0', b[i] = '2';
				}
			}
		}

		cout << a << endl << b << endl;
	}

	return 0;
}
