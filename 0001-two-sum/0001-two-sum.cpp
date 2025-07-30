class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> m;
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.find(target-nums[i]) != m.end()){
                res.push_back(m[target - nums[i]]);
                res.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};