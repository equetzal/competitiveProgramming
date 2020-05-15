//CF Gym 101917C - Basic Encryption

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	lli t,dif; cin >> t >> dif;
	int d = dif%26;

	int start, val;
	string line; getline(cin, line);
	while(t--){
		getline(cin, line);
		for(auto c:line){
			if(isalpha(c)){
				if(isupper(c))
					start = int('A');
				else
					start = int('a');
				val = int(c) - start;
				val = (val+26-d)%26;
				cout << char(val+start);
			}else{
				cout << c;
			}
		}
		cout << endl;
	}


	return 0;
}

