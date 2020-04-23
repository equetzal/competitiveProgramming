//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028A - Codeforces Rating

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;

	while(t--){
		int s,cor; cin >> s >> cor;
		int sum = 1500, temp;
		while(s--){
			cin >> temp;
			sum += temp;
		}
		if(sum == cor)
			cout << "Correct\n";
		else
			cout << "Bug\n";
	}
	return 0;
}
