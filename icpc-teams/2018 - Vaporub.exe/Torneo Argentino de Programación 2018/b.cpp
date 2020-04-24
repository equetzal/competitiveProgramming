//https://codeforces.com/group/YjFmW2O15Q/contest/101919
//TAP2018 - Buenos amigos

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long D = 0, M = 0 , D1=0, N=0, D2=0, cont = 0;
	cin>> D>>M>>D1>>N>>D2;
	while(M--){
		if(D1<=D){ 
			cout<<"-1\n";
			 return 0;
		}
		D*=2;
		D=D-D1;
		cont++;
		if(D<=0) {
			cout<<cont<<'\n';
			return 0;
		}
	}
	while(N--){
		if(D2<=D){ cout<<"-1\n";  return 0;}
		D*=2;
		D=D-D2;
		cont++;	
		if(D<=0) {
			cout<<cont<<'\n';
			return 0;
		}
	}
	if(D>0) cout<<"-1\n";

	return 0;
}
