//CF Gym 101889C - Complete Naebbirac's Sequence

#include <bits/stdc++.h>
using namespace std;

int b[1000];
int main(){
    int k,n,ai,mn = 10000,mx = -1,index1,index2;
    cin>>k>>n;
    for(int i = 0;i<n;i++){
        cin>>ai;
        b[ai]++;
    }   
    int sum;
    for(int i = 1;i<=k;i++){
        sum+=b[i];
        if(b[i]<mn){mn = b[i];index1 = i;}
        if(b[i]>mx){mx = b[i];index2 = i;}
    }
    int f = round(float(n)/k);
    if(mx-mn>2)cout<<"*"<<endl;
    else if(mx-mn == 2)cout<<"-"<<index2<<" +"<<index1<<endl;
    else if(mx-mn == 1){
        if(mx>f)
            cout<<"-"<<index2<<endl;
        else if(mn<f)
            cout<<"+"<<index1<<endl;
    }
    return 0;
}   
