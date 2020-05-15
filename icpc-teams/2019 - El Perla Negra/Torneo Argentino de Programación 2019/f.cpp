#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
typedef long long int lli;
const int mod = 1000000007;
lli mod_pow(lli a,lli b){
	lli ans = 1;
	while(b){
		if(b&1)ans = (ans*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	char grid[n][m];
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			cin>>grid[i][j];
	
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(i-1>0 && grid[i][j]!= '-' && grid[i-1][j] == grid[i][j])return cout<<0,0;
			if(i+1<n && grid[i][j]!= '-' && grid[i+1][j] == grid[i][j])return cout<<0,0;
			if(j-1>0 && grid[i][j]!= '-' && grid[i][j-1] == grid[i][j])return cout<<0,0;
			if(j+1<m && grid[i][j]!= '-' && grid[i][j+1] == grid[i][j])return cout<<0,0;
		}
	}
	vector<int>cont(4,0);
	int first =1;
	if(grid[0][0]=='-')first = k;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(grid[i][j] == '-'){
				int cuantos = 0;
				if(j == 0){
					if(i-1>0 && grid[i-1][j]!= '-' )cuantos++;
					if(i+1<n && grid[i+1][j]!= '-' )cuantos++;
					if(j-1>0 && grid[i][j-1]!= '-' )cuantos++;
					if(j+1<m && grid[i][j+1]!= '-' )cuantos++;
					if(k-cuantos<=0)return cout<<0,0;
					if(i == 0)
						cont[(3-cuantos)+1]++;
					else 
						cont[3-(cuantos+1)]++;

				}
				else{
					if(i-1>0 && grid[i-1][j]!= '-' )cuantos++;
					if(i+1<n && grid[i+1][j]!= '-' )cuantos++;
					if(j-1>0 && grid[i][j-1]!= '-' )cuantos++;
					if(j+1<m && grid[i][j+1]!= '-' )cuantos++;
					if(k-cuantos<=0)return cout<<0,0;
					if(i == 0)
						cont[(3-cuantos)+1]++;
					else 
						cont[3-(cuantos+1)]++;
				} 
			}
		}	
	}
	for(auto c: cont)cout<<c<<" ";
		cout<<endl;
	cout<<first<<endl;
    if(k-2<=0)return cout<<0,0;
    lli ans = 1;
    for(int i = 0;i<4;i++)
    	ans =(ans*mod_pow((k-(4-i)),cont[i]))%mod;
    ans = (ans*first)%mod;
	cout<<ans<<endl;
}