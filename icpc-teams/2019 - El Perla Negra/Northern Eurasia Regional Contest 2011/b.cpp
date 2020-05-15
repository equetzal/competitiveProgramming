#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
int main(){
    int m,N=0;
    cin>>m;
    int nbits =ceil(log2(m));
    for(int i =0;i<m-1;i++){
        if(pow(2,nbits)-N*2>m-N){
            for(int j =pow(2,nbits-2);j>0;j=j>>1){
                if(i&j)printf("1");
                else printf("0");
            }
            N++;
            printf("\n");
        }
        else break;
    }
    for(int k =N*2,i=N;i<m;i++,k++){ 
        for(int j =pow(2,nbits-1);j>0;j=j>>1){
            if(k&j)printf("1");
            else printf("0");
        }
        printf("\n");
    }
        
        

    return 0;
}