//CF ProblemSet 867A - Between the Offices

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;

	int s2f=0, f2s=0;
	for(int i=0; i<(n-1); i++){
		if(s[i] == 'S' && s[i+1] == 'F')
			s2f++;
		if(s[i] == 'F' && s[i+1] == 'S')
			f2s++;
	}

	if(s2f > f2s)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
