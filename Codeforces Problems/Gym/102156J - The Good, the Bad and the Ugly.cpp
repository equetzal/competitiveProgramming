//CF Gym 102156J - The Good, the Bad and the Ugly

#include <bits/stdc++.h>
 
using namespace std;
 
bool play(int turns, bool sign){
	for(int i=0; i<turns; i++){
		cout << (sign? '+' : '-') << endl;
		
		int ans; cin >> ans;
		if(ans != 0){//El juagador esta en 0
			cout << "+" << endl;
			cin >> ans;
			cout << "-" << endl;
			cin >> ans;
			
			if(ans != 0){
				cout << "! ugly" << endl;
				return true;
			}else if(sign){
				cout << "! bad" << endl;
				return true;
			}else{
				cout << "! good" << endl;
				return true;
			}
		}
	}
	return false;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int turns=1;
	bool sign = true; //True: +, False: -
	
	while(true){
		if(play(turns, sign))
			break;
		sign = !sign;
		turns *= 3;
	}
	
	return 0;
}
