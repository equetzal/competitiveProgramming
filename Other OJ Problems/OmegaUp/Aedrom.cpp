//https://omegaup.com/arena/problem/AERODROM/

#include <iostream>
#include <vector>

using namespace std;

typedef long long lli;

lli checkN(lli tPrueba, vector <lli> &tiempo, int mesas){
	lli total=0;
	for(lli i=0; i<mesas; i++)
		total += tPrueba/tiempo[i];
	return total;
}

lli searchTime(lli personas, vector<lli> &tiempo, int mesas){
	lli mn = 0, mx = 1e18+10;

	int it = 64;
	while(it--){
		lli mid = (mn+mx)/2;
		lli val = checkN(mid, tiempo, mesas);

		if(val >= personas)
			mx = mid;
		else
			mn = mid;
	}

	return mx;
}

int main(){
	lli mesas, personas;
	vector <lli> tiempo(100010);
	cin >> mesas >> personas;

	for(int i=0; i<mesas; i++)
		cin >> tiempo[i];

	cout << searchTime(personas, tiempo, mesas) << "\n";

	return 0;
}


