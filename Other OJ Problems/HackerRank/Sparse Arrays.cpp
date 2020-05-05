//HR sparse-arrays - Sparse Arrays

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int lines, querys, count;
	
	cin >> lines;
	vector<string> V(lines);
	for(int i=0; i<lines; i++)
		cin >> V[i];

	cin >> querys;
	vector<string> Q(querys);
	for(int i=0; i<querys; i++)
		cin >> Q[i];

	for(int i=0; i<querys; i++){
		count = 0;
		for(int j=0; j<lines; j++){
			if(Q[i] == V[j])
				count++;
		}
		cout << count << "\n";
	}

	return 0;
}
