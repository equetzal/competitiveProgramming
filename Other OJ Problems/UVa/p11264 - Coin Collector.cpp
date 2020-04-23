//UVa p11264 - Coin Collector

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int cases, size, numberOfCoins;
	long long int coin;

	cin >> cases;
	while(cases--){
		numberOfCoins = 1;
		cin >> size;
		vector <long long int> coins;

		while(size--){
			cin >> coin;
			coins.push_back(coin);
		}

		coin = coins[0];

		for(int i=1; i<coins.size()-1; i++){
			if(coin+coins[i] < coins[i+1]){
				coin += coins[i];
				numberOfCoins++;
			}
		}

		cout << numberOfCoins+1 << endl;

	}

	return 0;
}
