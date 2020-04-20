//CF Gym 100503D - Sequence analysis

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long lli;
 
long long nextNum(lli a, lli b, lli c, lli x) {
    return ((a*x)%c + (x%b)%c) % c;
}
 
int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lli a, b, c, lim = 2*1e7, tamCiclo, idx;
    cin >> a >> b >> c;
    
    lli cicloA, cicloB;
	cicloA = nextNum(a,b,c,1);
	cicloB = nextNum(a,b,c,cicloA);
    
    while(lim-- > 0 && cicloA != cicloB){
        cicloA = nextNum(a,b,c,cicloA);
        cicloB = nextNum(a,b,c,nextNum(a,b,c,cicloB));
    }
    
    if(lim <= 0){
        cout << -1 << endl;
        return 0;
    }
    
    idx = 0;
    cicloA = 1;
    while(cicloA != cicloB){
        cicloA = nextNum(a,b,c,cicloA);
        cicloB = nextNum(a,b,c,cicloB);
        idx++;
    }
    
    tamCiclo = 1;
    cicloB = nextNum(a,b,c,cicloA);
    while(cicloA != cicloB){
        cicloB = nextNum(a,b,c,cicloB);
        tamCiclo++;
    }
    
    cout << tamCiclo+idx << endl;
    return 0;
}
