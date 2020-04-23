//UVa p12405 - Scarecrow

#include <iostream>

using namespace std;

int main(void){
	int cases, size, scarecrows;
	char dirt;

	cin >> cases;

	for(int i=0; i<cases; i++){
		scarecrows = 0;
		cin >> size;

		for(int j=0; j<size; j++){
			cin >> dirt;
			if(dirt == '.'){
				scarecrows++;
				
				if(j+2 < size){
					j++;
					cin >> dirt;
					j++;
					cin >> dirt;
				} else if(j+1 < size){
					j++;
					cin >> dirt;
				} 
			}
		}

		cout << "Case " << i+1 << ": " << scarecrows << "\n";
	}

	return 0;
}
