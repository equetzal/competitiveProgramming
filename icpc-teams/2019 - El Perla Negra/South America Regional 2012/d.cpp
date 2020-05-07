#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;

	while(cin >> n >> m){
		int count = 0;
		for(int i=n; i<=m; i++){
			map<char,short> frec;
			string num = to_string(i);
			bool isDouble = false;
			for(char c:num){
				frec[c]++;
				if(frec[c] > 1)
					isDouble = true;
			}
			if(!isDouble)
				count++;
		}
		cout << count << endl;
	}


	return 0;
}
