//UVa p10474 - Where is Marble?

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

pair<int,int> search(int num, vector < pair<int,int> > &marbles){
	int mn = 0;
	int mx = marbles.size();
	int toFind = num;
	int mid;

	while(mn <= mx){
		mid = (int)(((mx + mn) / 2) + 0.5);

		if(toFind == marbles[mid].first)
			return marbles[mid];
		else if(marbles[mid].first < toFind)
			mn = mid+1;
		else
			mx = mid-1;
	}

	return make_pair(-1,-1);
}

int main(){
	int N,Q,num;
	int testCase = 0;

	while(cin >> N >> Q){
		if(N == 0 && Q == 0) break;

		testCase++;
		vector< pair<int,int> > marbles;

		for(int i=1; i<=N; i++){
			cin >> num;
			if(num > 0 && num < 10000)
				marbles.push_back(make_pair(num,-1));
		}

		sort(marbles.begin(), marbles.end());

		marbles[0].second = 1;
		for(int i=0; i<marbles.size(); i++){
			if(marbles[i].first == marbles[i-1].first)
				marbles[i].second = marbles[i-1].second;
			else
				marbles[i].second = i+1;
 		}

		cout << "CASE# " << testCase << ":\n"; 
		while(Q--){
			cin >> num;
			pair <int,int> res = search(num, marbles);

			if(res.first == -1){
				cout << num << " not found\n";
			}else{
				cout << res.first << " found at " << res.second << "\n";
			}
		}
	}

	return 0;
}
