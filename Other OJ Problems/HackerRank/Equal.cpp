//HR equal - Equal

#include <iostream>
#include <vector>

using namespace std;

int acortar(vector<int> &A, int pos, int maxdif){
	bool yaEsta = true;
	int m, md, pm;
	vector<int> D(A.size());

	for(int i=1; i<A.size(); i++)
		if(A[1] != A[i])
			yaEsta = false;

	if(yaEsta == true)
		return 1;

	if(maxdif>=5){
		for(int i=0; i<A.size(); i++){
			if(i != pos){
				A[i] += 5;
			}
		}
	}
	else{
		if(maxdif>=2){
			for(int i=0; i<A.size(); i++){
				if(i != pos){
					A[i] += 2;
				}
			}
		}
		else{
			for(int i=0; i<A.size(); i++){
				if(i != pos){
					A[i] += 1;
				}
			}
		}
	}

	for(int i=0; i<A.size(); i++){
		cin >> A[i];
		if(i==0){
			pm = i;
			m = A[i];
		}
		if(A[i] > m){
			pm = i;
			m = A[i];
		}
	}

	for(int i=0; i<A.size(); i++){
		D[i] = m - A[i];
		if(i==0)
			md = D[i];
		if(D[i] > md)
			md = D[i];
	}

	cout << endl << endl;
	for(int i=0; i<A.size(); i++)
		cout << A[i] << " ";
	cout << endl;
	for(int i=0; i<A.size(); i++)
		cout << D[i] << " ";
	cout << endl << "Posicion: " << pm << "Max: " << m << "\tMax Dif: " << md << endl;

	return (1 + acortar(A, pm, md));
}

int main(){
	int cases, p, max, maxd, pos;
	cin >> cases;

	for(int c=0; c<cases; c++){
		cout << "-------------------------------------------------------------------------" << endl;
		cin >> p;
		vector<int> V(p);
		vector<int> D(p);

		for(int i=0; i<p; i++){
			cin >> V[i];
			if(i==0){
				pos = i;
				max = V[i];
			}
			if(V[i] > max){
				pos = i;
				max = V[i];
			}
		}

		for(int i=0; i<p; i++){
			D[i] = max - V[i];
			if(i==0)
				maxd = D[i];
			if(D[i] > maxd)
				maxd = D[i];
		}

		for(int i=0; i<p; i++)
			cout << V[i] << " ";
		cout << endl;
		for(int i=0; i<p; i++)
			cout << D[i] << " ";
		cout << endl << "Pos: " << pos << "\tMax: " << max << "\tMax Dif: " << maxd << endl;

		// cout << "Movimientos necesarios: " << acortar(V, pos, maxd);

		cout << acortar(V, pos, maxd) << endl;

	}

	return 0;
}
