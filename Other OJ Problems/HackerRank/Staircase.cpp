//HR staircase - Staircase

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n, space, hash; 
    scanf("%d",&n);
    
    space = n - 1;
    hash = 1;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<space; j++)
            printf(" ");
        space--;
        for(int j=0; j<hash; j++)
            printf("#");
        hash++;
        printf("\n");
    }
    return 0;
}
