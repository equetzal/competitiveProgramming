#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

set<pair<map<char,int>,int>> validNums;

void printMaps(map<char,int> a, map<char,int> b){
	cout << "------------------------------" << endl;
	for(char c = '0'; c <= '9'; c++){
		cout << "key[" << c << "]:\t" << a[c] << " vs " << b[c] << endl;
	}
	cout << "||||||||||||||||||||||||||||||" << endl;
}


bool isPossible(map<char,int> frec, int len){
	if(frec.size() == 1 && frec['0'] > 0)
		return true;

	for(auto mp:validNums){
		bool isValid = true;
		if(len == mp.second){
//			printMaps(mp.first,frec);
			for(auto p:mp.first){
				if(frec[p.first] < p.second)
					isValid = false;
			}
			if(isValid){
//				cout << "true" << endl;
				return true;
			}else{
//				cout << "false" << endl;
			}
		}
	}
	return false;
}

bool isMul(string num){
	map<char,int> numFrec;
	for(auto c:num) numFrec[c]++;

	int len = (num.size()>4)?4:num.size();
	if(isPossible(numFrec, len))
		return true;
	return false;
}


int main(){
	int n; cin >> n;
	string num;

	for(int i=1; i<5000; i++){
		map<char,int> f;
		string sub;
		num = to_string(i*60);

		if(num.size() > 4)
			sub = num.substr(num.size()-4);
		else
			sub = num;

		for(auto c:sub)
			f[c]++;

		validNums.insert(make_pair(f,num.size()));
	}


	while(n--){
		cin >> num;

		if(isMul(num))
			cout << "red" << endl;
		else
			cout << "cyan" << endl;
	}

	return 0;
}
