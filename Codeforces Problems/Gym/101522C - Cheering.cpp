//CF Gym 101522C - Cheering

#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;

	int a=0,b=0;
	for(int i=2; i<s.size(); i++){
		if(s[i-2] == 'L' && s[i-1] == 'S' && s[i] == 'C')
			a++;
	}
	for(int i=3; i<s.size(); i++){
		if(s[i-3] == 'P' && s[i-2] == 'C' && s[i-1] == 'M' && s[i] == 'S')
			b++;
	}

	if(a == b)
		cout << "Tie" << endl;
	else if(a > b)
		cout << "LSC" << endl;
	else cout << "PCMS" << endl;

	return 0;
}
