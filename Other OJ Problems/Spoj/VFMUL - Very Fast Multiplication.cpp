//SPOJ VFMUL - Very Fast Multiplication

#include <iostream>
#include <complex>
#include <vector>

using namespace std;
typedef long double Double;
typedef complex < Double > complejo;
const int MAXN = 2000000;
int rev[ MAXN ];
complejo wlen_pw[ MAXN ];
 
void fft ( vector<complejo>& a, int n, bool invert ) {
	for ( int i = 0 ; i < n ; ++ i )
		if ( i < rev [ i ] )
			swap ( a [ i ] , a [ rev [ i ] ] ) ;
 
	for ( int len = 2 ; len <= n ; len <<= 1 ) {
		Double ang = 2 * M_PI / len * ( invert ? - 1 : + 1 ) ;
		int len2 = len >> 1 ;
 
		complejo wlen ( cos ( ang ) , sin ( ang ) ) ;
		wlen_pw [ 0 ] = complejo ( 1 , 0 ) ;
		for ( int i = 1 ; i < len2 ; ++ i )
			wlen_pw [ i ] = wlen_pw [ i - 1 ] * wlen;
		
		complejo t; int r, l;
		for ( int i = 0 ; i < n ; i += len ) {
			for ( int j = 0; j < len/2; j++ ) {
				r = i+j+len/2; l = i+j;
				t = a[r] * wlen_pw[j];
				a[r] = a[l] - t;
				a[l] += t ;
			}
		}
	}
	if ( invert )
		for ( int i = 0 ; i < n ; ++i )
			a [ i ] /= n ;
}
 
void calc_rev ( int n, int log_n ) {
	for ( int i = 0 ; i < n ; ++ i ) {
		rev [ i ] = 0 ;
		for ( int j = 0 ; j < log_n ; ++ j )
			if ( i & ( 1 << j ) )
				rev [ i ] |= 1 << ( log_n - 1 - j ) ;
	}
}

void Multiplica( vector<complejo>& A, vector<complejo>& B ){
	fft( A, A.size(), false);
	fft( B, B.size(), false );
	for( int i = 0; i < A.size(); i++ )
		A[i] *= B[i];
	fft(A, A.size(), true);
}

int main(){
	int N;
	cin>>N;
	while(N--){
		string x,y;
		cin>>x>>y;
		if(x=="0" || y=="0"){
			cout<<"0\n";
		}else{
			vector<complejo> A, B;
			A.clear();
			B.clear();
			for(int i=x.size()-1; i>=0;i--){
				A.push_back(complejo(x[i]-48,0));
			}
			for(int i=y.size()-1; i>=0;i--){
				B.push_back(complejo(y[i]-48,0));
			}
			int len = max( A.size(), B.size() );

			int n = 1, logn = 0;
			while( n < len ) n <<=1, logn++;
			n <<= 1, logn++;
			vector<int> res( n );
			A.resize(n);
			B.resize(n);
			calc_rev(n, logn);
			Multiplica(A,B);
			
			for(int i=0; i<A.size();i++){
					int num=(int)round(real(A[i]));
					if( num> 9){					
						A[i]=complejo(real(num%10),0);
						A[i+1]=complejo(real(A[i+1])+num/10,0);
					}
			}
			bool si=false;
			for(int i=A.size()-1; i>=0;i--){
				 if((int)round(real(A[i]))>0 || si){
					si=true;
					cout<<(int)round(real(A[i]));
				 }			
				
			}
			cout<<endl;
			
		}
		
	}
	return 0;
}
