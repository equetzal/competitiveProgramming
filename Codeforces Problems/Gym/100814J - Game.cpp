//CF Gym 100814J - Game
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//ECPC 2015
//Los Hermanos Computadores de Paine - Coded by Quetzalli

#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;
vector<string> eq(26);

bool isvowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

string leftMove(string game){
	string ans;

	for(int i=game.size()-2; i>=0; i-=2){
		int a = game[i]-'a', b = game[i+1]-'a';
		ans.push_back(eq[b][a]);
	}

	if(game.size()%2 == 1){
		ans.push_back(game[0]);
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

string rightMove(string game){
	string ans;

	for(int i=0; i<(game.size()-1); i+=2){
		int a = game[i]-'a', b = game[i+1]-'a';
		ans.push_back(eq[a][b]);
	}

	if(game.size()%2 == 1){
		ans.push_back(game.back());
	}

	return ans;
}


bool redux(string game, bool play){
	if(game.size() == 1){ // El jueego acabo
		if(isvowel(game[0]))
			return true;
		return false;
	}

	string left = leftMove(game);
	string right = rightMove(game);

	assert(left.size() == (game.size()+1)/2);
	assert(right.size() == (game.size()+1)/2);

	if(play)
		return (redux(left, !play) & redux(right, !play));
	else
		return (redux(left, !play) | redux(right, !play));

}

int main(){
	int t; cin >> t;
	while(t--){
		for(auto &x:eq) cin >> x;

		string game; cin >> game;
		if(redux(game, false))
			cout << "Salah" << endl;
		else
			cout << "Marzo" << endl;

	}

	return 0;
}

