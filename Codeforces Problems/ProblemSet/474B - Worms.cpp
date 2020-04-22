//CF ProblemSet 474B - Worms

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int piles;
	cin >> piles;

	vector<int> v;

	for(int i=1; i<=piles; i++){
		int p;
		cin >> p;

		while(p--)
			v.push_back(i);
	}

	int querys;
	cin >> querys;

	while(querys--){
		int q;
		cin >> q;
		cout << v[q-1] << "\n";
	}

	return 0;
}
