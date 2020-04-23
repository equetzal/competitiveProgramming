//https://omegaup.com/arena/problem/Las-cuentas-del-hippie/

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int main(){
	int negras, cuentas; cin >> negras >> cuentas;
	vector<int> hilo(2*cuentas);

	for(int i=0; i<cuentas; i++){
		cin >> hilo[i];
		hilo[i+cuentas] = hilo[i];
	}

	int ans = INT_MAX;
	for(int cuentaInicio = 0; cuentaInicio < cuentas; cuentaInicio++){
		int encontradas = 0;
		int actCuenta = cuentaInicio; 
		while(encontradas < negras && actCuenta < 2*cuentas){
			if(hilo[actCuenta] == 0)
				encontradas++;
			actCuenta++;
		}

		ans = min(ans, actCuenta-cuentaInicio-encontradas);
	}
	cout << ans << endl;

}
