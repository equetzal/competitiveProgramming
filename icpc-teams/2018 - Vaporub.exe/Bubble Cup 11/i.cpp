#include <bits/stdc++.h>

using namespace std;

long long int combina(int n){
	if(n < 2)
		return 0;
	else
		n -= 2;

	long long int mat[2][n+1];
	mat[0][0] = 1;
	mat[1][0] = 2;

	for(int i=1; i<=n; i++){
		mat[0][i] = mat[0][i-1] + mat[1][i-1];
		mat[1][i] = mat[1][i-1]+1;
	}

	return mat[0][n];
}

bool isPairPalindrome(int i, int j, vector < map<char,int> > &maps){
	unordered_map<char,int> frec;

	for(auto c:maps[i]){
		if(c.second%2 == 1)
			frec[c.first] += c.second;
	}
	for(auto c:maps[j]){
		if(c.second%2 == 1)
			frec[c.first] += c.second;
	}

	bool firstOdd = false;
	for(auto a:frec){
		if(a.second % 2 == 1)
			if(firstOdd)
				return false;
			else
				firstOdd = true;
	}

	return true;
}

bool isPalindrome(string &s){
	unordered_map<char,int> frec;
	for(auto c:s)
		frec[c]++;

	bool firstOdd = false;
	for(auto a:frec){
		if(a.second % 2 == 1)
			if(firstOdd)
				return false;
			else
				firstOdd = true;
	}
	return true;
}

int main(){
	int n; cin >> n;
	vector < map<char,int> > maps;

	int cantPal = 0;
	for(int i=0; i<n; i++){
		string temp; cin >> temp;
			map<char,int> m;
			for(auto a:temp){
				m[a]++;
			}
			maps.push_back(m);
	}

	cout << cantPal << endl;

	long long int counter = combina(cantPal);
	cout << counter << endl;
	if(!maps.empty())
		for(int i=0; i<maps.size()-1; i++){
			for(int j=i+1; j<maps.size(); j++){
				if(isPairPalindrome(i,j,maps))
					counter++;
			}
		}

	cout << counter << "\n";

}
