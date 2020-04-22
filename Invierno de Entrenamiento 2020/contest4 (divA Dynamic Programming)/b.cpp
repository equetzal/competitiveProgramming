//CF ProblemSet 8C - Looking for Order

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int distances[30][30];
const int inf = numeric_limits<int>::max();


int dist(pair<int,int> p1, pair<int,int> p2){
	return (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
}

int dp[1<<24]; //Todas las posibilidades 2²⁴/10⁸ = 0.16 y 250 MiB, debería entrar en tiempo y memoria
int track[1<<24];

int main(){
	pair<int,int> handbag;
	cin >> handbag.first >> handbag.second;

	int n; cin >> n;
	vector<pair<int,int>> object(n);
	for(auto &x:object) cin >> x.first >> x.second;

	for(int i = 0; i<n; i++){
		for(int j=0; j<n; j++){
			distances[i][j] = dist(object[i],object[j]);
		}
	}

	lli lim = (1<<n);
	for(int i=0; i<lim; i++){
		if(i)
			dp[i] = inf;
		else
			dp[i] = 0;
	}

	for(int i=0; i<lim; i++){//Para cada combinacion de objetos
		if(dp[i] < inf){//Vemos si alguien ya la optimizo
			for(int j=0; j<n; j++){//Y buscamos un objeto para agregarle
				if(!((i>>j)&1)){//Si esta apagado
					for(int k=j; k<n; k++){//Buscamos su pareja
						if(!((i>>k)&1)){//Si la pareja esta disponible
							int msk = i|(1<<j)|(1<<k); //Encendemos los bits de los objetos elegidos
							int cost = dp[i] + dist(handbag,object[j]) + distances[k][j] + dist(object[k],handbag); //Y calculamos la distancia
							if(dp[msk] > cost){ //Si hay una mejora
								dp[msk] = cost; //Actualizamos la DP
								track[msk] = i; //Y activamos el seguimiento de markess
							}
						}
					}
					break;
				}
			}
		}
	}

	cout << dp[(1<<n)-1] << endl;

	int trackId=(1<<n)-1;
	cout << "0 ";
	while(trackId != 0){
  		int dif = trackId ^ track[trackId];
		for(int i=0; i<32; i++){
			if(dif & (1<<i))
				cout << i+1 << " ";
		}
		trackId = track[trackId];
		cout << "0 ";
	}
	cout << endl;

	return 0;
}
