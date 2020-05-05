//HR plus-minus - Plus Minus

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n, Cz=0, Cp=0, Cm=0; 
    scanf("%d",&n);
    int arr[n];
    float resz,resp, resm;
    
    for(int i = 0; i < n; i++){
       scanf("%d",&arr[i]);
    }
    
    for(int i=0; i < n; i++){
        if(arr[i] == 0)
            Cz++;
        else
            if(arr[i] > 0)
                Cp++;
            else
                Cm++;
    }
    
    resz = (float)Cz / (float)n;
    resp = (float)Cp / (float)n;
    resm = (float)Cm / (float)n;
    
    printf("%f \n", resp);
    printf("%f \n", resm);
    printf("%f \n", resz);
    
     
    return 0;
}
