//https://codeforces.com/group/YjFmW2O15Q/contest/101919
//TAP2018 - A guardar

#include <bits/stdc++.h>

using namespace std;

pair<int,int> caja,sotano;

bool isValid(int x, int y, vector< vector<char> > &mapa){
	cout << "Checando si " << x << "," << y << " es valido\n";
	if(x < 0 || y < 0)
		return false;
	if(x >= mapa.size() || y >= mapa[0].size())
		return false;
	if(mapa[x][y] == '#')
		return false;
	return true;
}

void bfs(vector< vector<char> > &mapa, queue<char> &route, char estado){
	bool visitado[mapa.size()][mapa[0].size()][3];
	queue < pair< char, pair<int,int> > > q; //estado,x,y
	
	cout << estado << endl;
	q.push(make_pair(estado,caja));
	visitado[caja.first][caja.second] = true;

	pair<char, pair<int,int>> actual;
	while(!q.empty()){
		actual = q.front();
		int x = actual.second.first;
		int y = actual.second.second;
		q.pop();
		cout << "Pos: (" << x << "," << y << ")\n";

		switch(actual.first){
			case 'P':
			cout << "Esta parado\n";
				if(x == sotano.first && y == sotano.second)
					cout << "llegue we" << endl;
				//Derecha
				if(isValid(x,y+1,mapa) && isValid(x,y+2,mapa)){
					if(!visitado[x][y+1][1] && !visitado[x][y+2][1]){
						cout << "Derecha\n";
						visitado[x][y+1][1] = true;
						visitado[x][y+2][1] = true;
						q.push(make_pair('U', make_pair(x,y+2)));
					}
				}

				//Izquierda
				if(isValid(x,y-1,mapa) && isValid(x,y-2,mapa)){
					if(!visitado[x][y-1][1] && !visitado[x][y-2][1]){
						cout << "Izquierda\n";
						visitado[x][y-1][1] = true;
						visitado[x][y-2][1] = true;
						q.push(make_pair('U', make_pair(x,y-1)));
					}
				}

				//Arriba
				if(isValid(x+1,y,mapa) && isValid(x+2,y,mapa)){
					if(!visitado[x+1][y][2] && !visitado[x+2][y][2]){
						cout << "Arriba\n";
						visitado[x+1][y][2] = true;
						visitado[x+2][y][2] = true;
						q.push(make_pair('L', make_pair(x+2,y)));
					}
				}

				//Abajo
				if(isValid(x-1,y,mapa) && isValid(x-2,y,mapa)){
					if(!visitado[x-1][y][2] && !visitado[x-2][y][2]){
						cout << "Abajo\n";
						visitado[x-1][y][2] = true;
						visitado[x-2][y][2] = true;
						q.push(make_pair('L', make_pair(x-1,y)));
					}
				}				
			break;

			case 'U':
				//Arriba
				if(isValid(x,y+1,mapa)){
					if(!visitado[x][y+1][0]){
						visitado[x][y+1][0] = true;
						q.push(make_pair('P', make_pair(x,y+1)));
					}
				}

				//Abajo
				if(isValid(x,y-2,mapa)){
					if(!visitado[x][y+2][0]){
						visitado[x][y+2][0] = true;
						q.push(make_pair('P', make_pair(x,y-2)));
					}
				}

				//Derecha
				if(isValid(x+1,y,mapa) && isValid(x+1,y-1,mapa)){
					if(!visitado[x+1][y][1] && !visitado[x+1][y-1][1]){
						visitado[x+1][y][1] = true;
						visitado[x+1][y-1][1] = true;
						q.push(make_pair('U', make_pair(x+1,y)));
					}
				}

				//Izquierda
				if(isValid(x-1,y,mapa) && isValid(x-1,y-1,mapa)){
					if(!visitado[x-1][y][1] && !visitado[x-1][y-1][1]){
						visitado[x-1][y][1] = true;
						visitado[x-1][y-1][1] = true;
						q.push(make_pair('U', make_pair(x-1,y)));
					}
				}
			break;

			case 'L':
				//Arriba
				if(isValid(x,y+1,mapa) && isValid(x-1,y+1,mapa)){
					if(!visitado[x][y+1][2] && !visitado[x-1][y+1][2]){
						visitado[x][y+1][2] = true;
						visitado[x-1][y+1][2] = true;
						q.push(make_pair('L', make_pair(x,y+1)));
					}
				}

				//Abajo
				if(isValid(x,y-1,mapa) && isValid(x-1,y-1,mapa)){
					if(!visitado[x][y-1][2] && !visitado[x-1][y-1][2]){
						visitado[x][y-1][2] = true;
						visitado[x-1][y-1][2] = true;
						q.push(make_pair('L', make_pair(x,y-1)));
					}
				}

				//Derecha
				if(isValid(x+1,y,mapa)){
					if(!visitado[x+1][y][0]){
						visitado[x+1][y][0] = true;
						q.push(make_pair('P', make_pair(x+1,y)));
					}
				}

				//Izquierda
				if(isValid(x-1,y,mapa)){
					if(!visitado[x-1][y][0]){
						visitado[x-1][y][0] = true;
						q.push(make_pair('P', make_p21air(x-1,y)));
					}
				}
			break;
		}
	}
}

int main(){
	int n,m; cin >> n >> m;
	vector< vector<char> > mapa(m, vector<char> (n));


	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++){
			cin >> mapa[i][j];
			if(mapa[i][j] == 'C'){
				caja.first = i;
				caja.second = j;
			}
			if(mapa[i][j] == 'E'){
				sotano.first = i;
				sotano.second = j;
			}
		}

	queue<char> route;
	bfs(mapa, route, 'P');

	return 0;
}
