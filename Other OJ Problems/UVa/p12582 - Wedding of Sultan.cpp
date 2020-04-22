//UVa p12582 - Wedding of Sultan

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
	int cases;
	cin >> cases;

	for(int z=0; z<cases; z++){
		cout << "Case " << z+1 << "\n";
		string way;
		cin >> way;

		vector <int> v(26,0);
		stack <char> S;
		S.push(way[0]);

		for(int i=1; i<way.size(); i++){
			if(S.size() != 0){
				if(way[i] == S.top()){
					S.pop();
				}else{
					v[S.top()-65]++;
					S.push(way[i]);
					v[S.top()-65]++;
				}
			}
		}

		for(int i=0; i<=25; i++){
			if(v[i] > 0){
				cout << (char)(i+65) << " = " << v[i] << endl;
			}
		}
	}


	return 0;
}
