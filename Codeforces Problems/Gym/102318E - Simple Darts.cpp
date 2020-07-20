//CF Gym 102318E - Simple Darts
//UCF Locals 2017
//Los Hermanos Computadores de Paine - Coded by Quetzalli

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define endl "\n"

using ld = long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);

bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

struct point{
	ld x, y;
	point(): x(0), y(0){}
	point(ld x, ld y): x(x), y(y){}

	ld ang() const{
		ld a = atan2l(y, x); a += le(a, 0) ? 2*pi : 0; return a;
	}

	ld length() const{return sqrtl(x * x + y * y);}
};

int main(){
	int t; cin >> t;
	while(t--){
		lli divisions, inner,medium,outer;
		cin >> divisions >> inner >> medium >> outer;
		
		lli ans = 0;
		int p; cin >> p;
		ld x,y,dist,angle;
		vector<ld> section;
		ld act=0.0;
		section.push_back(act);
		for(int i=0; i<divisions; i++){
			act += 2*pi/divisions;
			section.push_back(act);
		}

		while(p--){
			cin >> x >> y;
			if(x == 0 && y == 0){
				ans += 50;
			}else{
				point p = point(x,y);
				if(p.length() < ld(inner)){
					ans += 50;
				}else{
					angle = p.ang();
					for(int i=0; i<divisions; i++){
						if(angle > section[i] && angle < section[i+1]){
							if(p.length() < ld(medium) && p.length() > ld(inner)){
								ans += (i+1)*2;
							}else if(p.length() < ld(outer)){
								ans += i+1;
							}
						}
					}

				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
