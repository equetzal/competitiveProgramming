#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n, k;
vector <int> v;

int calcula(int div) {

	int suma=0;
	for(auto a:v){
		suma += a/div;
	}
	return suma;
}

int binaria(int izq, int der) {
	int m, res = 0;

	while (izq <= der) {
		m = (izq + der) /2;
		int aux = calcula(m);
		if (aux == k) {
			res = m;
			izq = m + 1;
		} 
		else if(aux < k) {
			der = m - 1;
		}
		else
			izq = m + 1;
	}
	return res;
}

int main(){
	int T;
	cin >> T;

	while(T--){
		int size, suma=0, tot=0, div, maxN = -1;
		cin >> n >> k;

		for(int i=0; i<n; i++){
			cin >> size;
			//cout << size << endl;
			v.push_back(size);
			maxN = max(maxN, size);
			tot += size;
		}

		div = tot/k;
		//cout << "div: " << div << endl;
		int ans = binaria(1, maxN);

		cout << ans << "\n";
		v.clear();
		/*while (div > 0){
			suma=0;
			for(auto a:v){
				suma += a/div;
			}
			//cout << "suma: "<< suma << endl;
			if(suma >= k){
				cout << div << "\n";
				break;
			}
			div--;
		}*/


		//cout << res << "\n";
	}

	return 0;
}