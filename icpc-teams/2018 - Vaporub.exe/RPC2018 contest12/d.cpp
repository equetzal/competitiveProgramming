#include <bits/stdc++.h>
using namespace std;
#define mod pow(10,9)+7

int main(){
	int N,modbact=0,moddato=0;
	bool negativo=false;
	long long int dato,bacterias=1;
	cin>>N;
	while(N--){
		cin>>dato;
		if(!negativo){
			if(dato>=mod){
				moddato=dato/mod;
				dato%=(long long int)mod;
			}

			bacterias=bacterias*2;
			modbact*=2;
			if(bacterias>=mod){
				modbact+=bacterias/mod;
				bacterias%=(long long int)mod;
			}

			bacterias-=dato;
			modbact-=moddato;
			if(bacterias<0 && modbact>0) bacterias+=mod;
			if(modbact<0 || (bacterias<0 && modbact<=0)) negativo=true;
			
		}
	}
	if(negativo) cout<<"error";
	else cout<<bacterias<<"";

	return 0;
}
