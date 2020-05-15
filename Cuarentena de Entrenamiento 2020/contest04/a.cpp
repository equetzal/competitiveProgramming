#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vari(v); int v; cin >> v;
#define varl(v); lli v; cin >> v;
#define vecn(v,n); vector<lli> v(n);
#define readv(v); for(auto &x:v) cin >> x;
#define readvp(v); for(auto &x:v) cin >> x.first >> x.second;
#define printv(v); for(auto x:v) cout << x << " "; cout << endl;
#define printvp(v); for(auto x:v) cout << "(" <<  x.first << "," << x.second << ")" << endl;
#define multicase(t); lli t; cin >> t; while(t--)
#define MAXN 100010

lli ans[MAXN], habs[MAXN], gcdNode[MAXN], stz[MAXN], sol[MAXN];

lli gcd(lli a, lli b){
	lli r;
	while(b != 0) r = a % b, a = b, b = r;
	return a;
}

lli gcd(vector<lli> & nums){
	lli ans = 0;
	for(lli & num : nums) ans = gcd(ans, num);
	return ans;
}

pair<lli,pair<lli,lli>> dfs1(int me, int parent, vector<vector<int>> &graph){
	vector<lli> nums;
	lli subTreeSize = 1, bestAns = -1;
	nums.push_back(habs[me]);

	for(auto n:graph[me]){
		if(n != parent){
			auto nodeAns = dfs1(n,me,graph);
			subTreeSize += nodeAns.second.first;
			bestAns = max(bestAns, nodeAns.second.second);
			nums.push_back(nodeAns.first);
		}
	}
	gcdNode[me] = gcd(nums);
	if(gcdNode[me] != 1){
		bestAns = max(bestAns, subTreeSize);
	}

	ans[me] = bestAns;
	stz[me] = subTreeSize;

	return make_pair(gcdNode[me], make_pair(subTreeSize, bestAns));
}

void dfs2(int me, int parent, vector<vector<int>> &graph){
	lli mySol = -1;
	for(auto n:graph[me]){
		mySol = max(mySol,ans[n]);
	}
	if(gcdNode[me] != 1){
		mySol = max(mySol, stz[me]);
	}
	sol[me] = mySol;

	for(int n:graph[me]){
		if(n != parent){
			lli myOldGcd = gcdNode[me];
			lli myOldMax = ans[me];
			lli childOldGcd = gcdNode[n];
			lli childOldMax = ans[n];

			vector<lli> nums;
			lli mx = -1;
			nums.push_back(habs[me]);
			for(auto myChild:graph[me])
				if(myChild != n){
					nums.push_back(gcdNode[myChild]);
					mx = max(mx, ans[myChild]);
				}
			gcdNode[me] = gcd(nums);
			stz[me] = stz[me] - stz[n];

			stz[n] = stz[n] + stz[me];
			gcdNode[n] = gcd(gcdNode[me],gcdNode[n]);

			if(gcdNode[me] != 1){
				mx = max(mx, stz[me]);
			}

			dfs2(n,me,graph);

			stz[n] = stz[n] - stz[me];
			ans[n] = childOldMax;
			gcdNode[n] = childOldGcd;
		}
	}
}


int main(){
	fast_io
	varl(n);
	for(lli i=0; i<n; i++){
		cin >> habs[i];
	}
	vector<vector<int>> graph(n);

	int u,v;
	for(int i=0; i<(n-1); i++){
		cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//Rooting on 0
	dfs1(0, -1, graph);

	//Re-rooting on 1 to n-1
	dfs2(0, -1, graph);

	lli generalSol = -1;
	for(int i=0; i<n; i++){
		generalSol = max(generalSol, sol[i]);
	}

	cout << generalSol << endl;

	return 0;
}

