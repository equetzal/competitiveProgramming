//CF Gym 101208J - Pollution Solution

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

vector<point> intersectLineCircle(const point &a, const point &v, const point &c, ld r){
	ld h2 = r*r - v.cross(c-a)*v.cross(c-a)/v.norm();
	point p = a+v*v.dot(c-a)/v.norm();
	if(eq(h2, 0)) return {p};
	else if(le(h2, 0)) return {};
	else{
		point u = v.unit() * sqrt(h2);
		return {p - u, p + u};
	}
}

vector<point> intersectSegmentCircle(const point &a, const point &b, const point &c, ld r){
	vector<point> pol = intersectLineCircle(a,b-a,c,r), ans;
	for(const point &p:pol){
		if(pointInSegment(a,b,p))
			ans.push_back(p);
	}
	return ans;
}

int pointInCircle(const point &c, ld r, const point &p){
	ld l = (p-c).length()-r;
	return (le(l,0) ? 1: (eq(l,0) ? -1 : 0));
}


ld signed_angle(const point &a, const point &b){
	return sgn(a.cross(b))*acosl(a.dot(b)/(a.length()*b.length()));
}

ld intersectPolygonCircle(const vector<point> &pol, const point &c, ld r){
	int n = pol.size();
	ld ans = 0;

	for(int i=0; i<n; i++){
		point p = pol[i], q = pol[(i+1)%n];
		bool p_inside = (pointInCircle(c,r,p) != 0);
		bool q_inside = (pointInCircle(c,r,q) != 0);

		if(p_inside && q_inside){
			ans += (p-c).cross(q-c);
		}else if(p_inside && !q_inside){
			point s1 = intersectSegmentCircle(p,q,c,r)[0];
			point s2 = intersectSegmentCircle(c,q,c,r)[0];
			ans += (p-c).cross(s1-c) + r*r*signed_angle(s1-c, s2-c);
		}else if(!p_inside && q_inside){
			point s1 = intersectSegmentCircle(c,p,c,r)[0];
			point s2 = intersectSegmentCircle(p,q,c,r)[0];
			ans += (s2-c).cross(q-c) + r*r*signed_angle(s1-c,s2-c);
		}else{
			auto info = intersectSegmentCircle(p,q,c,r);
			if(info.size() <= 1){
				ans += r*r*signed_angle(p-c,q-c);
			}else{
				point s2 = info[0], s3 = info[1];
				point s1 = intersectSegmentCircle(c,p,c,r)[0];
				point s4 = intersectSegmentCircle(c,q,c,r)[0];
				ans += (s2-c).cross(s3-c) + r*r*(signed_angle(s1-c,s2-c) + signed_angle(s3-c,s4-c));
			}
		}
	}
	return abs(ans)/2;
}


int main(){
	int n; cin >> n;
	ld r; cin >> r;

	vector<point> figure;

	ld x,y;
	while(n--){
		cin >> x >> y;
		figure.push_back(point(x,y));
	}

	point center = point(0.0,0.0);
	cout << setprecision(10) << fixed << intersectPolygonCircle(figure,center,r) << endl;

	return 0;
}
