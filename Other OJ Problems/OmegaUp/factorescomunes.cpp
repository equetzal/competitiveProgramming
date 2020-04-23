//https://omegaup.com/arena/problem/factorescomunes/

#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long int ulli;

set<ulli> primeFactors(ulli n) { 
    map <ulli,ulli> factors;  
    while (n%2 == 0){
        factors[2]++; 
        n = n/2; 
    } 

    for(ulli i = 3; i <= sqrt(n); i = i+2)
        while (n%i == 0){ 
            factors[i]++;
            n = n/i; 
        } 
  
    if (n > 2) 
        factors[n]++;

    vector< pair<ulli,ulli> > v;
    for(auto f:factors)
        v.push_back(f);

    set<ulli> s;
    for(int i=0; i<v.size()-1; i++)
        for(int j=i+1; j<v.size(); j++){
            ulli base1 = v[i].first, base2 = v[j].first;
            for(ulli pot1 = 0; pot1 <= v[i].second; pot1++)
                for(ulli pot2 = 0; pot2 <= v[j].second; pot2++)
                    s.insert(pow(base1,pot1) * pow(base2,pot2));
        }

    if(v.size() == 1)
        s.insert(1);
    return s;
} 

int main(){
    ulli a,b; cin >> a >> b;

    set<ulli> factoresA = primeFactors(a);
    set<ulli> factoresB = primeFactors(b);
    set<ulli> fAB;
    set_intersection(factoresA.begin(), factoresA.end(), factoresB.begin(), factoresB.end(), inserter(fAB,fAB.begin()));

    cout << fAB.size() << endl;
}

