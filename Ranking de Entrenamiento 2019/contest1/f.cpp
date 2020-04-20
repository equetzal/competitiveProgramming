//Two Cats - CF Gym 101875C

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int lli;
#define modulo 1000000007
 
map<lli,lli> primeFrec;
map<int,lli> numOfPrime;
int id;
 
void primeFactors(lli n){ 
    while(!(n&1)){ 
    	primeFrec[2]++;
        n = n/2; 
    } 
 
    lli sq = sqrt(n);
    for(lli i = 3; i <= sq+2; i += 2){ 
        while (n%i == 0){
        	primeFrec[i]++; 
            n = n/i; 
        } 
    } 
 
    if(n > 2)
    	primeFrec[n]++; 
}
 
 
lli dp[10010][1010];
lli go(lli b, int lvl, lli prod){
    if(lvl >= id)
        return 0;
    
    if(dp[lvl][prod] != -1)
        return dp[lvl][prod];
    
    lli nOfB = 0;    
    for(int exp=0; exp<=primeFrec[numOfPrime[lvl]]; exp++){
        lli nProd = (exp+1)*prod;
        if(nProd == b)
            nOfB++;
        else if(nProd < b){
            nOfB += go(b,lvl+1,nProd);
        }else{
            break;
        }
    }
    dp[lvl][prod] = nOfB % modulo;
    return dp[lvl][prod];
}
 
int main(){
	lli b,n,t; cin >> b >> n;
	
	if(b == 1 && n == 1){
		cin >> t; 
		if(t == 1)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
 
	for(lli i=0; i<n; i++){
		cin >> t;
		primeFactors(t);
	}
 
	id = 0;
	for(auto p:primeFrec){
		numOfPrime[id++] = p.first;
	}
 
    memset(dp, -1, sizeof(dp));
	cout << go(b,0,1) << endl;
    
	return 0;
}
