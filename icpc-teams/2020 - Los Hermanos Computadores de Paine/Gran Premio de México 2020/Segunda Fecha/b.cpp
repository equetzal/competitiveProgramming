#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,D,L,R,C;
    while(t--){
        cin>>n;
        vector<vector<int>> grid(10,vector<int>(10,0));
        bool flag = true;
        for(int i = 0;i<n;i++){
            cin>>D>>L>>R>>C;
            R--,C--;
            if(D == 0){
                if(C+(L-1)>=10){flag = false;continue;}
                for(int i= C;i<C+L;i++)
                    if(grid[R][i] == 1)flag = false;
                    else grid[R][i] = 1;
            }
            else {
                if(R+(L-1)>=10){flag = false;continue;}
                for(int i= R;i<R+L;i++)
                    if(grid[i][C] == 1)flag = false;
                    else grid[i][C] = 1;
            }
        }
        // for(int i = 0;i<10;i++)
            // for(int j = 0;j<10;j++)
                // cout<<grid[i][j]<<" \n"[j==9]; 
        if(flag)cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}  

