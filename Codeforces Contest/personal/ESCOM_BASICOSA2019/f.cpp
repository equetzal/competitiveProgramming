//CF ProblemSet 595A - Vitaly and Night

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m; cin >> n >> m;

	int ans=0;
	bool a,b;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a >> b;
			if(a || b)
				ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
