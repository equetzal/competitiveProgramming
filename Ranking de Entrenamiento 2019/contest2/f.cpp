//Watering System - CF ProblemSet 967B

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b,s=0; cin >> n >> a >> b;
	vector<int> holes(n);

	for(int i=0; i<n; i++){
		cin >> holes[i];
		s += holes[i];
	}

	sort(holes.begin()+1, holes.end(), greater<int>());

	int flow = holes[0]*a/s;
	if(flow >= b){
		cout << 0 << endl;
		return 0;
	}
	int numOfHoles=0;
	for(int i=1; i<n; i++){
		s -= holes[i];
		flow = holes[0]*a/s;
		if(flow >= b){
			cout << i << endl;
			return 0;
		}
	}

	return 0;	
}
