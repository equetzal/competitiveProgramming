//CF ProblemSet 1270C - Make Good

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
typedef long long int lli;

int main(){
	int t; cin >> t;
	while(t--){
		lli n; cin >> n;
		lli sum=0, xSum=0;

		lli temp;
		while(n--){
			cin >> temp;
			sum += temp;
			xSum = xSum ^ temp;
		}

		if(sum == 2*xSum){
			cout << 0 << endl;
			cout << endl;
			continue;
		}

		vector<lli> ans;
		lli add;

//cout << "sum: " << sum << " xor: " << xSum << endl;

		if(sum & 1){
			ans.push_back(1);
			sum += 1;
			xSum = xSum ^ 1;

			if(xSum == 0){
				add = sum;
				ans.push_back(add);
				xSum = xSum ^ add;
				sum += add;

			}else{
				add = xSum;
				ans.push_back(add);
				xSum = xSum ^ add;
				sum += add;

				add = sum;
				ans.push_back(add);
				xSum = xSum ^ add;
				sum += add;

			}

		}else{
			if(xSum == 0){
				add = sum;
				ans.push_back(add);
				xSum = xSum ^ add;
				sum += add;

			}else{
				add = xSum;
				ans.push_back(add);
				xSum = xSum ^ add;
				sum += add;

				add = sum;
				ans.push_back(add);
				xSum = xSum ^ add;
				sum += add;

			}
		}

//cout << "sum: " << sum << " xor: " << xSum << endl;

		cout << ans.size() << endl;
		for(auto a:ans)
			cout << a << " ";
		cout << endl;
	}

	return 0;
}
