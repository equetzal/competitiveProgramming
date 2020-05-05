//CF ProblemSet 1296A - Array with Odd Sum

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x:v) cin >> x;

		bool isFullEven = true;
		bool isFullOdd = true;
		bool isArrayOdd = n&1;
		int sum = 0;
		for(int i=0; i<n; i++){
			if(v[i] & 1){
				isFullEven = false;
			}else{
				isFullOdd = false;
			}
			sum += v[i];
		}

		if(sum&1){
			cout << "YES" << endl;
			continue;
		}else{
			if(isArrayOdd){
				if(isFullEven){
					cout << "NO" << endl;
					continue;
				}
				cout << "YES" << endl;
			}else{
				if(isFullOdd || isFullEven){
					cout << "NO" << endl;
					continue;
				}
				cout << "YES" << endl;
			}
		}
	}

}
