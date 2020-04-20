//CF Gym 101532B - Array Reconstructing

#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
		vector<int> v(n);

		int fPos = -1;
		for(int i=0; i<n; i++){
			cin >> v[i];
			if(v[i] != -1 && fPos == -1)
				fPos = i;
		}

		//Adelante
		for(int i=fPos+1; i<n; i++){
			v[i] = (v[i-1]+1)%m;
		}
		//Atras
		for(int i=fPos-1; i>=0; i--){
			if(v[i+1] == 0)
				v[i] = m-1;
			else
				v[i] = (v[i+1]-1)%m;
		}

		for(int i=0; i<n; i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
