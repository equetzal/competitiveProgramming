#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c,lines= 0,points=0;
    cin>>r>>c;
    char matrix[r][c];
    for(int i =0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]=='/'||matrix[i][j]=='\\') lines ++;
        }
    }
    for(int i =0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(matrix[i][j]=='.'){
                int limits=0;
                for(int k =i;k>=0;k--)if(matrix[k][j]=='/'|| matrix[k][j]=='\\'){ limits ++;break;}
                for(int k =i;k<r;k++)if(matrix[k][j]=='/'||matrix[k][j]=='\\') {limits ++;break;}
                for(int k =j;k>=0;k--)if(matrix[i][k]=='/'||matrix[i][k]=='\\') {limits ++;break;}
                for(int k =j;k<c;k++)if(matrix[i][k]=='/'||matrix[i][k]=='\\') {limits ++;break;}
                if(limits == 4)points++;
            }
        }
    }
    cout<<(lines/2)+points;
    return 0;
}