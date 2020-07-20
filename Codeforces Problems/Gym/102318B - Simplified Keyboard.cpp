//CF Gym 102318B - Simplified Keyboard
//UCF Locals 2017
//Los Hermanos Computadores de Paine - Coded by Beto

#include <bits/stdc++.h>
using  namespace std;

vector<set<char>> v(27);
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  
int check(string a,string b){
    if( a.size()!= b.size())return 3;
    int sz = a.size();
    int cont = 0;
    bool similar = false;
    for(int i = 0;i<sz;i++){
        if(a[i]== b[i])cont++;
        else if(v[a[i]-'a'].count(b[i])){cont++,similar = true;}
    }
    // cout<<similar<<" "<<cont<<endl;
    if(!similar && cont == sz)return 1;
    if(similar && cont == sz)return 2;
    else return 3;
}
bool check(int i,int j){
    if(i<0)return false;
    if(i>=3)return false;
    if(j<0)return false;
    if(j>=9)return false;
    return true;
}

int main(){
    int n;
    string s,t;
    cin>>n;
    char m[3][9];
    for(int i  = 0;i<9;i++){
        m[0][i] = 'a'+i;
    }
    for(int i = 0;i<9;i++){
        m[1][i]= 'j'+i;
    }
    for(int i = 0;i<8;i++){
        m[2][i]= 's'+i;
    }
    m[2][8] = 'z';
    for(int i = 0;i<3;i++){
        for(int j = 0;j<9;j++){
            int nx = i,ny = j;
            for(int k = 0;k<8;k++){
                nx = i+fx[k];
                ny = j+fy[k];
                if(check(nx,ny)){
                   v[(i*9)+j].insert(m[nx][ny]);
                }
            }
        }
    }

    for(int i = 0;i<n;i++){
        cin>>s>>t;
        cout<<check(s,t)<<endl;
    }
    return 0;
}
