//LC 347 - Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frec;
        vector<vector<int>> frecNum(nums.size()+1);
        
        for(auto i:nums){
            frec[i]++;
        }
        
        for(auto p:frec){
            frecNum[p.second].push_back(p.first);
        }
        
        vector<int> ans;
        for(int i=frecNum.size()-1; i>=0 && k>0; i--){
            for(auto n:frecNum[i]){
                ans.push_back(n);
                k--;
            }
        }
        
        return ans;
    }
};
