//Timus 1017 - Staircases

#include <iostream>
#include <cstdio>
#include <cstring>

#define max 510

using namespace std;

long long int depe[max][max];

long long int dp(int x, int y){
    if(x==0) 
        return 1;
    if(y==0) 
        return 0;
    
    long long int &res = depe[x][y];
    
    if(res == -1){
        if(x >= y){
            res = dp(x-y,y-1) + dp(x,y-1);
        }else{
            res = dp(x,y-1);
        }
    }

    return res;
}

int main(){
    int N;
    scanf("%d", &N);
    
    memset(depe,-1,sizeof(depe));
    printf("%lld\n", dp(N,N-1));

    return 0;
}
