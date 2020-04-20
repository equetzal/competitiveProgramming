//CF ProblemSet 345A - Expecting Trouble

#include <bits/stdc++.h>

using namespace std;

int main(){
	string s; cin >> s;
	double p; cin >> p;

	int P = int(p*100.0);
	srand((unsigned)time(0));

	int ones = 0, unknow = 0;
	for(int i=0; i<s.size(); i++){
		if(s[i] == '1')
			ones++;
		if(s[i] == '?'){
			unknow++;
		}
	}

	double count = double(ones) + p*double(unknow);
	printf("%.5lf\n", count/double(s.size())); 

	return 0;
}
