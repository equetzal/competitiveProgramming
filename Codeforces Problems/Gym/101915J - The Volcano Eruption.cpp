//CF Gym 101915J - The Volcano Eruption

#include<bits/stdc++.h>

using namespace std;

#define eps 1e-6

bool cross = true;

int check(int a,int b, vector< tuple<double,double,double> > &circle){
	double xx = (get<0>(circle[a])-get<0>(circle[b]))*(get<0>(circle[a])-get<0>(circle[b]));
	double yy = (get<1>(circle[a])-get<1>(circle[b]))*(get<1>(circle[a])-get<1>(circle[b]));
	double rr = (get<2>(circle[a])+get<2>(circle[b])+eps)*(get<2>(circle[a])+get<2>(circle[b])+eps);
	
    return  (xx+yy < rr);
}

void dfs(int u, int w, vector<bool> &visited, vector< tuple<double,double,double> > &circle){
	if(visited[u])
		return ;
	visited[u] = true;
	
	if(get<0>(circle[u]) + get<2>(circle[u]) >= w)
		cross = false;
	
	for(int v=0; v<circle.size(); v++){
		if(v==u)
			continue;
		if(!visited[v] && check(u,v, circle))
			dfs(v, w, visited, circle);
	}
	return;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		double w,l; cin >> w >> l;
		int holes=0;
		
		vector< tuple<double,double,double> > circle;
		vector<bool> visited(n,false);
		
		for(int i=0; i<n; i++){
			double x,y,r; cin >> x >> y >> r;
			circle.push_back(make_tuple(x,y,r));
		}
		for(int i=0; i<n; i++)
			if(get<0>(circle[i]) - get<2>(circle[i]) <= eps){
				cross = true;
				if(!visited[i])
					dfs(i, w, visited, circle);
				if(!cross)
					holes++;
			}
		cout << holes << endl;
    }
}
