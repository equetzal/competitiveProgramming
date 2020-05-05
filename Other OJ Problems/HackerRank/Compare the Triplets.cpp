//HR compare-the-triplets - Compare the Triplets

#include <iostream>

using namespace std;

int main(){
	
	int a[3], b[3], bob=0, alice=0;
	scanf("%d %d %d", a[0], a[1], a[2]);
	scanf("%d %d %d", b[0], b[1], b[2]);    
    
	for(int i=0; i<4; i++){
		if(a[i] > b[i])
			alice++;
		if(a[i] < b[i])
			bob++;

	}

	cout << alice << " " << bob;

}
