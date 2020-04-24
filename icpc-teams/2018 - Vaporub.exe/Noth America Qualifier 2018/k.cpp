#include <bits/stdc++.h>

using namespace std;

int main(){
	char op; cin >> op;
	string cad; cin >> cad;

	if(op == 'E'){
		int count = 0; char car = cad[0];
		for(auto c:cad){
			if(c != car){
				cout << car << count;
				count = 1;
				car = c;
			}else{
				count++;
			}
		}
		cout << car << count << endl;
	}else{
		char car; int count;

		for(int i=0; i<cad.size(); i+=2){
			car = cad[i];
			count = cad[i+1]-'0';
			while(count--){
				cout << car;
			}
		}
			cout << endl;
	}
}
