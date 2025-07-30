class Solution {
public:
    bool check(vector<int> nums, int k){
        if(nums.size() == 1) return false;
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1]) <=k) return true;
        }
        return false;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        bool res = false;

        for(auto& x:mp){
            res = check(x.second,k);
            if(res == true) return true;
        }
        return res;

    }
};