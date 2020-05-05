//HR divisible-sum-pairs - Divisible Sum Pairs

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int size, res, count=0;
	cin >> size >> res;

	vector<int> V(size);

	for(int i=0; i<size; i++)
		cin >> V[i];

	for(int i=0; i<size; i++)
		for(int j=i+1; j<size; j++)
			if((V[i] + V[j])%res == 0)
				count++;
	cout << count;
	
	return 0;
}
