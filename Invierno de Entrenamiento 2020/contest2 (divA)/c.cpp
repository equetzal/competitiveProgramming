//CF Gym 100935B - Weird Cryptography

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define endl "\n"

int main(){
	int n, caso = 1;
	while(cin >> n){
		if(n == 0)
			break;

		vector< set<string> > digits;
		string temp;
		while(n--){
			cin >> temp;
			if(digits.size() > 0){
				bool isInserted = false;
				for(int i=0; i<digits.size(); i++){
					if(digits[i].find(temp) == digits[i].end() && digits[i].size() < 9){
						isInserted = true;
						digits[i].insert(temp);
						break;
					}
				}
				if(isInserted == false){
					set<string> s;
					s.insert(temp);
					digits.push_back(s);
				}
			}else{
				set<string> s;
				s.insert(temp);
				digits.push_back(s);
			}
		}
		cout << "Case " << caso << ": ";
		for(int i=digits.size()-1; i>=0; i--){
			cout << digits[i].size();
		}
		cout << endl;
		caso++;
	}

	return 0;
}
