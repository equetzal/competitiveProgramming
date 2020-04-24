//UVaLive p6802 - Turtle Graphics

#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases; cin >> cases;

	for(int c=1; c<=cases; c++){
		int map[66][66] = {0};
		int x,y; cin >> x >> y;
		string instructions; cin >> instructions;

		char dir = 'N'; //North
		map[x][y]++;
		for(auto op:instructions){
			switch(op){
				case 'F':
					switch(dir){
						case 'N':
							y++;
						break;

						case 'S':
							y--;
						break;

						case 'E':
							x++;
						break;

						case 'W':
							x--;
						break;
					}
					map[x][y]++;
				break;

				case 'L':
					switch(dir){
						case 'N':
							dir = 'W';
						break;

						case 'S':
							dir = 'E';
						break;

						case 'E':
							dir = 'N';
						break;

						case 'W':
							dir = 'S';
						break;
					}
				break;

				case 'R':
					switch(dir){
						case 'N':
							dir = 'E';
						break;

						case 'S':
							dir = 'W';
						break;

						case 'E':
							dir = 'S';
						break;

						case 'W':
							dir = 'N';
						break;
					}
				break;
			}
		}

		int repeatedTiles = 0;
		for(int i=0; i<66; i++){
			for(int j=0; j<66; j++){
				// cout << map[i][j] << " ";
				if(map[i][j] > 1)
					repeatedTiles++;
			}
			// cout << "\n";
		}

		cout << "Case #" << c << ": ";
		cout << x << " " << y << " " << repeatedTiles << "\n";
	}
}
