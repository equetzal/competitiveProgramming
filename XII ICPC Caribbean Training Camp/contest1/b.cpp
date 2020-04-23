#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <set>

using namespace std;

template <typename flow_type, typename cost_type> struct min_cost_max_flow{
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

	void print_graph(){
		map<int, set<int> > graph;

		for(int i = 0; i<adj.size(); i++){
			for(auto ved:adj){
				for(auto ed:ved){
					graph[ed.src].insert(ed.dst);
					// if(ed.cost >= 0 && ed.cap > 0)
					// cout << ed.src << "-" << ed.dst << " "
					// 	<< ed.cap << " " << ed.cost << endl; 
				}
			}
		}

		for(auto g:graph){
			cout << g.first << " -> ";
			for(auto v:g.second){
				cout << v << " ";
			}
			cout << endl;
		}
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

		for (pq.push({dist[source] = 0, source}); !pq.empty();)
		{
			node p = pq.top(); pq.pop();

			if (dist[p.second] < p.first) continue;
			if (p.second == sink) break;

			for (edge &e : adj[p.second])
				if (e.flow < e.cap &&
					dist[e.dst] > dist[e.src] + rcost(e))
				{
					back[e.dst] = &e;
					pq.push({dist[e.dst] = dist[e.src] + rcost(e),
							 e.dst});
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

		bellman_ford(source); // remove negative costs

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
	int n; cin >> n;
	min_cost_max_flow <int,int> problem(2*n+2);

	for(int i=0; i<n; i++){
		int act, mA, mB, cost; cin >> act >> mA >> mB >> cost;
		problem.add_edge( 0, i+1, 1, 0);
		// cout << "Connecting: " << 0 << " --- " << i+1 << endl;

		for(int m=mA; m <= mB; m++){
			problem.add_edge( i+1, n+m, 1, cost*abs(m-act));
			// cout << "Connecting: " << i+1 << " --- " << n+m  << " c: " << cost*abs(m-act)<< endl;
		}
		problem.add_edge( n+i+1, 2*n+1, 1, 0);
		// cout << "Connecting: " << n+i+1 << " --- " << 2*n+1 << endl;

	}

	// problem.print_graph();
	auto res = problem.max_flow(0, 2*n+1);
	if(res.first < n)
		cout << "NIE" << endl;
	else 
		cout << res.second << endl;
	return 0 ;
}