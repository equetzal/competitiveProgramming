//AtCoder 4164 - Multiple of 2 and N

#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b){
    return (b==0 ? a: gcd(b,a%b));
}

long long lcm(long long a, long long b){
    return a / gcd(a,b) *b ;
}

int main(){
    long long n;
    cin >> n;
    
    cout << lcm(2,n);
    
    return 0;
}
