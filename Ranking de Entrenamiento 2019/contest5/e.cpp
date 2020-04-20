//CF Gym 101522I - Inverted Signs

#include <bits/stdc++.h>

using namespace std;

int h[1000005], dif[1000005];
int mn1 = std::numeric_limits<int>::max();
int mn2 = std::numeric_limits<int>::max();

int main(){
	int n; cin >> n;
	long long int sum = 0;

	scanf("%d", &h[0]);

	for(int i=1; i<n; i++){
		scanf("%d", &h[i]);

		sum += abs(h[i]-h[i-1]);
		dif[i-1] = abs(-h[i]-h[i-1]) - abs(h[i]-h[i-1]);

		if(dif[i-1] < mn1){
			mn2 = mn1;
			mn1 = dif[i-1];
		}else{
			if(dif[i-1] < mn2){
				mn2 = dif[i-1];
			}
		}
	}

	if(mn1 < 0)
		sum += mn1;
	if(mn2 < 0)
		sum += mn2;

	cout << sum << endl;

	return 0;
}
