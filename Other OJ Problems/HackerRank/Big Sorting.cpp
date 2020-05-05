//HR big-sorting - Big Sorting

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
	int size;
	cin >> size;

	priority_queue<string> Q;
	string temp;
	unsigned long long int n;

	for(int i=0; i<size; i++){
		cin >> temp;
		cout << temp << endl;
		n = stoll(temp);
		Q.push(temp);
	}

	for(int i=0; i<size; i++){
		cout << Q.top() << "\n";
		Q.pop();
	}

	return 0;
}
