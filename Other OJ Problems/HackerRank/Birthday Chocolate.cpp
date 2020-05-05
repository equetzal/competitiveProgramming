//HR the-birthday-bar - Birthday Chocolate


#include <iostream>
#include <vector>

using namespace std;

int main(){
	int size, days, months, sum, count=0;
	cin >> size;
	vector<int> V(size);

	for(int i=0; i<size; i++)
		cin >> V[i];
	
	cin >> days >> months;

	for(int i=0; i<size; i++){
		sum=0;
		for(int k=0; k<months; k++){
			sum += V[i+k];
		}
		if(sum == days)
			count++;
	}

	cout << count << endl;

	return 0;
}
