/* K-th most popular numbers in O(n)
 * Given an array of numbers, find the K numbers more popular
 * in O(n) time complexity
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long int lli;

vector<lli> solution(vector<lli> &v, int k){
	unordered_map<lli,int> frec; //val, frecReal
	//vector<int> frec(v.size());
	for(auto i:v)
		frec[i]++;

	vector< vector<lli> > bucket(v.size()+1);
	for(auto p:frec){
		bucket[p.second].push_back(p.first);
	}

	vector<lli> ans;
	for(int i=bucket.size()-1; i>=0 && k>0; i--){
		for(auto n:bucket[i]){
			ans.push_back(n);
			k--;
			if(k == 0)
				break;
		}
	}

	return ans;
}


int main(){
	int k; cin >> k;
	vector<lli> v;

	lli temp;
	while(cin >> temp)
		v.push_back(temp);

	auto sol = solution(v,k);
	for(lli i:sol)
		cout << i << endl;

	return 0;
}
