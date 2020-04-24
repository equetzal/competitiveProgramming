//https://codeforces.com/group/YjFmW2O15Q/contest/101919
//TAP2018 - Galileo Galilei

#include <bits/stdc++.h>

using namespace std;

typedef long double Double;
const Double ERROR = 1e-9;
#define EQ(a,b) (fabs((a)-(b)) < ERROR)

Double distancia(pair<Double,Double> p1, pair<Double,Double> p2){
	return (p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second);
}

bool isRectangular(int a, int b, int c, vector< pair<Double,Double> > &points){
	Double dist[3];

	dist[0] = distancia(points[a], points[b]);
	dist[1] = distancia(points[a], points[c]);
	dist[2] = distancia(points[b], points[c]);

	if(dist[0] > dist[1] && dist[0] > dist[2])
		if(EQ(dist[1]+dist[2], dist[0]))
			return true;
		else
			return false;
	else if(dist[1] > dist[0] && dist[1] > dist[2])
		if(EQ(dist[0]+dist[2], dist[1]))
			return true;
		else
			return false;
	else //if(dist[2] > dist[1] && dist[2] > dist[0])
		if(EQ(dist[1]+dist[0], dist[2]))
			return true;
		else
			return false;

}


int main(){
	int n; cin >> n;
	vector< pair<Double,Double> > points(n);

	for(int i=0; i<n; i++){
		cin >> points[i].first >> points[i].second; 
	} 

	int triangles = 0;
	for(int i=0; i<n-2; i++){
		// cout << "entra \n";
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; k<n; k++){
				if(isRectangular(i,j,k, points))
					triangles++;
			}
		}
	}

	cout << triangles << "\n";
	return 0;
}
