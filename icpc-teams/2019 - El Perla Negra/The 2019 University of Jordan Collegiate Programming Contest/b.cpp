#include <bits/stdc++.h>
using namespace std;
const int N = 10000000;
int lp[N+1];
vector<int> pr;
void criba(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
int findPrimes(int n) { 
    for (int i=0 ; pr[i] <= n/2; i++) { 
        int diff = n - pr[i]; 
        if (binary_search(pr.begin(), pr.end(), diff)){ 
            // Express as a sum of primes 
            cout << pr[i]<<" "<<diff<<endl; 
            return 1; 
        } 
    }
    return 0; 
} 
int main(){
	int n,i,j;
	criba();
    cin>>n;
    if(!findPrimes(n))cout<<-1<<endl;
}