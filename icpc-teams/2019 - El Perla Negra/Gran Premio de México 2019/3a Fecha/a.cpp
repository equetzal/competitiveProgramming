#include <bits/stdc++.h>

using namespace std;

#define endl "\n";
#define x(c) real(c)
#define y(c) imag(c)

const double EPS = 1e-7;
const int oo = (1<<30);
typedef complex<double> point;

int s1,s2;

double dist(const point &a, const point &b){
	return abs(a-b);
}

struct circle{
	point center;
	double ratio;

	circle(point center, double ratio):center(center),ratio(ratio){}
};

bool circles_intersect(const circle &c1, const circle &c2){
	double d = dist(c1.center, c2.center);
	if(d > c1.ratio+c2.ratio || d+min(c1.ratio,c2.ratio) < max(c1.ratio, c2.ratio))
		return false;
	return true;
}

bool dfs(vector< vector<int> > &graph, int me, int father){
	if(graph[me].size() == 0){
		if(me == s1 || me == s2){
			return true;
		}else{
			return false;
		}
	}

	for(auto a:graph[me]){
		if(a != father){
			if(dfs(graph, a, me)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int m,n,k; cin >> m >> n >> k;

	vector<circle> sensors;

	for(int i=0; i<k; i++){
		double x,y,r; cin >> x >> y >> r;
		if(x+r > double(m-1) && x-r < double(0)){
			cout << "N" << endl;
		}
		sensors.push_back(circle(point(x,y),r));
	}

	vector< vector<int> > graph(sensors.size()+4);
	for(int i=0; i<sensors.size()-1; i++){
		for(int j=i+1; j<sensors.size(); j++){
			if(circles_intersect(sensors[i], sensors[j])){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	for(int i=0; i<sensors.size(); i++){
		if(sensors[i].center.x() - sensors[i].ratio < 0.0){
			graph[sensors.size()].push_back(i);
			graph[i].push_back(sensors.size());
		}
		if(sensors[i].center.y() - sensors[i].ratio < 0.0){
			graph[sensors.size()+1].push_back(i);
			graph[i].push_back(sensors.size()+1);
		}

		if(sensors[i].center.x() + sensors[i].ratio > double(m)){
					graph[sensors.size()+2].push_back(i);
					graph[i].push_back(sensors.size()+2);
				}

		if(sensors[i].center.x() + sensors[i].ratio < double(n)){
					graph[sensors.size()+3].push_back(i);
					graph[i].push_back(sensors.size()+3);
				}
	}

	s1 = sensors.size()+2;
	s2 = sensors.size()+3;


	if(dfs(graph, sensors.size(), sensors.size()) && dfs(graph, sensors.size()+1, sensors.size()+1)){
		cout << "N" << endl;
	}
	else{
		cout << "S" << endl;
	}

	return 0;
}