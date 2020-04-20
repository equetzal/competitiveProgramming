//CF Gym 102020D - Dumb feature

#include <bits/stdc++.h>

using namespace std;

char getKey(char c){
	if(c == 'a'||c == 'b'||c == 'c') 
		return '2';
    if(c == 'd'||c == 'e'||c == 'f') 
		return '3';
    if(c == 'g'||c == 'h'||c == 'i')
		return '4';
    if(c == 'j'||c == 'k'||c == 'l')
		return '5';
    if(c == 'm'||c == 'n'||c == 'o')
		return '6';
    if(c == 'p'||c == 'q'||c == 'r'||c == 's') 
		return '7';
    if(c == 't'||c == 'u'||c == 'v')
		return '8';
    if(c == 'w'||c == 'x'||c == 'y'||c == 'z') 
		return '9';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q; cin >> n >> q;
	
	unordered_map<string,int> cells;
	for(int i=0; i<n; i++){
		string name; cin >> name;
		int tam = min((int)name.size(), 500);
		char nums[tam+1];

		for(int j=0; j<tam; j++){
			nums[j] = getKey(name[j]);
			nums[j+1] = '\0';
			cells[nums]++;
		}
	}
	
	while(q--){
		string seq; cin >> seq;
		if(seq.size() > 500)
			seq[500] = '\0';
		cout << cells[seq] << endl;
	}
}
