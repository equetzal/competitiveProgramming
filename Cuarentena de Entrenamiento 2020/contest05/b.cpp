#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vari(v); int v; cin >> v;
#define varl(v); lli v; cin >> v;
#define readv(v); for(auto &x:v) cin >> x;
#define readvp(v); for(auto &x:v) cin >> x.first >> x.second;
#define printv(v); for(auto x:v) cout << x << " "; cout << endl;
#define printvp(v); for(auto x:v) cout << "(" <<  x.first << "," << x.second << ")" << endl;
#define multicase(t); lli t; cin >> t; while(t--)

template<typename flow_type, typename cost_type>
struct min_cost_max_flow{
	struct edge{
		size_t src, dst, rev;
		flow_type flow, cap;
		cost_type cost;
	};

	int n;
	vector<vector<edge>> adj;

	min_cost_max_flow(int n) : n(n), adj(n), potential(n), dist(n), back(n) {}

	void add_edge(size_t src, size_t dst, flow_type cap, cost_type cost){
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap, cost});
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, 0, -cost});
	}

	vector<cost_type> potential;

	inline cost_type rcost(const edge &e){
		return e.cost + potential[e.src] - potential[e.dst];
	}

	void bellman_ford(int source){
		for (int k = 0; k < n; ++k)
			for (int u = 0; u < n; ++u)
				for (edge &e : adj[u])
					if (e.cap > 0 && rcost(e) < 0)
						potential[e.dst] += rcost(e);
	}

	const cost_type oo = numeric_limits<cost_type>::max();

	vector<cost_type> dist;
	vector<edge*> back;

	cost_type dijkstra(int source, int sink){
		fill(dist.begin(), dist.end(), oo);

		typedef pair<cost_type, int> node;
		priority_queue<node, vector<node>, greater<node>> pq;

		for (pq.push({dist[source] = 0, source}); !pq.empty();){
			node p = pq.top(); pq.pop();

			if (dist[p.second] < p.first) continue;
			if (p.second == sink) break;

			for (edge &e : adj[p.second])
				if (e.flow < e.cap && dist[e.dst] > dist[e.src] + rcost(e)){
					back[e.dst] = &e;
					pq.push({dist[e.dst] = dist[e.src] + rcost(e), e.dst});
				}
		}

		return dist[sink];
	}

	pair<flow_type, cost_type> max_flow(int source, int sink){
		flow_type flow = 0;
		cost_type cost = 0;

		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;

		potential.assign(n, 0);
		dist.assign(n, 0);
		back.assign(n, nullptr);

		bellman_ford(source);

		while (dijkstra(source, sink) < oo){
			for (int u = 0; u < n; ++u)
				if (dist[u] < dist[sink])
					potential[u] += dist[u] - dist[sink];

			flow_type f = numeric_limits<flow_type>::max();

			for (edge *e = back[sink]; e; e = back[e->src])
				f = min(f, e->cap - e->flow);
			for (edge *e = back[sink]; e; e = back[e->src])
				e->flow += f, adj[e->dst][e->rev].flow -= f;

			flow += f;
			cost += f * (potential[sink] - potential[source]);

		}
		return {flow, cost};
	}
};

int main(){
	int n,m,q; cin >> n >> m >> q;
	int mat[m][n][n];

	min_cost_max_flow <int,int> mm(n*m);

	for(int k=0; k<m; k++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> mat[k][i][j];
			}
		}
	}

	for(int k=0; k<m; k++){
		for(int i=0; i<(n-1); i++){
			for(int j=i+1; j<n; j++){
				mm.add_edge(n*k+i, n*k+j, -mat[k][i][j], 0);
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int k1=0; k1<(m-1); k1++){
			for(int k2=k1+1; k2<m; k2++){
				mm.add_edge(n*k1+i, n*k2+i, 0, 1);
			}
		}
	}

	while(q--){
		cout << "Query " << q << endl;
		int s,t,l; cin >> s >> t >> l;

		int ans = 0;
		for(int k1=0; k1<m; k1++){
			for(int k2=k1; k2<m; k2++){
				auto p = mm.max_flow(n*k1+s, n*k2+t);
				if(p.second <= l){
					ans = min(ans, -p.first);
				}
			}
		}

		cout << ans << endl;
	}


	return 0;
}

