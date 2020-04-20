//CF ProblemSet 993A - Two Squares

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

bool pointInLine(const point &a, const point &v, const point &p){
	return eq((p-a).cross(v),0);
}

bool pointInSegment(const point &a, const point &b, const point &p){
	return pointInLine(a,b-a,p) && leq((a-p).dot(b-p),0);
}

int intersectSegmentsInfo(const point &a, const point &b, const point &c, const point &d){
	point v1 = b-a;
	point v2 = d-c;
	int t = sgn(v1.cross(c-a)), u = sgn(v1.cross(d-a));

	if(t == u){
		if(t == 0){
			if(pointInSegment(a,b,c) || pointInSegment(a,b,d)
				|| pointInSegment(c,d,a) || pointInSegment(c,d,b)){
				return -1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else{
		return sgn(v2.cross(a-c)) != sgn(v2.cross(b-c));
	}
}

bool crossesRay(const point &a, const point &b, const point &p){
	return ge((geq(b.y,p.y) - geq(a.y,p.y)) * (a-p).cross(b-p),0);
}

bool pointInPerimeter(vector<point> &pol, const point &p){
	int n = pol.size();
	for(int i=0; i<n; i++){
		if(pointInSegment(pol[i], pol[(i+1)%n], p))
			return true;
	}
	return false;
}

bool pointInPolygon(vector<point> &pol, const point &p){
	if(pointInPerimeter(pol, p))
		return true;
	int n = pol.size();
	int rays = 0;

	for(int i=0; i<n; i++){
		rays += crossesRay(pol[i], pol[(i+1)%n], p);
	}
	if(rays&1 == 1)
		return true;
	else
		return false;
}


int main(){
	vector<point> cuadrado;
	vector<point> rombo;

	ld x,y;
	for(int i=0; i<4; i++){
		cin >> x >> y;
		cuadrado.push_back(point(x,y));
	}

	for(int i=0; i<4; i++){
		cin >> x >> y;
		rombo.push_back(point(x,y));
	}

	bool isInside = false;

	//Checar si algun punto vive dentro del otro
	for(int i=0; i<4; i++){
		if(pointInPolygon(cuadrado,rombo[i]))
			isInside = true;
		if(pointInPolygon(rombo,cuadrado[i]))
			isInside = true;
	}

	//Checar si los segmentos se intersectan
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(intersectSegmentsInfo(cuadrado[i%4], cuadrado[(i+1)%4], rombo[j%4], rombo[(i+1)%4])){
				isInside = true;
			}
		}
	}

	if(isInside)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}
