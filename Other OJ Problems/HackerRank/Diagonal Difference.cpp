//HR diagonal-difference - Diagonal Difference

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

int main(){
    int n; 
    scanf("%d",&n);
    int a[n][n], sum=0;

    for(int i = 0; i < n; i++){
       for(int j = 0; j < n; j++){
          scanf("%d",&a[i][j]);
       }
    }
    
    for(int i=0; i<n; i++){
        sum += a[i][i];
    }
    
    for(int i=n-1, j=0; i>=0; i--, j++){
        sum -= a[i][j];
    }
    
    if(sum < 0 )
    	sum = sum*-1; 
    
    printf("\n \n %d", sum);
    
    return 0;
}
