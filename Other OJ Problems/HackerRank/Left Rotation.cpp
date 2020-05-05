//HR array-left-rotation - Left Rotation

#include <iostream>
#include <vector>

using namespace std;

int main(){
	int size, rot;
	cin >> size >> rot;
	vector<int> V(size);
	vector<int> R(size);

	for(int i=0; i<size; i++)
		cin >> V[i];

	for(int i=0, k=rot; i<size; i++, k++){
		if(k == size)
			k=0;
		R[i] = V[k];
	}

	for(int i=0; i<size; i++)
		cout << R[i] << " ";


	return 0;
}
