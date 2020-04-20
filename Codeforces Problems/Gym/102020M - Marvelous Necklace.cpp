//CF Gym 102020M - Marvelous Necklace

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string collar; cin >> collar;
    
    int a=0,b=0;
    for(auto c:collar){
        if(c == 'A')
            a++;
        else
            b++;
    }
        
    if(a&1 || b&1){
        cout << "NO" << endl;
        return 0;
    }
        
    int tam = collar.size()/2;
    int m1_a=0, m1_b=0, m2_a=0, m2_b=0;
    for(int i=0; i<tam; i++){
        if(collar[i] == 'A')
            m1_a++;
        else
            m1_b++;
    }
    m2_a = a-m1_a;
    m2_b = b-m1_b;
    
    int ini = -1, fin = -1;
    bool areSol = false;
    for(int i=0; i<collar.size(); i++){
        if(m1_a == m2_a && m1_b == m2_b){
            areSol = true;
            ini = min(i,(tam+i)%((int)collar.size()));
            fin = max(i,(tam+i)%((int)collar.size()));
            break;
        }
        
        if(collar[i] == 'A')
            m1_a--;
        else
            m1_b--;
        
        if(collar[(tam+i)%collar.size()] == 'A')
            m1_a++;
        else
            m1_b++;
        
        m2_a = a-m1_a;
        m2_b = b-m1_b;
    }
    
    if(areSol){
        cout << "YES" << endl;
        cout << ini+1 << " " << fin+1 << endl;
    }else{
        cout << "NO" << endl;   
    }
    
    return 0;
}
