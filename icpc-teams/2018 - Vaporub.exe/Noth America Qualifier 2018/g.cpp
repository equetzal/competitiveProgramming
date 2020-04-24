#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,contL=0,casaAct,contR=0;
	vector<int> sol;
	string cad; cin>>n; cin>>cad;

	casaAct=1;
	if(cad[0]=='L'){
		for(int i = casaAct-1; cad[i]!='R' && i<cad.size(); ++i){
			contL++;
		}
		casaAct+=contL;
		for(int i=0; i<casaAct; ++i){
			sol.push_back(casaAct-i);
		}
	}else 
		sol.push_back(1);

	while(casaAct <= cad.size()){
		contR=0;
		contL=0;

		for(int i = casaAct-1; i<cad.size() && cad[i]!='L' ; ++i){
			contR++;
		}
		for(int i = 1;  i<contR; ++i){
			sol.push_back(casaAct+i);
		}	
		
		casaAct+=contR;
		
		for (int i = casaAct-1; i<cad.size() && cad[i]!='R' ; ++i){
			contL++;
		}

		casaAct+=contL;
		for (int i = 0;  i<=contL; ++i){ 
			sol.push_back(casaAct-i);
		}
	}

	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << '\n';
	}

	return 0;
}
