//LC 1 - Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> val;
        for(int i=0; i<nums.size(); i++)
            val[nums[i]].push_back(i);
        
        set<int> complement;
        for(int i=0; i<nums.size(); i++){
            if(complement.count(nums[i]) > 0){
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(val[target-nums[i]][0]);
                return ans;
            }else{
                complement.insert(target-nums[i]);
            }
        }
        
        vector<int> res;
        return res;
    }
};
