class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = n/3;
        vector<int> res;

        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }

        for(auto& x:mp){
            if(x.second > target){
                res.push_back(x.first);
            }
        }

        return res;
    }
};