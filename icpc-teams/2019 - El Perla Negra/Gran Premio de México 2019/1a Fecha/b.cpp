#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli fact[200010], t, n, k, temp, totJef, totSup;
bool Jef[100010];
string sup,jef;

void calcFact(lli M){ //Factorial Modulo M
	fact[0] = 1;
	for(lli i=1; i<200010; i++){
		fact[i] = (fact[i-1] * (i%M))%M;
	}
	return;
}

lli inv(lli b, lli M){
	lli u = 1, x = 0, s = b, t = M;
	while(s){
		lli q = t/s;
		swap(x -= u * q, u);
		swap(t -= s * q, s);
	}
	return (x %= M) >= 0 ? x : x + M;
}

lli combinatoria(lli n, lli k, lli M){ //nCk % M
	lli denom = (fact[k] * fact[n-k])%M;
	lli ans = (fact[n] * inv(denom,M))%M;
	return ans;
}

int main(){
	calcFact(986444689);
	cin >> t;
	while(t--){
		cin >> n >> k;
		getchar();
		getline(cin, sup);
		getline(cin, jef);
		
		memset(Jef,false, sizeof(Jef));
		
		totJef=0, totSup=0;
		stringstream in(jef);
		while(in >> temp){
			Jef[temp] = true;
			totJef++;
		}
		stringstream in2(sup);
		while(in2 >> temp){
			if(!Jef[temp]){
				totSup++;
			}
		}
		
		k -= 2*totJef;
		k -= totSup;
		if(k >= 0)
			cout << combinatoria(k+(n-1), (n-1), 986444689) << endl;
		else 
			cout << 0 << endl;
		
	}
	
	return 0;
}
