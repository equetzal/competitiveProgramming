//CF Gym 101962B - Color Changing Sofa

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	string tiles, sofa; cin >> tiles >> sofa;
	
	int res=0;
	for(int i=0; i+(sofa.size()-1) < tiles.size(); i++){
		map<char,int> zeroes, ones, zeroes_reverse, ones_reverse;
		for(int j=0; j<sofa.size(); j++){
			if(sofa[j] == '0'){
				zeroes[tiles[i+j]]++;
				zeroes_reverse[tiles[i-j+(sofa.size()-1)]]++;
			}else{
				ones[tiles[i+j]]++;
				ones_reverse[tiles[i-j+(sofa.size()-1)]]++;
			}
		}

		if(zeroes.size() > 1 || ones.size() > 1){ //Checar si los unos y los ceros empatan
			if(zeroes_reverse.size() <= 1 && ones_reverse.size() <= 1){
				res++;
			}
		}else{
			res++;
		}
	}
	
	cout << res << endl;	
	
}
