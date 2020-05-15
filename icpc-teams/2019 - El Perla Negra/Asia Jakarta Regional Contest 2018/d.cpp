#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    char board[r][c];
    for(int i = 0;i<r;i++)
        for(int j = 0;j<c;j++)
            cin>>board[i][j];
    int continside = 0;
    if(r ==2){
        for(int j = 1;j<c-1;j++)
            if(board[0][j]=='.' && board[1][j] == '.')continside++;
    }
    else if(c ==2 ){
        for(int j = 1;j<r-1;j++)
            if(board[j][0]=='.' && board[j][1] == '.')continside++;
    }
    else if(r == 1){
        for(int j = 1;j<c-1;j++)
            if(board[0][j]=='.')continside++;
    }
    else if(c == 1){
        for(int j = 1;j<r-1;j++)
            if(board[j][0]=='.')continside++;
    }
    else if(r>2 && c>2){
        bool sup,inf,izq,der;
        sup = inf = izq = der = true;
        for(int i = 1;i<c-1;i++)if(board[0][i] == '#')sup = false;
        for(int i = 1;i<c-1;i++)if(board[r-1][i] == '#')inf = false;
        for(int i = 1;i<r-1;i++)if(board[i][0] == '#')izq = false;
        for(int i = 1;i<r-1;i++)if(board[i][c-1] == '#')der = false;
        if(sup&&inf&&der&&izq)continside++;
        for(int i = 1;i<r-1;i++)
            for(int j = 1;j<c-1;j++)
                if(board[i][j]=='.')continside++;
    }
    cout<<continside<<endl;
    return 0;
}