#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ld;

int main(){
	int n; cin >> n;
	ld prob[n][n];
	vector< ld > p(n), q(n), qAc(n);

	ld t;
	for(int i=0; i<n; i++){
		cin >> t;
		p[i] = t/100.0;
	}

	sort(p.rbegin(), p.rend());

	for(int i=0; i<n; i++){
		q[i] = 1.0-p[i];
	}

	qAc[0] = q[0];
	for(int i=1; i<n; i++){
		qAc[i] = q[i]*qAc[i-1];
	}

	prob[0][0] = p[0];

	for(int lvl=1; lvl<n; lvl++){
		for(int var=0; var<=lvl; var++){
			if(var == 0){
				prob[lvl][var] = prob[lvl-1][var]*p[lvl];
				continue;
			}
			if(var == lvl){
				prob[lvl][var] = qAc[lvl-1]*p[lvl] + prob[lvl-1][var-1]*q[lvl];
				continue;
			}
			prob[lvl][var] = prob[lvl-1][var]*p[lvl] + prob[lvl-1][var-1]*q[lvl];
		}
	}

	ld ans = numeric_limits<ld> :: min();
	for(int lvl=0; lvl<n; lvl++){
		ld val = 0.0;
		for(int var=0, ac=lvl+1; var<=lvl; var++, ac--)
			val += pow(double(ac), double(ac)/double(lvl+1))*prob[lvl][var];
		ans = max(ans,val);
	}

	cout << setprecision(8) << fixed << ans << endl;

}