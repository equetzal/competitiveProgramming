#include <vector>
#include <iostream>

#define endl "\n"

using namespace std;

int main(){
	int cases; cin >> cases;

	while(cases--){
		vector< pair<bool, int> > cad;
		string s; cin >> s;
		for(char c:s){
			bool val;
			if(c == 'A' || c == 'G')
				val = 1;
			if(c == 'C' || c == 'T')
				val = 0;
		
			if(cad.empty())
				cad.push_back(make_pair(val, 1));
			else{
				if(cad[cad.size()-1].first != val){
					cad.push_back(make_pair(val, 1));
				}else{
					cad[cad.size()-1].second++;
				}
			}
		}
			
		// for(auto b:cad){
		// 	cout << b.first << " " << b.second << endl;
		// }
		// cout << endl;

		//Si son solo 1's o 0's 
		if(cad.size() == 1){
			if(cad[0].first)
				cout << cad[0].second << " " << 0 << endl;
			else 
				cout << 0 << " " << cad[0].second << endl;
			continue;
		}

		//El conjunto mas grande de 1's
		int maxOnes = 0, maxZeros = 1;
		for(auto p:cad)
			maxOnes = max(p.second, maxOnes);
	
		//La suma de 1's separados por un 0
		for(int i = 1; i < cad.size()-1; i++){
			if(cad[i].first == 0)
				if(cad[i].second == 1)
					maxOnes = max(cad[i-1].second+cad[i+1].second, maxOnes);
				else{
					if((cad[i-1].second+cad[i+1].second)/cad[i].second >= maxOnes){
						maxOnes = cad[i-1].second+cad[i+1].second;
						maxZeros = cad[i].second;
					}
					// maxOnes = max(, maxOnes);
				}
		}

		cout << maxOnes << " " << maxZeros << endl;
	}
}