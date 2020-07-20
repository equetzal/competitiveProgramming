//Kattis Open alphabetanimals - Alphabet Animals
//NCPC 2019
//Los Hermanos Computadores de Paine - Coded by Beto

#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define endl "\n"

int main(){ 
    int n;
    string t;
    cin>>t;
    cin>>n;
    vector<string>s(n);
    vector<int> bk(27);
    vector<int> bk2(27);
    vector<string> possible;
    for(int i = 0;i<n;i++){
        cin>>s[i];
        bk[s[i][0]-'a']++;
        if(s[i][0] == t.back())possible.push_back(s[i]);
    }

    if(possible.size()== 0)return cout<<"?"<<endl,0;
    bool flag = false;
    string ans;
    for(auto c:possible){
        if(c.back()== c[0]){
            if(bk[c.back()-'a']-1 <=0){
                ans = c;
                flag = true;
                break;
            }
        }
        else if(bk[c.back()-'a'] == 0) {
                ans = c;
                flag = true;
                break;
        }
    }
    if(flag)return cout<<ans<<"!"<<endl,0;
    else cout<<possible[0]<<endl;
    return 0;

}
