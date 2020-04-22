//CF ProblemSet 687B - Remainders Game

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli gcd(lli a, lli b){
	lli r;
	while(b != 0) r = a % b, a = b, b = r;
	return a;
}

lli lcm(lli a, lli b){
	return b * (a / gcd(a, b));
}

lli gcd(vector<lli> & nums){
	lli ans = 0;
	for(lli & num : nums) ans = gcd(ans, num);
	return ans;
}

lli lcm(vector<lli> & nums){
	lli ans = 1;
	for(lli & num : nums) ans = lcm(ans, num);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lli n,k,t; cin >> n >> k;
	vector<lli> gcds(n);
	for(int i=0; i<n; i++){
		cin >> t;
		gcds[i] = gcd(t,k);
	}

	if(lcm(gcds)%k == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
