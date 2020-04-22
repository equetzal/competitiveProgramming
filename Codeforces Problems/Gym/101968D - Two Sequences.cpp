//CF Gym 101968D - Two Sequences

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define endl "\n"

int main(){
	multiset<int> A,B;
	lli n,k,temp;

	lli t; scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld", &n, &k);
		A.clear(); B.clear();

		for(lli i=0; i<n; i++){
			scanf("%lld", &temp);
			A.insert(temp);
		}

		for(lli i=0; i<n; i++){
			scanf("%lld", &temp);
			if(A.find(temp) != A.end()){
				A.erase(A.find(temp));
			}
			else{
				B.insert(temp);
			}
		}

		if(A.empty())
			cout << "YES" << endl;
		else if(A.size() == 1 && B.size() == 1 &&
			abs(*A.begin() - *B.begin()) <= k){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
