//HR truck-tour

#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;


int main(){
	queue<int> q;
	int n; cin >> n;
	vector<pair<int,int>> v(n);
	for(auto &x:v) cin >> x.first >> x.second;
	for(int i=0; i<n; i++) q.push(i);

	lli sum = 0, idx=n-1, i=0;
	while(true){
		i = q.front();
		sum += v[i].first - v[i].second;

		if(idx == i){
			cout << i+1 << endl;
			break;
		}

		if(sum >= 0){
			q.push(i);
			q.pop();
		}else{
			idx = i;
			q.push(i);
			q.pop();
			sum = 0;
		}
	}
}
