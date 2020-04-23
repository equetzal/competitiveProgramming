//UVa p10020 - Minimal Coverage

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

bool isOnRange(int posI, int posF, int posA){
	if(posI <= posA && posF >= posA)
		return true;
	return false;
}

int main(){
	int cases, goal, x1, x2, position, minimal;
	pair <int, int> range, Selected;
	priority_queue < pair <int,int> > Q;
	queue < pair <int,int> > O;
	bool end_case, bestRange, existSol;
	cin >> cases;

	for(int n_cases=0; n_cases<cases; n_cases++){
		cin >> goal;

		minimal = 0;
		position = 0;
		end_case = false;
		existSol = false;
		Selected = make_pair(1,1);

		while(!end_case){
			cin >> x1 >> x2;
			if(x1 == 0 && x2 == 0){
				end_case = true;
			}else{
				Q.push(make_pair((-1)*x2, (-1)*x1));
			}
		}

		while(Q.size() != 0){
			bestRange = false;
			existSol = false;
			while(!bestRange){ 
				if(Q.size() != 0){
					if(isOnRange( -Q.top().second, -Q.top().first, position)){ //Si se sale del rango no existe solucion
						existSol = true;
						if((-1*Q.top().second) <= position){ //Guarda el avance maximo
							Selected = Q.top();
							Q.pop();
						}else{
							bestRange = true;
						}
					}else{
						if(existSol == false)
							Q.pop();
						break;
					}
				}else{
					break;
				}
			}

			if(-Selected.first > position){
				position = -Selected.first;
				O.push(make_pair(-Selected.second, -Selected.first));
				minimal++;
			}
		}

		if(bestRange){
			position = -Selected.first;
			minimal++;
		}

		cout << minimal << "\n";
		while(O.size() != 0){
			cout << O.front().first << " " << O.front().second << "\n";
			O.pop();
		}
		cout << "\n";
	}

	return 0;
}
