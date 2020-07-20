//Kattis Open eenymeeny - Eeny Meeny
//NCPC 2019
//Los Hermanos Computadores de Paine - Coded by Quetzalli

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define endl "\n"

int main(){
	string line,word; getline(cin,line);
	istringstream ss(line);
	vector<string> words;
	
	while(ss >> word)
		words.push_back(word);

	int k = words.size();
	int n; cin >> n;
	vector<string> names(n);
	for(auto &x:names) cin >> x;

	vector<string> teamA,teamB;
	queue<string> song;
	for(auto name:names){
		song.push(name);
	}

	int counter = 1;
	bool isTeamA = true;
	while(!song.empty()){
		if(counter%k == 0){
			if(isTeamA){
				teamA.push_back(song.front());
			}else{
				teamB.push_back(song.front());
			}
			isTeamA = !isTeamA;
			song.pop();
		}else{
			song.push(song.front());
			song.pop();
		}
		counter++;
	}

	cout << teamA.size() << endl;
	for(auto name:teamA)
		cout << name << endl;
	cout << teamB.size() << endl;
	for(auto name:teamB)
		cout << name << endl;

	return 0;
}
