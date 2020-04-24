//2016 Al-Baath University Training Camp Contest-1
//CF Gym 101028I - March Rain
//UPSOLVING

#include <bits/stdc++.h>

using namespace std;

long long int tam;

long long int playHole(vector<long long int> &hoyos, long long int len){
	len--;
	long long int pos = hoyos[0]-1;
	long long int k=0; 
	for(auto h:hoyos)
		if(h > pos){
			pos = h+len;
			k++;
		}
	return k;
}

long long int search(vector<long long int> &hoyos, long long int k){
	long long int mn = 1, mx = tam;

	int it = 32;
	while(it--){
		long long int mid = (mn+mx)/2;
		long long int val = playHole(hoyos, mid);

		if(val < k)
			mx = mid;
		else if(val > k)
			mn = mid;
		else {
			mx = mid;
		}
	}

	return mx;
}

int main() {
	
	long long int TC, n, k;
	vector<long long int> hoyos;

	cin >> TC;
	while (TC--) {
		cin >> n >> k;
		tam = -1;
		hoyos.assign(n, 0);
		for (int i = 0; i < n; i++){
			cin >> hoyos[i];
			tam = max(hoyos[i], tam);
		}
		cout << search(hoyos, k) << endl;
	}
	return 0;
}
