//CF Gym 102020G - Gabrielmetry

#include <bits/stdc++.h>

using namespace std;

double distance(pair<double,double> p1, pair<double,double> p2){
	return sqrt(pow(p2.first-p1.first, 2) + pow(p2.second-p1.second, 2));
}

bool eq(double a, double b){
	if(abs(a-b) < 0.00001)
		return true;
	return false;
}

int main(){
	int n,m; cin >> n >> m;
	vector< pair<double,double> > P, Q;
	vector<double> distP, distQ;
	
	while(n--){
		double x,y; cin >> x >> y;
		P.push_back(make_pair(x,y));
	}
	
	while(m--){
		double x,y; cin >> x >> y;
		Q.push_back(make_pair(x,y));
	}
	
	double totalDistance = 0;
	for(int i=0; i<(P.size()-1); i++){
		distP.push_back(distance(P[i], P[i+1]));
		totalDistance += distance(P[i], P[i+1]);
	}
	
	for(int i=0; i<(Q.size()-1); i++){
		distQ.push_back(distance(Q[i], Q[i+1]));
	}
	
	int points = 0;
	double actDist = 0;
	int i=0, j=0;
	while(!eq(actDist, totalDistance) && i<distP.size() && j<distQ.size()){
		if(eq(distP[i], distQ[j])){
			actDist += distP[i];
			i++; j++;
			continue;
		}
		if(distP[i] > distQ[j]){
			actDist += distQ[j];
			distP[i] -= distQ[j];
			j++; points++;
			continue;
		}
		if(distP[i] < distQ[j]){
			actDist += distP[i];
			distQ[j] -= distP[i];
			i++; points++;
			continue;
		}
	}
	
	cout << points << endl;
	
	return 0;
}
