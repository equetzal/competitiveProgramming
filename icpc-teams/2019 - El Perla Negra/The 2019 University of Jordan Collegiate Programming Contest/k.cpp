#include <bits/stdc++.h> 
using namespace std;    
vector<int> a; 
int ORsum() { 
    int zerocnt[32] = {0};   
    for (int i = 0; i < 17; i++)      
        for (int j = 0; j < a.size(); j++)         
            if (!(a[j] & 1 << i)) 
                zerocnt[i] += 1;       
    unsigned long long  ans = 0; 
    for (int i = 0; i < 17; i++)  { 
        ans += ((pow(2, a.size())-1)-(pow(2,zerocnt[i])-1)) * pow(2, i); 
    } 
    return ans; 
} 
  
int main() { 
    int n,ai;
    cin>>n;
    for(int i = 0;i<n;i++){ 
        cin>>ai;
        a.push_back(ai);
    }
    cout<<ORsum(); 
    return 0; 
} 