#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
char grid[41][41];
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  
set<int> st[40*40];
int n,m;
bool valid(int i,int j){
    if(i<0 ||j<0)return false;
    if(i>=n || j>=m)return false;
    return true;
}
void find(string s,int idx){
    vector<int> b1(26);
    for(int i = 0;i<s.size();i++)
        b1[s[i]-'A']++;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            for(int k = 0;k<8;k++){
                vector<int> b(26,0);
                int x = i,y = j;
                for(int z = 0;z<s.size();z++){
                    b[grid[x][y]-'A']++;
                    x+=fx[k];
                    y+=fy[k];
                    if(!valid(x,y))break;
                }
                if(b == b1){
                    int x = i,y = j;
                    for(int z = 0;z<s.size();z++){
                        st[(x*m)+y].insert(idx);
                        x+=fx[k];
                        y+=fy[k];
                    }
                }
            }
        }
    }
}
int main(){__
    int k;
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>grid[i][j];
    cin>>k;
    string s;
    for(int i = 0;i<k;i++){
        cin>>s;
        find(s,i);
    }
    int cont = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            // cout<<st[(i*m)+j].size()<<" ";
            if(st[(i*m)+j].size()>1)cont++;
        }
        // cout<<endl;
    }
    cout<<cont<<endl;
    return 0;
}  

