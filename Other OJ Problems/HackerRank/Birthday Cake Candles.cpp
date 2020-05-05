//HR birthday-cake-candles - Birthday Cake Candles

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    
    int n,tall=0, num=0; 
    scanf("%d",&n);
    int *height = (int*)malloc(sizeof(int) * n);
    int *j;
    
    for(int i = 0; i < n; i++, height++){
       scanf("%d",height);

       if(*height > tall){
            tall = *height;
            num = 1;
        }
        else if(*height == tall)
            num++;
    }
    
    printf("%d", num);
    
    return 0;
}
