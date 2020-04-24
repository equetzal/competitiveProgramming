//Tobby’s Ancestors

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;

	while(cin >> s1){
		cin >> s2;

		long cont=0, max=0, line=0, disp=0, min=10000000;
		char res[s1.size()+s2.size()];

		for(int i=0; i < s1.size(); i++){
			// cout << i << endl;
			cont = 0;
			disp = 0;
			for(long j=i, k=0; j != s1.size(); j++, k++){
				if(s1[j] == s2[k])
					cont++;
				else
					disp++;
			}
			// cout << "coincidencias: " << cont << "  errores: " << disp << "   linea: " << i << endl;
			if(cont >= max){
				if(disp < min){
					max = cont;
					line = i;
					min = disp;
				}
				// cout << "Line: " << line << endl;
			}
		}

		// cout << "Maximo de coincidencias: " << max << "  Linea: " << line << " S1: " << s1.size() << endl;
		if(max > 0){
			for(long i=0; i != line; i++)
				res[i] = s1[i];
			for(long i=line, j=0; i != s1.size(); i++, j++){
				if(s1[i] == s2[j])
					res[i] = s1[i];
				else
					res[i] = 'X';
			}
			long j=s1.size();
			for(long i = s1.size()-line; s2[i] != '\0'; i++, j++){
				// cout << "J: " << j << " ";
				res[j] = s2[i];
			}

			res[j] = '\0';

			cout << max << endl << res;
		}
		else
			cout << 0 << "\nNo matches";

		cout << endl << endl;
	}
}
