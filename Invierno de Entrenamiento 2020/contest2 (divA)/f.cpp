//CF Gym 101972H - Beautiful Substrings

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define endl "\n"
#define MAXN 100010

int main(){
	lli t,n,m,k, totalSubStrings, endChars;
	char a[MAXN],b[MAXN];
	set< pair<char,char> > valids;

	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld %lld", &n, &m, &k);
		scanf("%s %s", a, b);
		valids.clear();

		for(int i=0; i<(n-k+1); i++){
			valids.insert(make_pair(a[i],a[i+k-1]));
		}

		totalSubStrings = 0;
		for(auto v:valids){
			endChars = 0;
			for(int i=m-1; i>=0; i--){
				if(b[i] == v.second)
					endChars++;
				if(b[i] == v.first)
					totalSubStrings += endChars;
			}
		}

		printf("%lld\n", totalSubStrings);
	}

	return 0;
}
