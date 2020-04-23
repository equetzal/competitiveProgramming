//UVa p280 - Vertex

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char mapa[100][100];
int cont, m, n;
char x;

bool verifica(int x, int y){
	if(x < 0 || y < 0)
		return false;
	if(x > m || y > n)
		return false;
	if(mapa[x][y] != '@')
		return false;
	return true;
}

void bfs(int x, int y){
	if(!verifica(x,y))
		return;

	queue < pair <int,int> > Q;
	Q.push(make_pair(x,y));

	cont++;

	while(!Q.empty()){
		x = Q.front().first;
		y = Q.front().second;
		mapa[x][y] = (char)(cont+'0');

		if(verifica(x+1, y))
			Q.push(make_pair(x+1,y));
		if(verifica(x-1,y))
			Q.push(make_pair(x-1,y));
		if(verifica(x,y+1))
			Q.push(make_pair(x,y+1));
		if(verifica(x,y-1))
			Q.push(make_pair(x,y-1));
		if(verifica(x+1, y+1))
			Q.push(make_pair(x+1,y+1));
		if(verifica(x+1,y-1))
			Q.push(make_pair(x+1,y-1));
		if(verifica(x-1,y+1))
			Q.push(make_pair(x-1,y+1));
		if(verifica(x-1,y-1))
			Q.push(make_pair(x-1,y-1));

		Q.pop();
	}

}

int main(){

	while(cin >> m >> n){
		if(m==0 && n==0)
			break;

		cont = 0;

		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				cin >> mapa[i][j];

		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++){
				bfs(i,j);
			}

		cout << cont << endl;

	}

	return 0;
}
