//Caribbean Camp 2019 - Contest2 - [D] Triumphal Arch, [ID]=4142
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

//dp[v] Min #archs constructes for subtrees before the king entrys that node

int dp[300010] = {-1};
bool visited[300010];

int calcSubTree(int workers, vector< vector<int> > &graph, int node, bool hasFather){ 
	// cout << workers << " trabajadores" << endl;
	visited[node] = true;
	if(dp[node] == -1){
		if(hasFather && graph[node].size() == 1)
			return dp[node] = 0;

		int neededWorkers = 0;
		for(auto u:graph[node]){
			if(dp[u] ==  -1 && visited[u] == false)
				dp[u] = calcSubTree(workers, graph, u, true); 

			neededWorkers += 1+dp[u];
		}
		dp[node] = max(0, neededWorkers-workers);
		// cout << node << " " << dp[node] << endl;
		return dp[node];
	}else
		return dp[node];
}

int solution(int maxWorkers, vector< vector<int> > &graph){
	char bin = 20;
	int mx = maxWorkers, mn = 0, md = (mx+mn)/2;


	while(bin--){//Binary Search Over Workers
		memset(dp, -1, sizeof(dp));
		memset(visited, false, sizeof(visited));
		int res = calcSubTree(md, graph, 0, false);
		// cout << "mx: " << mx << "\tmn: " << mn << "\tans[" << md << "]: " << res << endl;
		// for(int i = 0; i < graph.size(); i++){
		// 	cout << i+1 << " " << dp[i] << endl;
		// }
		if(res > 0){
			mn = md;
			md = (mx+mn)/2;
		}else{
			mx = md;
			md = (mx+mn)/2;
		}
	}

	return mx;
}

int main(){
	int n; cin >> n;

	vector< vector<int> > graph(n);
	int a,b;
	for(int i=0; i<(n-1); i++){
		cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int maxWorkers=graph[0].size();
	for(auto v:graph)
		maxWorkers = max(maxWorkers, (int)v.size()-1);

	// cout << maxWorkers << " top" << endl;
	cout << solution(maxWorkers+1, graph) << endl;

	return 0;
}