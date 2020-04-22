//UVa p10382 - Watering Grass

#include <iostream>
#include <list>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

int main(void){

	ios_base :: sync_with_stdio(false);
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	//Delaracion
	int sprinklers, numberOfSprinklers;
	float longitude, wide, advance;
	float circlePos, circleRad, circleCover;
	priority_queue < pair < float, float > > sprRange;
	pair< float, float > range;

	//Inicializacion
	advance = 0;
	numberOfSprinklers = 0;
	longitude = 0;

	while(cin >> sprinklers >> longitude >> wide){

		//Reinicia el valor del avance
		advance = 0;
		//Reinicia el numero de rociadores necesarios
		numberOfSprinklers = 0;

		//Obtener posicion x con su radio y transformar a coordenadas
		for(int i=0; i<sprinklers; i++){
			//Obtener posicion y radio
			cin >> circlePos >> circleRad;

			//Solo se usan circulos cuyo diametro sea mayor al ancho del campo
			if(circleRad*2 > wide){
				//Obtenemos la hipotenusa del punto de interseccion entre el campo y el circulo (La mitad del rango que ocupa)
				circleCover = sqrt(circleRad*circleRad - (wide/2)*(wide/2));

				//Obtenemos la posicion X inicial
				range.first = circlePos - circleCover;
				//Obtenemos la posicion X final
				range.second = circlePos + circleCover;

				//Cambiamos el signo del rango para ser ordenado ascendentemente en el heap
				range.first = range.first * -1;
				range.second = range.second * -1;
				//Metemos el ranco en el heap
				sprRange.push(range);
			}else{
				//Si el circulo es muy pequeño entra aqui.
				//cout << "Circulo muy pequenio" << endl;
			}
		}

		//En caso de que ningun roceador hubiera entrado (Todos muy pequeños), rechaza la salida.
		if(sprRange.size() == 0){
			cout << -1;
		}else{
			//Informa cuantos elementos hay por revisar.
			////cout << "Hay " << sprRange.size() << " valores" << endl;

			//Busqueda de rangos, no se detiene a menos que se avance la longitud del campo
			while(advance < longitude){
				//Revisamos el elemento mas cercano al origen X
				range = sprRange.top();

				//Revertimos los valores negativos a su valor original
				range.first *= -1;
				range.second *= -1;

				//Revisamos si el inicio del rango se encuentra dentro de la posicion x actual (El avance sobre la longitud).
				if(range.first <= advance){
					//El elemento mas cercano es accesible
					////cout << "El elemento mas cercano es accesible en " << range.first << endl;
					//Sacamos el elemento, pues ya esta guandado en range
					sprRange.pop();
					//Aumentamos el numero de rociadores pues a partir de aqui es seguro que al menos uno se usara.
					numberOfSprinklers++;

					//Buscamos si hay otro elemento en el rango con mayor cobertura en x
					bool nextIt;
					do{
						//Verificamos si el siguiente elemento esta dentro de la posicion X actual
						if((-sprRange.top().first) <= advance){

							//Ahora verificamos si el alcance en X es mayor que el rango seleccionado actual
							if((-sprRange.top().second) > range.second){
								////cout << "X1: " << -sprRange.top().first << "\tX2: " << -sprRange.top().second << endl;
								//Si su alcance es mayor, entonces convertimos el nuevo rengo en el siguiente rango
								range = sprRange.top();
								range.first *= -1;
								range.second *= -1;
								//Ahora sacamos el siguiente elemento para descartar el anterior rango
								sprRange.pop();
							}else{
								//En caso de que el alcance sea menor que el actual rango, simplemente descartamos el rango
								sprRange.pop();
							}
							nextIt = true;
						}else{ // Si el siguiente elemento se encuentra fuera de la posicion actual acabamos el ciclo para no seguir buscando
							nextIt = false;
						}
					}while(nextIt && sprRange.size() != 0);

					//En este punto "Range" tiene al elemento de mayor cobertura sobre X,
					//por lo que colocaremos el avance en el limite de este rango
					advance = range.second;

				}else{ //En caso de que la posicion mas cernana se mayor a la posicion actual, el problema no tiene solucion.
					numberOfSprinklers = -1;
				}

				//Imprime el numero de rociadores necesarios para cubrir el campo
				////cout << "Numero de rociadores necesarios por ahora: " << numberOfSprinklers << "\n";

				//Si el numero de rociadores es -1, iguala el avance a la longitud para terminar la busqueda
				if(numberOfSprinklers == -1){
					advance = longitude+1;
				}
			}

			//Decimos el numero de rociadores necesarios
			cout << numberOfSprinklers << "\n";

			//Vaciamos la cola si aun hay elementos
			while(sprRange.size() != 0){
				////cout << sprRange.size() << endl;
				sprRange.pop();
			}
		}
	}

}
