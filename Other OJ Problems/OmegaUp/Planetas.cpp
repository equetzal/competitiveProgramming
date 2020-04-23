//https://omegaup.com/arena/problem/Planetas/

#include <cstdio>
#include <algorithm>

using namespace std;

#define EPS 1e-11

double planets[1009];
int n;

double calcula(double punto){
	double answer = 0;
	for(int i = 0; i < n; i++)
		answer += 1/(planets[i] - punto);
	return answer;
}

double busca(double izq, double der){
	double medio;
	
	int maxi = 25;
	
	for(int i = 0; i < maxi; i++){
		medio = (izq + der) / 2;	
		if(calcula(medio) > 0){
			der = medio;
		}
		else{
			izq = medio;
		} 		
	}
	
	return izq;
}

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
		scanf("%lf", &planets[i]);
	
	sort(planets, planets + n);

	printf("%d\n", n - 1);
	
	for(int i = 1; i < n; i++)
		printf("%.3lf ", busca(planets[i-1], planets[i]));
}
