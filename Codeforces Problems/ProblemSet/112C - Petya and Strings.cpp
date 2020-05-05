//CF ProblemSet 112C - Petya and Strings

#include <bits/stdc++.h>

using namespace std;

int main(){
	string cad1,cad2;
	cin >> cad1 >> cad2;

	for(int i=0;i<cad1.size();i++){
		cad1[i] = tolower(cad1[i]);
		cad2[i] = tolower(cad2[i]);
		if(cad1[i] < cad2[i]){
			cout << -1 << endl; return 0;
		} else if (cad1[i] > cad2[i]){
			cout << 1 << endl; return 0;
		}
	}

	cout << 0 << endl;
	return 0;
}
