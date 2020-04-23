#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n; scanf("%lld", &n);
	long long int cities[3][2];

	cities[0][0] = 0;
	cities[1][0] = 0;
	cities[0][1] = 0;
	cities[1][1] = 0;
	cities[2][0] = 0;
	cities[2][1] = 0;

	for(int i=0; i<n; i++){		
		cities[0][0] = cities[1][0];
		cities[1][0] = cities[2][0];
		cities[0][1] = cities[1][1];
		cities[1][1] = cities[2][1];

		scanf("%lld", &cities[2][0]);
		cities[2][1] = max(cities[2][0]+cities[0][1], cities[1][1]);
	}

	printf("%lld\n",cities[2][1]);
}