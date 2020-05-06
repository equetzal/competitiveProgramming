#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	unsigned long long n;
	cin>>n;
	int nbits = 0;
	for(int i = 63;i>=0;i--)
		if(n& 1ll<<i)nbits++;
	unsigned long long ans;
	ans = 1ll<<nbits;
	cout<<ans<<"\n";
	return 0;
}

