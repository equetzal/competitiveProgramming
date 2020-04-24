//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028B - Bonapity

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		string cadA, cadB;
		cin >> cadA >> cadB;

		if(cadA.size() != cadB.size()){
			cout << "No\n";
			continue;
		}

		transform(cadA.begin(), cadA.end(), cadA.begin(), ::tolower);
		transform(cadB.begin(), cadB.end(), cadB.begin(), ::tolower);

		for(int i=0; i<cadA.size(); i++){
			if(cadA[i] == 'b')
				cadA[i] = 'p';
			if(cadA[i] == 'i')
				cadA[i] = 'e';
			if(cadB[i] == 'b')
				cadB[i] = 'p';
			if(cadB[i] == 'i')
				cadB[i] = 'e';
		}

		if(cadA == cadB)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
