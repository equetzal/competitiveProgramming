//AtCoder 2001 - Wanna go back home

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	string S;
	cin >> S;

	map <char,bool> dir;
	dir['N'] = false;
	dir['S'] = false;
	dir['E'] = false;
	dir['W'] = false;

	for(int i=0; i<S.size(); i++){
		dir[S[i]] = true;
	}

	int count=0;
	for(auto a:dir){
		if(a.second == true)
			count++;
	}

	if(count%2 == 1)
		cout << "No" << endl;
	else{
		if(dir['N'] && dir['S'] && dir['E'] && dir['W']){
			cout << "Yes" << endl;
		}else{
			if(dir['N'] && dir['E'] || dir['N'] && dir['W']){
				cout << "No" << endl;
			}else if(dir['S'] && dir['E'] || dir['S'] && dir['W']){
				cout << "No" << endl;
			}else{
				cout << "Yes" << endl;
			}
		}
	}

}
