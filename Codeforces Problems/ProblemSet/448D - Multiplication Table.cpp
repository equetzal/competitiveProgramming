//CF ProblemSet 448D - Multiplication Table

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll ;
typedef pair<int,int> ii ;

#define _CRT_SECURE_NO_WARNINGS
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i=(a) ; (i)<(b) ; ++i)
#define inf 2000000000
#define endl "\n"
#define max(a,b) ( (a>b) ? (a) : (b) )
#define min(a,b) ( (a<b) ? (a) : (b) )

int ri() {
	char c = getchar(); 

	while(c<'0' || c>'9') 
		c=getchar(); 
	int ret = 0; 

	while(c>='0' && c<='9') { 
		ret=10*ret+c-48; 
		c=getchar(); 
	} 
	return ret; 
}

ll n,m,k ;

int main() {
	cin >> n >> m >> k;
	ll R=n*m ;
	ll L=1 ;

	while(L<=R){ 
		ll mid = (L+R) >> 1;
		ll cnt = 0 ;
		
		rep(i,1,m+1){
			cnt += ( n < (mid/i)) ? n : (mid/i) ;
		}
		
		if(cnt<k)
			L=mid+1 ;
		else
			R=mid-1 ;
	}
	
	cout << L << endl;

	return 0;
}
