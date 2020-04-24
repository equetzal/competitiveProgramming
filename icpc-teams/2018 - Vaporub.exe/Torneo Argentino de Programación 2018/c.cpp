//https://codeforces.com/group/YjFmW2O15Q/contest/101919
//TAP2018 - Complicando contrase˜nas

#include <bits/stdc++.h>
using namespace std;

int codigo[]={6,1,2,2,4,8,3,2};

int main() {
	long long aux=0;
	vector<long long> N;
	while(cin>>aux){
		N.push_back(aux);
	}
	
	for (long long i = 0; i < N.size(); ++i)
	{
		if(N[i]==1) cout<<'4';
		else if(N[i]==2) cout<<'6';
		else cout<< codigo[N[i]%8 ];

	}
	cout<<'\n';
	return 0;
}
