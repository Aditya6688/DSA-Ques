class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int res = 0;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int target = n/2;

        for(auto m:mp){
            if(m.second > target)
            res = m.first;
        }

        return res;
    }
};