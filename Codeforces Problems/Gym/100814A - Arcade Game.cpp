//CF Gym 100814A - Arcade Game
//Cuarentena de Entrenamiento 2020 - Club de Algoritmia ESCOM
//ECPC 2015
//Los Hermanos Computadores de Paine

#include <bits/stdc++.h>
using namespace std;
double pow(double a,int b){
    double x = 1;
    while(b){
        if(b&1)x = a*x;
        a*=a;
        b>>=1;
    }
    return x;
}

int fact(int n){ 
    return (n<=1)?1:n*fact(n-1); 
} 
void cnt(int * count,string s) { 
    for (int i = 0; s[i]; ++i) 
        ++count[s[i]]; 
    for (int i = 1; i < 256; ++i) 
        count[i] += count[i - 1]; 
} 
void update(int * count,char s){ 
    int i; 
    for (i = s; i < 256; ++i) 
        --count[i]; 
} 
int findRank(string s) { 
    int n = s.size(); 
    int mul = fact(n); 
    int position = 1, i; 
    int count[256] = {0};
    cnt(count,s); 
    for (i = 0; i < n; ++i) { 
        mul /= n - i; 
        position += count[s[i] - 1] * mul; 
        update(count,s[i]); 
    } 
    return position; 
} 

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.size()==1)cout<<"0.000000000"<<endl;
        else {
            int n = stoi(s);
            int total = fact(s.size());
            int index = findRank(s);
            int c= total-index;
            if(c == 0)cout<<"0.000000000"<<endl;
            else {

                double p = 1.0/total;
                double aux = 1.0/total;
                double ans = p;
                for(int i = 1;i<c;i++){
                    ans  = p+p*aux;
                    p = ans;
                }
                
                cout<<fixed<<setprecision(9);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
