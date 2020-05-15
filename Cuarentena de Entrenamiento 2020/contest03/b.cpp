#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;
typedef lli ll;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef struct data{
	int light; //0 for on, 1 for off
	lli sizeOfSubtree;
	lli numOfLightsOff;
	vector<int> route;

	bool rootChange;
	bool childsChange;
}data;

vector<int> way;
pair<lli,lli> dfs(int me, int parent, vector< pair< data, vector<int> > > &graph){
	
	graph[me].first.sizeOfSubtree = 1;
	graph[me].first.numOfLightsOff = graph[me].first.light;
	graph[me].first.route = way;

	way.push_back(me);
	for(auto child:graph[me].second){
		if(child != parent){
			auto p = dfs(child,me,graph);
			graph[me].first.sizeOfSubtree += p.first;
			graph[me].first.numOfLightsOff += p.second;
		}
	}
	way.pop_back();

	return make_pair(graph[me].first.sizeOfSubtree, graph[me].first.numOfLightsOff);
}

void notNode(int me, vector< pair< data, vector<int> > > &graph){
	//Les digo a mis padres que si tienen una query, se tienen que recalcular.
	auto route = graph[me].first.route;
	for(int node:route){
		graph[node].first.rootChange = true;
	}

	//Me establezco como no calculado y no propagado.
	graph[me].first.childsChange = !graph[me].first.childsChange;
}

int getFather(int me, vector< pair< data, vector<int> > > &graph){
	if(me == 0){
		return 0;
	}
	return graph[me].first.route[graph[me].first.route.size()-1];
}


lli getLightsOff(int me, vector< pair< data, vector<int> > > &graph){
	if(graph[me].first.childsChange){ //Si yo tengo un not
		//Me actualizo yo
		if(graph[me].first.light == 1){
			graph[me].first.light = 0;
		}else{
			graph[me].first.light = 1;
		}
		graph[me].first.numOfLightsOff = graph[me].first.sizeOfSubtree - graph[me].first.numOfLightsOff;

		//Le digo a mis hijos que se deben propagar y recalcular
		int father = getFather(me,graph);
		for(int n:graph[me].second){
			if(n != father){
				graph[n].first.childsChange = !graph[n].first.childsChange;
			}
		}
	}

	if(graph[me].first.rootChange){ //Si alguno de mis subarboles se actualizó
		//Me recalculo
		graph[me].first.numOfLightsOff = graph[me].first.light;

		//Y le pido a mis hijos que se recalculen si tienen que hacerlo
		int father = getFather(me,graph);
		for(int n:graph[me].second){
			if(n != father){
				graph[me].first.numOfLightsOff += getLightsOff(n, graph);
			}
		}
	}

	//Regreso mi respuesta
	return graph[me].first.numOfLightsOff;
}

int main(){
	lli n; cin >> n;
	vector< pair< data, vector<int> > > graph(n);

	for(int i=0; i<n; i++){
		int light; cin >> light;
		if(light == 0)
			graph[i].first.light = 1;
		else
			graph[i].first.light = 0;

		graph[i].first.rootChange = false;
		graph[i].first.childsChange = false;
	}

	for(int i=0; i<(n-1); i++){
		int u,v; cin >> u >> v;
		u--; v--;
		graph[u].second.push_back(v);
		graph[v].second.push_back(u);
	}

	dfs(0,-1,graph);

	for(int i=0; i<n; i++){
		cout << i << " -> ";
		if(graph[i].first.light == 1)
			cout << "apagada" << endl;
		else
			cout << "encendida" << endl;
	}

	lli q; cin >> q;
	while(q--){
		int op,node; cin >> op >> node;
		node--;

		if(op == 1){
			notNode(node, graph);
		}else{
			auto path = graph[node].first.route;
			for(auto n:path)
				getLightsOff(n,graph);

			cout << getLightsOff(node, graph) << endl;
		}

	}

	return 0;
}
