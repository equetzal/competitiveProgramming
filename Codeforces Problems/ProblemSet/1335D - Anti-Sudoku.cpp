//CF ProblemSet 1335D - Anti-Sudoku

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		vector<string> mat(9);
		for(int i=0; i<9; i++){
			cin >> mat[i];
		}

		mat[1][1] = mat[1][0];
		mat[2][5] = mat[2][4];
		mat[0][6] = mat[0][5];
		mat[4][2] = mat[4][1];
		mat[5][4] = mat[5][3];
		mat[3][8] = mat[3][7];
		mat[7][0] = mat[7][8];
		mat[8][3] = mat[8][2];
		mat[6][7] = mat[6][6];

		for(int i=0; i<9; i++){
			cout << mat[i] << endl;
		}
	}

	return 0;
}

