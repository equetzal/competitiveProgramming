//AIZU DSL_5_A - The Maximum Number of Customers

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int people, T;
	cin >> people >> T;

	vector < pair <int,char> > v;

	for(int i=0; i<people; i++){
		int xI, xF;
		cin >> xI >> xF;
		v.push_back(make_pair(xI,'E'));
		v.push_back(make_pair(xF,'A'));
	}

	sort(v.begin(), v.end());

	int count=0, max=0;
	for(auto a:v){
		if(a.second == 'E'){
			count++;
		}else{
			count--;
		}
		if(count > max){
			max = count;
		}
	}

    cout << max << endl;

    return 0;
}
