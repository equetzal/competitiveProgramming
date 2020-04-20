//CF ProblemSet 552D - Vanya and Triangles

#include <bits/stdc++.h>

using namespace std;

using ld = long double;
ld eps = 1e-9, inf = numeric_limits<ld>::max();

bool geq(ld a, ld b){return a-b >= -eps;}
bool leq(ld a, ld b){return b-a >= -eps;}
bool ge(ld a, ld b){return a-b > eps;}
bool le(ld a, ld b){return b-a > eps;}
bool eq(ld a, ld b){return abs(a-b) <= eps;}
bool neq(ld a, ld b){return abs(a-b) > eps;}

typedef long long int lli;

lli comb3(lli n){
	return (n*(n-1)*(n-2))/6;
}

int main(){
	lli n; cin >> n;
	lli totalTriangles = comb3(n);

	map<tuple<int,int,int>, set<pair<int,int>> > pendiente;
	vector< pair<int,int> > puntos;

	int x,y;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		puntos.push_back(make_pair(x,y));
	}

	for(int i=0; i<(n-1); i++){
		for(int j=i+1; j<n; j++){
			int a = puntos[j].second - puntos[i].second;
			int b = puntos[i].first - puntos[j].first;
			int c = puntos[i].first*puntos[j].second - puntos[j].first*puntos[i].second;
			int gcd = __gcd(a,__gcd(b,c));

			a /= gcd;
			b /= gcd;
			c /= gcd;

			if(a < 0){
				a *= -1;
				b *= -1;
				c *= -1;
			}
			if(a == 0 && b < 0){
				b *= -1;
				c *= -1;
			}

			pendiente[make_tuple(a,b,c)].insert(puntos[i]);
			pendiente[make_tuple(a,b,c)].insert(puntos[j]);
		}
	}

	for(auto s:pendiente){
		if(s.second.size() > 2){
			totalTriangles -= comb3(s.second.size());
		}
	}

	cout << totalTriangles << endl;

	return 0;
}
