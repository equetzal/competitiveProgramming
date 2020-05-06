#include <bits/stdc++.h>

using namespace std;


int main(){

	int n; cin >> n; n--;
	int carlos; cin >> carlos;
	bool isBiggerThanCarlos = false;
	while(n--){
		int t; cin >> t;
		if(t>carlos)
			isBiggerThanCarlos = true;
	}

	if(isBiggerThanCarlos)
		cout << "N" << endl;
	else
		cout << "S" << endl;


	return 0;
}