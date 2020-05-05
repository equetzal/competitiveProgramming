/* Next Permutation 
 * Given an array of digits, find the next bigger number that can be formed 
 * with the same digits in the original array.
 * A number is represented in order of the array
 * 
 * [1,2,5,2] = 1252
 * The next bigger number is 1522
 */

#include <bits/stdc++.h>

using namespace std;

int firstSlower(vector<int> v){
	int anterior = v[v.size()-1];
	for(int i=v.size()-2; i>=0; i--){
		if(v[i] < anterior){
			return i;
		}
		anterior = v[i];
	}
	return -1;
}

void nperm(vector<int> &v){
	int idx = firstSlower(v);
	if(idx == -1){
		reverse(v.begin(),v.end());
		return;
	}

	cout << v[idx] << endl;
	int idy = (upper_bound(v.begin()+idx+1,v.end(),v[idx]+1) - v.begin())-1;
	swap(v[idx],v[idy]);
	sort(v.begin()+idx+2, v.end());
	return;
}

int main(){
	vector<int> v;
	int temp;
	while(cin >> temp)
		v.push_back(temp);

//	next_permutation(v.begin(), v.end());
	nperm(v);
	for(auto i:v)
		cout << i;
	cout << endl;

	return 0;
}
