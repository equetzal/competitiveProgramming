#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cont0= 0,cont1 = 0;
    for(int i = 0;i<s.size();i++){
        if(s[i]== '0')cont0++;
        else cont1++;
    }
    if(cont0>cont1){
        for(int i = 0;i<s.size();i++)
            cout<<"1";
    }
    else if(cont1>cont0){
        for(int i = 0;i<s.size();i++)
            cout<<"0";
    }
    else{
        if(s[0]== '1'){
            cout<<"0";
            for(int i = 0;i<s.size()-1;i++)
                cout<<"1";
        }
        else {
            cout<<"1";
            for(int i = 0;i<s.size()-1;i++)
                cout<<"0";
        }
    
    }
    cout<<endl;
    return 0;
}