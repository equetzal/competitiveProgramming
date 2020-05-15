#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,n,ai;
    cin>>r>>n;
    vector<int> b(r+1,0);
    for(int i =0;i<n;i++){
        cin>>ai;
        b[ai]++;
    }
    if(n ==r)return cout<<"*",0;
    for(int i =1;i<=r;i++)
        if(!b[i])cout<<i<<" ";
    
    return 0;
}