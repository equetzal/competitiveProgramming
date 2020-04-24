#include <iostream>
#include <cstdio>
using namespace std;

int coefficient (int n, int k){
	int cf = 0;

	if (k == 0)
		return 1;
	if (n == k)
		return 1;
	else 
		cf = coefficient(n - 1, k - 1) + coefficient (n - 1, k);

	return cf;
}
void makeCOF (int x, int y, int n){
	int pot = 0;

	pot = coefficient (n, y);
	if (pot != 1)
		printf ("%d", coefficient (n, y));	
	if (x != 0);
	if (x == 1)
		printf ("x");
	if (x > 0 && x != 1)
		printf ("x^%d", x);
	if (y != 0);
	if (y == 1)
		printf ("y");
	if (y > 0 && y != 1)
	 	printf ("y^%d", y);		
}

void printCOF (int n){
	for (int x = n, y = 0; x >= 0, y <= n; x--, y++){
		makeCOF (x, y, n);
		if (y < n)
			printf("+");
	}	
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T = 0;

	scanf ("%d", &T);
	int n[T];

	for (int i = 0; i < T; i++)
		scanf ("%d", &n[i]);

	for (int i = 0; i < T; i++){
		printCOF(n[i]);
		printf("\n");
	}
	return 0;	
}
