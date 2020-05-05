//HR 2D-array - 2D Array - DS

#include <iostream>

using namespace std;

int main(){

	int table[6][6], max=0, sum;

	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++)
			cin >> table[i][j];

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			sum=0;
			for(int a=0; a<3; a++)
				sum+=table[i][j+a];
			sum+=table[i+1][j+1];
			for(int a=0; a<3; a++)
				sum+=table[i+2][j+a];
			if(max==0 && i==0 && j==0)
				max=sum;
			if(sum>max)
				max=sum;
		}
	}

	cout << max;

	return 0;
}
