#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

void Decrypt(string &encrypt, string &reverse, int posA, vector <bool> &flags,vector <char> &final, int finPos){
	char act;
	act = reverse[posA]; 

	if(act == '$')
		return;

	final[finPos] = act;

	for(int i=encrypt.size(); i>=1; i--){
		if(encrypt[i] == act && flags[i] == false){
			posA = i;
			flags[i] = true;
			Decrypt(encrypt, reverse, posA, flags, final, finPos+1);
			break;
		}
	}

	if(finPos == encrypt.size()-1){
		posA = 0;
		flags[0] = true;
	}
}

int main(){
	string word, reverse, encrypt;
	int pos;

	priority_queue <int> Q;

	while(cin >> encrypt){
		vector <bool> flags(encrypt.size(), false);
		vector <char> final(encrypt.size()+1);

		for(int i=0; i<encrypt.size(); i++){
			Q.push(-(int)encrypt[i]);
			if(encrypt[i] == '$')
				pos = i;
		}

		for(int i=0; i<encrypt.size(); i++){
			reverse[i] = (char)(-Q.top());
			Q.pop();
		}

		Decrypt(encrypt, reverse, pos, flags, final, 0);
		
		for(int i=0; i<final.size(); i++){
			cout << final[i];
		}
		cout << "\n";

	}

	return 0;
}
