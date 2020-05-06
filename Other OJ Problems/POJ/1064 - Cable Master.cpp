//POJ 1064 - Cable Master

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>

using namespace std;

int proof(int mid, vector<int> &cables){
	int tot=0;
	// for(auto a:cables)
	// 	tot += (int)(a/mid);
	for(int i=0; i<cables.size(); i++)
		tot += cables[i]/mid;
	
	return tot;
}

float solution(int n, int k,vector<int> &cables){
	int mn = 0;
	int mx = 1000000;
	int mid;

	int it = 300;

	while(it--){
		mid = (mn+mx)/2;
		// cout << "cheking " << mid << " with " << proof(mid,cables) << endl;

		if(proof(mid, cables) >= k)
			mn = mid;
		else
			mx = mid;
	}

	// cout << mx << endl;
	float res = ((float)(mid))/100.00;
}

int main(){
	int n,k;
	cin >> n >> k;

	vector <int> cables(n);
	for(int i=0; i<n; i++){
		float c;
		cin >> c;
		c *= 100;
		cables[i] = (int)(c);
		// cout << "cable[" << i << "]: " << cables[i] << endl;
	}

	printf("%.2f\n", solution(n,k, cables));


	return 0;
}
