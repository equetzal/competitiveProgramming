//UVaLive 4104 - MODEX

#include <iostream>

using namespace std;

long long moduloShidorriDelReference(long long x, long long y, long long n){
    long long int tempo;

    if(y == 0){
        return 1;
    }

    if(y&1){
        return ((x%n)*(moduloShidorriDelReference(x,y-1,n )))%n;
    }
    else{
        tempo = moduloShidorriDelReference( x, y / 2, n );
        return ( tempo * tempo ) % n;
    }
}

int main(){
    int cases=0;

    while(cin >> cases){
        if(cases == 0)
            break;
        while(cases--){
            int x,y,n;
            cin >> x >> y >> n;
            printf("%lld\n", moduloShidorriDelReference(x,y,n));
        }
    }

    return 0;
}
