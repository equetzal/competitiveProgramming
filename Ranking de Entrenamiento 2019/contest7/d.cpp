//CF Gym 101915H - Buying Products

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector< pair<int,int> > prices;
        for(int i=0; i<n; i++){
            int p1,p2,p3; cin >> p1 >> p2 >> p3;
            prices.push_back(make_pair(p1,i));
            prices.push_back(make_pair(p2,i));
            prices.push_back(make_pair(p3,i));
        }
        
        sort(prices.begin(), prices.end());
        map<int,int> used;
        long long int total = 0;
        for(int i=0; i<prices.size(); i++){
            if(k == 0)
                break;
            if(used[prices[i].second] < 2){
                used[prices[i].second]++;
                total += prices[i].first;
                k--;
            }            
        }
        
        cout << total << endl;
        
    }
    
    return 0;
}
