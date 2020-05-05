//HR mini-max-sum - Mini-Max Sum

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    long int a[5], min=0, max=0, sum;
    scanf("%ld %ld %ld %ld %ld",&a[0],&a[1],&a[2],&a[3],&a[4]);
    
    for(int i=0; i<sizeof(a)/sizeof(long); i++)
        min += a[i];
    
    for(int i=0; i<sizeof(a)/sizeof(long); i++){
        sum = 0;
        for(int j=0; j<sizeof(a)/sizeof(long); j++){
            if(i != j)
                sum += a[j];
        }
        printf("\n");


        if(sum > max)
            max = sum;
        if(sum < min)
            min = sum;
    }
    
    printf("%ld %ld", min, max);
    
    return 0;
}
