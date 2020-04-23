//CF ProblemSet 734B - Anton and Digits

#include <bits/stdc++.h>

using namespace std;

int main(){
	int two,three,five,six; cin >> two >> three >> five >> six;

	int a = min(two,min(five,six));
	two -= a;
	five -= a;
	six -= a;
	int b = min(three,two);

	cout << a*256 + b*32 << endl;

	return 0;
}
