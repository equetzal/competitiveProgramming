//Checkerboard - CF Gym 101875D

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long int sides, xi, yi, xf, yf, distMin, ans;
	cin >> sides >> xi >> yi >> xf >> yf;
 
	distMin = abs(min(xi,xf) - max(xi,xf)) + abs(min(yi, yf) - max(yi,yf));
	ans = ((sides - distMin)/2)+1;
 
	if(sides < distMin)
		ans = 0;
	if(xi == xf && yi == yf)
		ans = floor(sides/2);
 
	cout << ans << endl; 
}
