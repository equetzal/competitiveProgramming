//CF ProblemSet 961E - Tufurama

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define MAXN 200005

vector<vector<int>> v(MAXN);
int a[MAXN], b[MAXN];
int n;

int low(int x){
	return x&-x;
}

lli sum(int x){
	lli ans=0;
	for(int i=x; i>=1; i-=low(i))
		ans += b[i];
	return ans;	
}

void add(int x, int p){
	for(int i=x; i<=n; i+=low(i))
		b[i]+=p;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[i] = min(n,a[i]);
		v[min(i-1, a[i])].push_back(i);		
	}
	
	lli ans=0; 
	for(int i=1; i<=n; i++){
		add(a[i],1);
		
		for(auto j:v[i])
			ans += sum(n)-sum(j-1);
	}
	
	cout << ans << endl;
	
	return 0;
}

