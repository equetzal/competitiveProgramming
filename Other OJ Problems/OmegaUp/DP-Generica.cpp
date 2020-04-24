//https://omegaup.com/arena/IE1/#problems/DP-Generica

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

//Global alv
map< pair < unsigned long long int,int > ,long long int > valoresDP;

unsigned long long int maxi(int potencia){
	return (1ULL<<(potencia+2)) - 2;
}

long long int dePe(unsigned long long int num, int potencia){
	pair < unsigned long long int,int > combinacion = make_pair(num, potencia);

	if (num == 0)
		return 1;

	if (potencia < 0)
		return 0;

	if (potencia < 63 && maxi(potencia) < num)
		return 0;

	if (valoresDP.find(combinacion) != valoresDP.end()){
		// cout << "La solucion ya existe";
		return valoresDP[combinacion];
	}

	valoresDP[combinacion] += dePe(num, potencia-1);

	if (num >= (1ULL << potencia)){
		valoresDP[combinacion] += dePe(num - (1ULL<<potencia), potencia-1);
	}

	if (potencia < 63 && num >= (1ULL << (potencia+1))){
		valoresDP[combinacion] += dePe(num - (1ULL<<(potencia+1)), potencia-1);
		// cout << "Entro";
	}

	return valoresDP[combinacion];
}

int main(){
	unsigned long long int num;
	cin >> num;

	cout << dePe(num, 63) << "\n";
}
