//https://omegaup.com/arena/problem/Concierto-de-Dr-Lira/

include <iostream>
#include <cstdio>

using namespace std;

int songs, iniv, maxim;
int slist[55], dp[50005][55];

int main(){
    scanf("%d", &songs);
    for(int i=1; i<=songs; i++){
        scanf("%d", &slist[i]);
    }
    scanf("%d%d", &iniv, &maxim);
    dp[iniv][1]=1;
    for(int i=1; i<=songs; i++){
        for(int j=0; j<=maxim; j++){
        	cout << "Si dp["<<j<<"]["<<i<<"]=" << dp[j][i] << "es != 0 y ademas " << j << "-" << slist[i] << " es >= 0"
        		<< "entonces dp["<<j<<"-"<<slist[i]<<"]["<<i+1<<"] sera = 1"<< endl;
            if(dp[j][i] && j-slist[i]>=0)
                dp[j-slist[i]][i+1]=1;
            if(dp[j][i] && j+slist[i]<=maxim)
                dp[j+slist[i]][i+1]=1;
        }
        cout << endl;
    }

    for(int i=0; i<=songs; i++){
    	cout << "for " << i << " song: ";
        for(int j=0; j<=maxim; j++){
        	if(i==0)
        		cout << j << " ";
        	else 
            	cout << dp[j][i] << " ";
        }
        cout << endl;
    }

    for(int j=maxim; j>=0; j--){
        if(dp[j][songs+1]){
            printf("%d\n", j);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
