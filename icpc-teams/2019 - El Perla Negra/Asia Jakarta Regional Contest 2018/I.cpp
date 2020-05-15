#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    vector<bool>d(n);
    for(int i = 0;i<n;i++){
        cin>>s;
        if(s == "TRUTH")d[i] = true;
        else d[i] = false;
    }
    for(int i = n-2;i>=0;i--){
        if(d[i+1] == false)d[i] = !d[i];
    }

    if(d[0])cout<<"TRUTH";
    else cout<<"LIE";
    return 0;
}