//LC 1243 - Array Transformation

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        bool changes;
        vector<int> piv = arr, ans = arr;
        
        do{
            changes = false;
            for(int i=1; i<(piv.size()-1); i++){
                if(piv[i] < piv[i-1] && piv[i] < piv[i+1]){
                    changes = true;
                    ans[i] = piv[i]+1;
                    continue;
                }
                if(piv[i] > piv[i-1] && piv[i] > piv[i+1]){
                    changes = true;
                    ans[i] = piv[i]-1;
                    continue;
                }
                ans[i] = piv[i];
            }
            piv = ans;
        }while(changes);
        
        return ans;
    }
};
