#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Rombo{
	bool encontrado;
	int posIx;
	int posIy;
	int tam;	
}Rombo;

bool ValidaPosicion(int posY, int posX, int tam){
	if(posX < tam && posY < tam && posX >= 0 && posY >= 0)
		return true;

	return false;
}

bool ValidaRombo(int posY, int posX, vector <vector <char> > &Matrix, int tam, int agregado, bool primero, int &tamarindo){
	int x,y, Ag=-1, agrega;
	char c;
	tamarindo++;

	y=posY;
	x=posX;
	//cout << "Llega" << endl;

	if(ValidaPosicion(y+1,x,tam)){
		while(Matrix[y+1][x] != '.'){
			if(ValidaPosicion(y,x,tam)){
				Ag++;
				//cout << "Contando O num: " << Ag << endl;
				x++;
			}
			else{
				break;
			}
		}
	}

	if(Ag == -1){
		Ag++;
	}

	// return true;

	for(int i=1; i<=agregado; i++){
		x = posX-i;
		if(ValidaPosicion(y, x, tam)){
			if(Matrix[y][x] != 'O'){
				return false;
			}
		}

		x = posX+i;
		if(ValidaPosicion(y, x, tam)){
			if(Matrix[y][x] != 'O'){
				return false;
			}
		}
	}

	// return true;

	x = posX + agregado +1;
	//cout << "Valor y: " << y << "  Valor x: " << x << endl;
	if(ValidaPosicion(y, x, tam)){
		if(Matrix[y][x] != '.'){
			return false;
		}
	}

	x = posX - agregado -1;
	//cout << "Valor y: " << y << "  Valor x: " << x << endl;
	if(ValidaPosicion(y, x, tam)){
		if(Matrix[y][x] != '.'){
			return false;
		}
	}

	if(primero == false && agregado == 0){
		//cout << "Ya casi lacaba" << endl;
		x = posX;
		y = posY+1;
		if(ValidaPosicion(y, x, tam)){
			if(Matrix[y][x] != '.'){
				return false;
			}
		}
		return true;
	}

	//cout << "Valor agregado: " << agregado << "\tSiguiente valor contado Ag: " << Ag << endl;
	//cout << "Tamari: " << tamarindo << endl;

	if(Ag == agregado){
		return false;
	}
	if(Ag > agregado){
		//cout << "Aumenta" << endl;
		return ValidaRombo(posY+1, posX, Matrix, tam, agregado+1, false, tamarindo);
	}
	else{
		//cout << "Disminuye" << endl;
		return ValidaRombo(posY+1, posX, Matrix, tam, agregado-1, false, tamarindo);
	}
}

Rombo BuscaRombo(vector <vector <char> > &Matrix, int i, int j, int tam){
	int posX, posY;
	int tamarindo=0;
	Rombo Aux;
	posY = i-1;
	posX = j;

	if(ValidaPosicion(i,j,tam))
		//cout << "Posicion Valida" << endl;

	if(ValidaPosicion(posY, posX, tam)){
		//cout << "Arriba tiene algo" << endl;
		if(Matrix[posY][posX] != '.'){
			//cout << "El caracter superior no es valido" << endl;
			Aux.encontrado = false;
			return Aux;
		}
	}

	//cout << "El caracter superior es valido" << endl;

	// Aux.encontrado = true;
	// return Aux;
	Aux.encontrado = ValidaRombo(i, j, Matrix, tam, 0, true, tamarindo);

	if(Aux.encontrado){
		Aux.posIx = j;
		Aux.posIy = i;
		Aux.tam = tamarindo;
		return Aux;
	}
	else{
		return Aux;
	}
}

int main(){
	int max=0;
	int N;
	cin >> N;
	vector < vector < char > > Matrix(N, vector <char>(N));
	Rombo rombAux;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> Matrix[i][j];
		}
	}

	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<N; j++)
	// 		//cout << Matrix[i][j];
	// 	//cout << endl;
	// }

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			//cout << "Evaluando y: " << i << " x: " << j << "\tCaracter: " << Matrix[i][j] << endl;
			if(Matrix[i][j] == 'O'){
				rombAux = BuscaRombo(Matrix, i, j, N);
				if(rombAux.encontrado){
					if(rombAux.tam > max)
						max = rombAux.tam;
					//cout << "ACEPTADO NUEVO VALOR MAX: " << max << endl;
				}
				else{
					//cout << "RECHAZADO" << endl;
				}
			}
		}
		//cout << endl << endl << endl;
	}

	cout << max;

	return 0;
}