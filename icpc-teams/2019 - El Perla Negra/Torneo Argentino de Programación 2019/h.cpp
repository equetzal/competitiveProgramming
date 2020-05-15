#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
typedef long long int lli;

bool isSimilar(map<char,int> A, map<char,int> B){
	int dif = 0;
	cout << ". -> " << A['.'] << "vs" << B['.'] << endl;
	cout << ", -> " << A[','] << "vs" << B[','] << endl;
	cout << "_ -> " << A['_'] << "vs" << B['_'] << endl;

	dif += abs(A['.'] - B['.']);
	dif += abs(A[','] - B[',']);
	dif += abs(A['_'] - B['_']);

	for(char c='a'; c<='z'; c++){
		dif += abs(A[c] - B[c]);
		cout << c << " -> " << A[c] << "vs" << B[c] << endl;

	}
	cout << "dif=" << dif << endl;
	cout << "/////////////" << endl;

	if(dif == 0 || dif == 2)
		return true;
	return false;

}

int main(){
	int tam; cin >> tam;
	string s; cin >> s;

	int n,tWord; cin >> n >> tWord;
	vector< map<char,int> > words(n);
	for(int i=0; i<n; i++){
		string cad; cin >> cad;
		for(auto c:cad){
			words[i][c]++;
		}
	}

	int ans = 0;
	map<char,int> curr;
	for(int i=0; i<tWord; i++)
		curr[s[i]]++;

	for(int i=0; i<tam-tWord; i++){
		cout << i << "--------------" << endl;
		for(auto w:words){
			if(isSimilar(curr, w)){
				ans++;
			}
		}
		curr[s[i]]--;
		if(i+tWord < tam)
			curr[s[i+tWord]]++;
	}

	cout << ans << endl;


	return 0;
}