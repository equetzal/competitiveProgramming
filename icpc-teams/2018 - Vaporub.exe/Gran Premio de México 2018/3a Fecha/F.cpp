#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool seEmpalman(int aI, int aF, int bI,int bF){
	if(bI >= aI && bI < aF)
		return true;
	if(bF <= aF && bF > aI)
		return true;
	if(aI >= bI && aI < bF)
		return true;
	if(aF <= bF && aF > bI)
		return true;
	return false;
}

bool horarioUsado(pair <int, pair<int,int> > e, vector < pair <int, pair<int,int> > > &usados){
	bool esUsado = false;
	for(auto used:usados){
		if(seEmpalman(e.second.first, e.second.second, used.second.first, used.second.second))
			esUsado = true;
	}

	return esUsado;
}


int main(){
	int n;
	cin >> n;

	vector < priority_queue < pair <int, pair<int,int> > > > escenario(n);
	vector <bool> visited(n,false);
	vector < pair <int, pair<int,int> > > usados;

	for(int i=0; i<n; i++){
		int eventos;
		cin >> eventos;
		// cout << eventos << endl;

		while(eventos--){
			pair <int, pair<int,int> > ev;
			cin >> ev.second.first >> ev.second.second >> ev.first;
			// cout << i << ": " << ev.second.first << " " << ev.second.second << " "<< ev.first << endl;
			escenario[i].push(ev);
		}
	}

	for(auto a:escenario){
		// cout << "l";
		cout << a.top().first << " [" << a.top().second.first << ":" << a.top().second.second << "]\n";
	}

	while(true){
		// Checar si ya termine
		bool allEmpty = true;
		for(auto q:escenario){
			if(!q.empty())
				allEmpty = false;
		}

		if(allEmpty)
			break;

		cout << "Seleccion -------------------" << endl;
		for(auto a:escenario){
		// cout << "l";
		    // cout << "llego" << endl;
		    if(!a.empty())
				cout << a.top().first << " [" << a.top().second.first << ":" << a.top().second.second << "]\n";
		}

		// Seleccion
		int q_max = -1;
		int c_max = -1;
		for(int i=0; i<n; i++){
			if(!escenario[i].empty())
				if(escenario[i].top().first > c_max){
					q_max = i;
					c_max = escenario[i].top().first;
				}
			else
				continue;
		}

		auto pivote = escenario[q_max];
		bool pivoteEstaLibre = true;
		for(int i=0; i<n; i++){
			if(i != q_max){
				if(!escenario[i].empty())
					if(seEmpalman(escenario[i].top().second.first, escenario[i].top().second.second, pivote.top().second.first, pivote.top().second.second)){
						pivoteEstaLibre = false;
						// ChecarAlternativas
						bool exiteAlt = false;
						auto mejorOp = escenario[i].top();
						int mejorOpPos = i;
						escenario[i].pop();
						while(!escenario[i].empty()){
							if(seEmpalman(escenario[i].top().second.first, escenario[i].top().second.second, pivote.top().second.first, pivote.top().second.second) || horarioUsado(escenario[i].top(), usados)){
								escenario[i].pop();
							}else{
								if(horarioUsado(escenario[i].top(), usados)){
									escenario[i].pop();
								}else{
									exiteAlt = true;
									break;
								}
							}
						}
						if(exiteAlt){
							usados.push_back(escenario[q_max].top());
							escenario[q_max].pop();
							visited[q_max] = true;
							break;
						}else{
							escenario[q_max].pop();
							exiteAlt = false;
							while(!escenario[q_max].empty()){
								if(seEmpalman(escenario[q_max].top().second.first, escenario[q_max].top().second.second, mejorOp.second.first, mejorOp.second.second) || horarioUsado(escenario[q_max].top(), usados)){
									escenario[q_max].pop();
								}else{
									visited[mejorOpPos] = true;
									usados.push_back(mejorOp);
									if(!escenario[mejorOpPos].empty())
										escenario[mejorOpPos].pop();
									exiteAlt = true;
									break;
								}
							}
							if(!exiteAlt)
								if(visited[i] == false && visited[q_max] == true){
									usados.push_back(mejorOp);
									if(!escenario[i].empty())
										escenario[i].pop();
									if(!escenario[q_max].empty())
										escenario[q_max].pop();
									visited[i] = true;
								}else{
									usados.push_back(escenario[q_max].top());
									visited[q_max] = true;
									if(!escenario[q_max].empty())
										escenario[q_max].pop();
								}
						}
					}else{
						continue;
					}
				else
					continue;
			}
		}

		if(pivoteEstaLibre && !horarioUsado(escenario[q_max].top(), usados)){
			usados.push_back(escenario[q_max].top());
			visited[q_max] = true;
			escenario[q_max].pop();
		}else{
			if(!escenario[q_max].empty())
				escenario[q_max].pop();
		}




	}

	int suma=0;
	cout << "usados:\n";
	for(auto u:usados){
		suma += u.first;
		cout << u.first << " [" << u.second.first << ":" << u.second.second << "]\n";
	}


	bool visiteTodos = true;
	for(auto a:visited)
		if(!a)
			visiteTodos = false;
	if(!visiteTodos)
		cout << "-1\n";
	else{
		cout << suma << "\n";
	}
	




	return 0;
}