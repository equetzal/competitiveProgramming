#include <bits/stdc++.h>

using namespace std;

int n, m, pasos = 0;
char mapa[1000][1000];
bool pVisitado[1000][1000] = {false};
bool sVisidado[1000][1000] = {false};
bool tVisitado[1000][1000] = {false};
int distancia[1000][1000] = {0};

pair <int,int> salida;
pair <int,int> joel;

char buscando;

bool valida(int x, int y, int cual){
	if(x<0 || y<0)
		return false;
	if(x>=n || y>=m)
		return false;
	if(mapa[x][y] == '#')
		return false;
	switch(cual){
		case 1:
			if(pVisitado[x][y])
				return false;
		break;

		case 2:
			if(sVisidado[x][y])
				return false;
		break;

		case 3:
			if(tVisitado[x][y])
				return false;
		break;
	}

	return true;
}

int bfs1(pair <int,int> salida){
	queue < pair <int,int> > Q;
	pair <int,int> coord;
	Q.push(make_pair(salida,0));

	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;

		if(mapa[x][y] == 'F'){
			buscando = 'K';
			return	distancia[x][y];
		}

		if(mapa[x][y] == 'K'){
			buscando = 'F';
			return	distancia[x][y];
		}

		if(valida(x+1, y, 1)){
			distancia[x+1][y] = distancia[x][y] + 1;
			Q.push(make_pair(x+1,y));
		}
		if(valida(x-1, y, 1))
		if(valida(x, y-1, 1))
		if(valida(x, y+1, 1))

	}
}

int main(){
	int T;
	cin >> T;

	while(T--){

		cin >> n >> m;
		char read;

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> read;
				mapa[i][j] = read;
				if( read == 'J'){
					joel.first = i;
					joel.second = j;
				}
				if(read == 'E'){
					salida.first = i;
					salida.second = j;
				}
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << mapa[i][j];
			}
			cout << endl;
		}

		pasos = bfs1(salida);

		cout << pasos;




	}

	return 0;
}