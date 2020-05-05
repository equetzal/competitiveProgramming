//HR crush - Array Manipulation

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int size, ops, posi, poso;
	long int val, max=0, temp=0;
	cin >> size >> ops;

	vector<long int> V(size+1, 0);

	for(int i=0; i<ops; i++){
		cin >> posi >> poso >> val;
		V[posi] += val;
		if(poso+1 <= size)
			V[poso+1] -= val;
	}

	for(int i=1; i<= size; i++){
		temp += V[i];
		if(max<temp)
			max = temp;
	}

	cout << max;

	return 0;
}
