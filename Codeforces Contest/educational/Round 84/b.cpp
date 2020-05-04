//CF ProblemSet 1327B - Princesses and Princes

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<bool> vGirls(n,false);
		set<int> guys;
		vector<queue<int>> girlPref(n);

		for(int i=0; i<n; i++){
			guys.insert(i);
			int k,v; cin >> k;
			for(int j=0; j<k; j++){
				cin >> v;
				v--;
				girlPref[i].push(v);
			}
		}
		int count = 0;
		for(int i=0; i<n; i++){
			while(!girlPref[i].empty()){
				int v = girlPref[i].front();
				girlPref[i].pop();

				if(guys.count(v) > 0){
					vGirls[i] = true;
					guys.erase(v);
					count++;
					break;
				}

			}
		}

		if(count < n){
			cout << "IMPROVE" << endl;
			int i=0;
			for(;vGirls[i] == true;i++);
			cout << i+1 << " " << (*guys.begin())+1 << endl;
		}else{
			cout << "OPTIMAL" << endl;
		}


	}

	return 0;
}
