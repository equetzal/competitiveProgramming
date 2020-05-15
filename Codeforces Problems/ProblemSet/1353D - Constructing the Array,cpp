//CF Problemset 1353D - Constructing the Array

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

int getPos(int l, int r){
	int v = r-l+1;

	if(v%2 == 1)
		return (l+r)/2;
	return (l+r-1)/2;
}

int sz(int l, int r){
	return r-(l-1);
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n+1);
		priority_queue<pair<int, pair<int,int> >> q;

		q.push(make_pair(sz(1,n), make_pair(-1,n)));
		int pos;
		for(int i=1; i<=n;){
			int l = q.top().second.first*-1;
			int r = q.top().second.second;
			if(!(v[l] == 0 && v[r] == 0)){
				q.pop();
				continue;
			}

			pos = getPos(l,r);
			v[pos] = i;

			q.push(make_pair(sz(l,pos-1), make_pair(l*-1, pos-1)));
			q.push(make_pair(sz(pos+1,r), make_pair((pos+1)*-1, r)));
			q.pop();
			i++;
		}

		for(int i=1; i<=n; i++)
			cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}
