//https://codeforces.com/group/YjFmW2O15Q/contest/101919
//TAP2018 - Descenso

#include<bits/stdc++.h>

using namespace std;
typedef double Double;
const Double ERROR = 1e-9;
#define EQ(a,b) (fabs((a)-(b)) < ERROR)

int main(){
	int N =0, M= 0;
	cin>>N>>M;
	Double X = (((N*(N-1.0))/2.0) - ((M*(M-1.0))/2.0)) / (N-M);

	printf( "%.1lf\n",X);
}
