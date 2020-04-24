#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
	string numero;
	int act, carga, aux;
	char temp;

	while(cin >> numero){
		act = 0;
		carga = 0;
		aux = 0;

		if(numero == "0")
			break;

		for(int i=0; i<numero.size(); i++){
			temp = numero[i];
			act = act + atoi(&temp);

			if(act>9){
				carga = act/10;
				act = act%10;

				aux= act+carga;

				act = aux;
			}
		}

		cout << act << endl;

	}
}