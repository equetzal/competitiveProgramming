//Original by https://codeforces.com/profile/Marckess - Late-Night Hunger
//https://codeforces.com/group/4Drl6UlALp/contest/264643/problem/A

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

struct point{
	ld x, y;
	point(): x(0), y(0){}
	point(ld x, ld y): x(x), y(y){}

	point operator+(const point &p) const{
		return point(x+p.x, y+p.y);
	}
	point operator-(const point &p) const{
		return point(x-p.x, y-p.y);
	}
	point operator*(const ld & k) const{
		return point(x * k, y * k);
	}
	point operator/(const ld &kk) const{
		return point(x/kk,y/kk);
	}
	point operator+=(const point &p){
		*this = *this+p;
		return *this;
	}
	point operator-=(const point &p){
		*this = *this-p;
		return *this;
	}
	point operator*=(const ld & p){
		*this = *this*p;
		return *this;
	}
	point operator/=(const ld &p){
		*this = *this/p;
		return *this;
	}

	point rotate(const ld & anguleishon) const{
		return point(x*cos(anguleishon) - y*sin(anguleishon), x*sin(anguleishon) + y*cos(anguleishon));
	}
	point perp() const{
		return point(-y,x);
	}

	ld dot(const point & p) const{
		return x*p.x + y*p.y;
	}
	ld cross(const point & p) const{
		return x*p.y - y*p.x;
	}
	ld norm() const{
		return x*x + y*y;
	}
	long double length() const{
		return sqrtl(x*x + y*y);
	}

	point unit() const{
		return (*this)/length();
	}

	bool operator==(const point &p) const{
		return eq(x,p.x) && eq(y,p.y);
	}
	bool operator!=(const point &p) const{
		return !(*this == p);
	}
	bool operator<(const point &p) const{
		if(eq(x,p.x))
			return le(y,p.y);
		return le(x,p.x);
	}
	bool operator>(const point &p) const{
		if(eq(x,p.x))
			return ge(y,p.y);
		return ge(x,p.x);
	}
};

int sgn(ld x){
	if(ge(x,0))
		return 1;
	if(le(x,0))
		return -1;
	return 0;
}

ld area(vector<point> &p){
	ld ans = 0;
	for(int i=0; i<p.size(); i++){
		ans += p[i].cross(p[ (i+1)%p.size() ]);
	}
	return abs(ans/2);
}

int main(){
	int n; cin >> n;
	vector<point> poligon;

	ld x,y;
	while(n--){
		cin >> x >> y;
		poligon.push_back(point(x,y));
	}

	ld maxArea = -1.0;
	for(int i=0; i<poligon.size(); i++){
		vector<point> triangle;
		triangle.push_back(poligon[i%poligon.size()]);
		triangle.push_back(poligon[(i+1)%poligon.size()]);
		triangle.push_back(poligon[(i+2)%poligon.size()]);
		maxArea = max(maxArea,area(triangle));
	}

	cout << setprecision(7) << fixed << maxArea << endl;

	return 0;
}
