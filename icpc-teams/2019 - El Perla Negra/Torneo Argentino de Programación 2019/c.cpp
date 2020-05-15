#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
typedef long long int lli;

int n,m;
char baul[2010][2010];
bool visitado[2010][2010];

bool isValid(int x, int y){
	if(x < 0 || y < 0)
		return false;
	if(x > n || y > m)
		return false;
	return true;
}

bool isCross(int x, int y){
	if(isValid(x,y)){
		if(baul[x][y] != '*')
			return false;
	}else{
		return false;
	}
	if(isValid(x-1,y)){
		if(baul[x-1][y] != '*')
			return false;
	}else{
		return false;
	}
	if(isValid(x+1,y)){
		if(baul[x+1][y] != '*')
			return false;
	}else{
		return false;
	}
	if(isValid(x,y-1)){
		if(baul[x][y-1] != '*')
			return false;
	}else{
		return false;
	}
	if(isValid(x,y+1)){
		if(baul[x][y+1] != '*')
			return false;
	}else{
		return false;
	}
	return true;
}

int countUp(int x, int y){
	int ans = 0;
	for(int i=x-1; i>=0; i--){
		if(!visitado[i][y] && baul[i][y] == '*'){
			if(baul[i][y-1] == '*' || baul[i][y+1] == '*'){
				return -1;
			}else{
				visitado[i][y] = true;
				ans++;
			}
		}else{
			break;
		}
	}
	return ans;
}

int countDown(int x, int y){
	int ans = 0;
	for(int i=x+1; i<n; i++){
		if(!visitado[i][y] && baul[i][y] == '*'){
			if(baul[i][y-1] == '*' || baul[i][y+1] == '*'){
				return -1;
			}else{
				visitado[i][y] = true;
				ans++;
			}
		}else{
			break;
		}
	}
	return ans;
}

int countLeft(int x, int y){
	int ans = 0;
	for(int i=y-1; i>=0; i--){
		if(!visitado[x][i] && baul[x][i] == '*'){
			if(baul[x-1][i] == '*' || baul[x+1][i] == '*'){
				return -1;
			}else{
				visitado[x][i] = true;
				ans++;
			}
		}else{
			break;
		}
	}
	return ans;
}

int countRight(int x, int y){
	int ans = 0;
	for(int i=y+1; i<m; i++){
		if(!visitado[x][i] && baul[x][i] == '*'){
			if(baul[x-1][i] == '*' || baul[x+1][i] == '*'){
				return -1;
			}else{
				visitado[x][i] = true;
				ans++;
			}
		}else{
			break;
		}
	}
	return ans;
}

int main(){
	cin >> n >> m;
	memset(visitado, 0, sizeof(visitado));

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> baul[i][j];
		}
	}

	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visitado[i][j] && isCross(i,j)){
				// cout << "Es cruz en " << i << "," << j << endl;
				int a,b,c,d;
				a = countUp(i,j);
				b = countDown(i,j);
				c = countLeft(i,j);
				d = countRight(i,j);

				// cout << "a:" << a << endl;
				// cout << "b:" << b << endl;
				// cout << "c:" << c << endl;
				// cout << "d:" << d << endl;

				if(a != -1 && b != -1 && c != -1 && d != -1){
					if(a < b && c == d && a == c){
						ans++;
					}
				}
			}
			// visitado[i][j] = true;
		}
	}	

	cout << ans << endl;



	return 0;
}