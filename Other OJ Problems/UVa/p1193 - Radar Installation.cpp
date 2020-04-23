//UVa p1193 - Radar Installation

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int boyas, radio, numCaso=0;
	bool yaTodoAlv;

	while(cin >> boyas >> radio && !(boyas == 0 && radio == 0)){
		numCaso++;
		//Caso de Prueba
		int x, y, d;
		yaTodoAlv = false;
		int entradas = 0, radares = 0;
		bool banderita=false;
		vector < pair <float,bool> > v;

		while(boyas--){
			cin >> x >> y;
			if(y > radio){
				yaTodoAlv = true;
				radares = -1;
			}
			d = sqrt(radio*radio - y*y);
			v.push_back(make_pair(x - d, false));
			v.push_back(make_pair(x + d, true));
		}

		if(!yaTodoAlv){
			sort(v.begin(), v.end());

			entradas = 0; 
			radares = 0;
			banderita = false;

			for(auto a:v){
				if(!a.second){
					banderita = false;
				}
				if(a.second){
					if(banderita == false){
						radares++;
						banderita = true;
					}
				}
			}
		}
		cout << "Case " << numCaso << ": " << radares << endl;
	}

	cout << endl;


	return 0;
}
