#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main(){
    long double v,s;
    cin>>v>>s;
    cout<<fixed;
    cout<<setprecision(9);
    long double r = (s/2)/sin(PI*((360/v)/2)/180);
    cout<<PI*r*r<<endl;
    return 0;
}