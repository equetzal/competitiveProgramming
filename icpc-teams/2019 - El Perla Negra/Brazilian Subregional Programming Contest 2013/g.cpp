#include <bits/stdc++.h>
using namespace std;
int grid[309][309];
int l,c;
bool verify(){
    for (int i=0;i<l;i++){
        for (int j=0;j<c;j++){
            if (grid[i][j]!=i*c+j)return false;
        }
    }
    return true;
}

void shiftCol(int c1,int c2){
    for (int i=0;i<l;i++){
        grid[i][c1]^=grid[i][c2];
        grid[i][c2]^=grid[i][c1];
        grid[i][c1]^=grid[i][c2];
    }
}

void shiftLin(int l1,int l2){
    for (int j=0;j<c;j++){
        grid[l1][j]^= grid[l2][j];
        grid[l2][j]^= grid[l1][j];
        grid[l1][j]^= grid[l2][j];
    }
}

int main(){
    int posx,posy,ans;
    cin>>l>>c;
        ans = 0;
        for (int i=0;i<l;i++){
            for (int j=0;j<c;j++){
                cin>>grid[i][j];
                grid[i][j]--;
                if (grid[i][j]==0)posx = i, posy = j;
            }
        }
        if (posx!=0){shiftLin(0,posx);ans++;}
        if (posy!=0){shiftCol(0,posy);ans++;}
        for (int i=1;i<c;i++){
            for (int j=i;j<c;j++){
                if (grid[0][j]==i){
                    if (j!=i){shiftCol(i,j);ans++;}
                    break;
                }
            }
        }
        for (int i=1;i<l;i++){
            for (int j=i;j<l;j++){
                if (grid[j][0]==c*i){
                    if (j!=i){shiftLin(i,j);ans++;}
                    break;
                }
            }
        }
        if (verify())cout<<ans<<endl;
        else cout<<"*"<<endl;
}