#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int comp_num(const void* a, const void* b){
    unsigned long int* arg1 = (unsigned long int*) a;
    unsigned long int* arg2 = (unsigned long int*) b;
    if (*arg1 < *arg2) return -1;
    else if (*arg1 == *arg2) return 0;
    else return 1;
}

int main(){
	
	// Entra cantidad de numeros
	int N;
	cin >> N;

	// Entrada de Numeros
	unsigned long int num[N], temp, *numP;
	for(int i=0; i<N; i++)
		cin >> num[i];
	numP = num;

	// Ordenamiento

	std::qsort(numP, N, sizeof(unsigned long int), comp_num);
	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<N; j++){
	// 		if(num[i] > num[j]){
	// 			temp = num[i];
	// 			num[i] = num[j];
	// 			num[j] = temp;
	// 		}
	// 	}
	// }

	// Busqueda

	for(int i=0; i<N; i++){
		cout << num[i] << " ";
	}

	// Entrega de Resultado


}
