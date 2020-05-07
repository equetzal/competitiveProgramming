#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector< set<string> > stores(n); 
	while(k--){
		int i; string s; cin >> i >> s;
		stores[i].insert(s);
	}

	vector<int> ans, revAns;
	vector<string> ord;
	string temp;
	int t; cin >> t;
	while(t--){
		cin >> temp;
		ord.push_back(temp);
	}

	int j=0;
	for(auto s:ord){
		for(j; j<stores.size(); j++){
			if(stores[j].count(s) > 0){
				ans.push_back(j);
				break;
			}
		}
	}
	// for(auto i:ans){
	// 	cout << i << endl;
	// }

	if(ans.size() != ord.size()){
		cout << "impossible" << endl;
		return 0;
	}

	reverse(ord.begin(), ord.end());
	j=stores.size()-1;
	for(auto s:ord){
		for(; j>=0; j--){
			if(stores[j].count(s) > 0){
				revAns.push_back(j);
				break;
			}
		}
	}

	sort(revAns.begin(), revAns.end());

	// for(auto i:ans)
	// 	cout << i << endl;

	// for(auto i:revAns)
	// 	cout << i << endl;

	if(ans == revAns){
		cout << "unique" << endl;
	}else{
		cout << "ambiguous" << endl;
	}


}
