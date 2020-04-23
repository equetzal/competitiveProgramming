//CF Gym 100753I - Milling machines

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int X,Y,W,S,a,b,c,xd;
    cin>>W>>S;
    cin>>X>>Y;
    int P[X][W];
    int C[X]={0};
    
    for(int i=0; i<W;i++){
        for(int z=0;z<X;z++){
            cin>>a;
            P[z][i]=a;        
        }       
            
    }
    for(int j=0; j<S;j++){
        for(int z=0;z<X;z++){
            cin>>a;
            C[z]=max(C[z],a);        
        } 
    }
    for(int i=0;i<W;i++){
            for(int j=0; j<X;j++){
                xd= Y-P[j][i];
                if(C[j]>xd)                
                    P[j][i]=P[j][i]-C[j]+xd;

            }
    }
    for(int i=0; i<W;i++){
        cout<<P[0][i];
        for(int z=1;z<X;z++){
            cout<<" "<<P[z][i];
        }       
        cout<<"\n";
    }
    return 0;
}
