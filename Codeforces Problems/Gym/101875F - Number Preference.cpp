//CF Gym 101875F - Number Preference

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int N; cin >> N;
 
	map<long long int, int> m;
	set<long long int> h;
 
	int totalLikes = 0;
	for(int n=0; n<N; n++){
		int op, cant; cin >> op >> cant;
		
		if(op == 1)
			totalLikes++;
 
		while(cant--){
			long long int num; cin >> num;
			if(op == 2)
				h.insert(num);
			else{
				m[num]++;
			}
		}
	}
 
	for(long long int i:h){
		m[i] = -1;
	}
 
	long long int ans = 0;
	for(auto p:m){
		if(p.second == totalLikes)
			ans++;
	}
	if(totalLikes == 0)
		ans = 1000000000000000000 - h.size();
	cout << ans << endl;
}
