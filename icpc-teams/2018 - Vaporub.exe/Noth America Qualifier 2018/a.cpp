#include <bits/stdc++.h>

using namespace std;

int main(){
	vector < pair<int, vector<int> > > nums(3010, make_pair(0, vector<int>()));
	bool adj[105][105] = {false};
	int cards; cin >> cards;

	for(int i=1; i<=cards; i++){
		int x = 25;
		while(x--){
			int pos; cin >> pos;
			nums[pos].first++;
			nums[pos].second.push_back(i);
		}
	}

	bool sePuede = false;
	for(int i=0; i<3010; i++){
		if(nums[i].first > 1){
			sePuede = true;
			for(int a=0; a<nums[i].second.size()-1; a++){
				for(int b=a+1; b<nums[i].second.size(); b++){
					adj[min(nums[i].second[a],nums[i].second[b])][max(nums[i].second[a],nums[i].second[b])] = true;
					adj[max(nums[i].second[a],nums[i].second[b])][min(nums[i].second[a],nums[i].second[b])] = true;
				}
			}
		}
	}

	if(sePuede)
		for(int i=0; i<105; i++){
			for(int j=0; j<105; j++){
				if(adj[i][j]){
					cout << i << " " << j << endl;
				}
			}
		}
	else
		cout << "no ties\n";
}
