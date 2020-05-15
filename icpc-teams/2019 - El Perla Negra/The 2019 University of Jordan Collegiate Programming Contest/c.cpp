#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,x,count = 0;
    cin>>s>>x;
    while(s){
        s/=x;
        count++;
    }
    cout<<count<<endl;
    return 0;
}