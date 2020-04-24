//https://codeforces.com/group/YjFmW2O15Q/contest/101919
//TAP2018 - Indecisos

#include <bits/stdc++.h>
using namespace std;

int main() {

	int N, pos = 0, neg = 0, ind = 0;
	string str;

	cin >> N >> str;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'P')
			pos++;
		else if (str[i] == 'N')
			neg++;
		else
			ind++;
	}
	if(pos>(neg+ind)){
		cout<<"SI"<<"\n";
	}else if(neg>=(pos+ind)){
		cout<<"NO"<<"\n";
	}else{
		cout<<"INDECISOS\n";
	}

	return 0;
}
