#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
	string cad;
	priority_queue <string> SR;
	stack <string> SO;

	int num, a, p;
	priority_queue <int> Q;

	queue <char> Order;

	while(cin >> cad){
		if(cad[cad.size()-1] != '.'){
			if(cad[0] > 47 && cad[0] < 58 || cad[0] == '-'){
			Q.push(-(atoi(&cad[0])));
			Order.push('N');
			}
			else{
				cad[cad.size()-1] = '\0';
				SR.push(cad);
				Order.push('C');
			}
		}
		else{
			for(int i=0, n = SR.size(); i<n; i++){
				SO.push(SR.top());
				SR.pop();
			}

			for(int i=Order.size(); i>0; i--){
				if(Order.front() == 'C'){
					cout << SO.top();
					SO.pop();
				}
				if(Order.front() == 'N'){
					cout << -Q.top();
					Q.pop();
				}
				Order.pop();
				if(i != 1 && i!=0){
					cout << ", ";
				}
				else{
					cout << ".";
				}
			}
			cout << "\n";
		}
	}
}
