#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	set<int> angles;
	for(int ang=0; ang<=180; ang += 6)
		angles.insert(ang);

	while(cin >> a){
		if(angles.count(a) > 0)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}

	return 0;
}
