#include <bits/Stdc++.h>
using namespace std;
int main(){
    long long k;
    string s;
    cin>>k>>s;
    int nn =s.size();
    long long n = 0;
    for(int i = 0;i<s.size();i++)
        if(s[i]=='1')n += pow(2,(s.size()-1)-i);

    if(n<=k)return cout<<0<<endl,0;
    int cont = 0;
    bool flag = true;
    int i = 1;
    while(flag){
        if(i == nn-1){
            while(n>k){
                
                n>>=1;
                cont++;
            }
            return cout<<cont<<endl,0;
        }
        if(s[i]=='1'){
            cont++;
            s.erase(s.begin()+i);
            n = 0;
            for(int j = 0;j<s.size();j++)
                if(s[j]=='1')n += pow(2,(s.size()-1)-j);
            if(n<=k)flag = false;
        }
        else i++;
    }
    cout<<cont<<endl;
    return 0;
}