//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028E - Teams

#include<bits/stdc++.h>

using namespace std;

int arraygcd (vector<int> n ) {
	int res=n[0];
	for(int i = 1 ; i<n.size(); i++){
		res=__gcd( n[i], res);
	}

	return res;
}

int main(){
	int T = 0 ,k = 0, min= 10000000;
	cin>>T;
	while(T--){
		int N, aux = 0;
		cin>>N;
		vector<int> v;
		while(N--){
			cin>>aux;
			v.push_back(aux);			
		}
		int res= arraygcd(v);

		int m=0;
		for(int i = 0; i< v.size() ; i++){
			m+= floor(v[i]/ res);
		}

		cout<< res <<" "<< m<< "\n";
	}
	return 0;
}
