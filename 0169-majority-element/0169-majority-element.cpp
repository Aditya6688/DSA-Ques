class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        int target = n/2;
        int res = -1;
        for(const auto& s:mp){
            if(s.second>target) res = s.first;
        }
        return res;
    }
};