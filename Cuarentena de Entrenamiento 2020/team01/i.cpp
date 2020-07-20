//CF Gym 100814I - Salem
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//ECPC 2015
//Los Hermanos Computadores de Paine - Coded by Quetzalli

#include <bits/stdc++.h>

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x:v) cin >> x;

		int ans = 0;
		for(int i=0; i<(n-1); i++){
			for(int j=i+1; j<n; j++){
				int b = v[i]^v[j], count = 0;
				for(int k=0; k<31; k++){
					if(b & (1<<k)){
						count++;
					}
				}
				ans = max(ans, count);
			}
		}
		cout << ans << endl;
	}

	return 0;
}

