#include <bits/stdc++.h>
using namespace std;
vector<int> su(1000000);
void puts(string s,int i, char p){
    for(i;i<s.size();i++){
        if(s[i]== ')'&& s[i+1]==')')return ;
        if(s[i]<='9'&& s[i]>='0' && su[s[i]-'0'] == 0)
            su[s[i]-'0']=p-'0';
        if(s[i] =='(' && s[i-1]<='9'&& s[i-1]>='0')
            puts(s,i+1,s[i-1]);
    }
}
int main(){
    int n;
    string s;
    cin>>n>>s;
    puts(s,2,s[0]);
    for(int i = 1;i<=n;i++)
        cout<<su[i]<<" ";
    cout<<endl;

    return 0;
}